//----------------------------------
#include <QDebug>
//----------------------------------
#include "Widget.h"
#include "ui_Widget.h"
//----------------------------------

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)

{
    ui->setupUi(this);

    setWindowTitle("Конвертер валют"); // Меняем заголовок окна

    ui->info->clear();                 // Убралb лишний текст

    ui->inputRub->setFocus();          // Ставим фокус на ввод рублей

    ui->inputRub->setPlaceholderText("Рубль");
    ui->course  ->setPlaceholderText("Доллар");
    ui->outputUE->setPlaceholderText("Сумма");

    connect(ui->inputRub   , SIGNAL(textChanged(QString)), this, SLOT(recalc()));
    connect(ui->course     , SIGNAL(textChanged(QString)), this, SLOT(recalc()));
    connect(ui->ussdRButton, SIGNAL(clicked(bool))       , this, SLOT(changeCourseUSSD()));
    connect(ui->euroRButton, SIGNAL(clicked(bool))       , this, SLOT(changeCourseEuro()));
    connect(ui->cnyRButton , SIGNAL(clicked(bool))       , this, SLOT(changeCourseCNY()));
}
//------------------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//------------------------------------------------------------------------------------

void Widget::changeCourseUSSD()
{
    ui->course->setText("75.55");
}
//------------------------------------------------------------------------------------

void Widget::changeCourseEuro()
{
    ui->course->setText("85.12");
}
//------------------------------------------------------------------------------------

void Widget::changeCourseCNY()
{
    ui->course->setText("11");
}

//------------------------------------------------------------------------------------
void Widget::recalc()
{
    bool ok = false;
    QString course = ui->course->text();
    double translateDol = course.toDouble(&ok);

    if(translateDol > 0 && ok == true)
    {
        ui->info->setText("ok");
    }
    else
    {
        ui->info->setText("некорректный ввод");
        ui->outputUE->clear();
        return;
    }

    QString inputRub = ui->inputRub->text();
    double translateRub = inputRub.toDouble(&ok); // Перевод string в double
                                                  // С помощью метода toDouble(&ok)
                                                  // мы переводим string в double
                                                  // а с помощью &ok мы можем контролировать
                                                  // произошла конвертация или нет.
    if(ok == true)
    {
        ui->info->setText("ok");
    }
    else
    {
        ui->info->setText("некорректный ввод");
        ui->outputUE->clear();
        return;
    }

    double operate = translateRub / translateDol;

    QString endUE = QString::number(operate);

    ui->outputUE->setText(endUE);
}
//------------------------------------------------------------------------------------
