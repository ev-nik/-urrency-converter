//----------------------------------
#include <QDebug>
//----------------------------------
#include "Widget.h"
#include "ui_Widget.h"
//----------------------------------

#define USSD "ussd"
#define EURO "euro"
#define CNY  "cny"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)

{
    saveMoney[USSD] = "75.12";
    saveMoney[EURO] = "85.55";
    saveMoney[CNY]  = "11";

    ui->setupUi(this);

    setWindowTitle("Конвертер валют"); // Меняем заголовок окна

    ui->info->clear();                 // Убралb лишний текст

    ui->inputRub->setFocus();          // Ставим фокус на ввод рублей

    ui->inputRub->setPlaceholderText("Рубль");
    ui->course  ->setPlaceholderText("Курс валюты");
    ui->outputUE->setPlaceholderText("Сумма");

    connect(ui->inputRub   , SIGNAL(textChanged(QString)), this, SLOT(recalc()));
    connect(ui->course     , SIGNAL(textChanged(QString)), this, SLOT(recalc()));
    connect(ui->ussdRButton, SIGNAL(clicked(bool))       , this, SLOT(changeCourseUSSD()));
    connect(ui->euroRButton, SIGNAL(clicked(bool))       , this, SLOT(changeCourseEuro()));
    connect(ui->cnyRButton , SIGNAL(clicked(bool))       , this, SLOT(changeCourseCNY()));
    connect(ui->course     , SIGNAL(textChanged(QString)), this, SLOT(saveCourse()));

    ui->ussdRButton->click(); // Выбран радиобаттон по умолчанию
}
//------------------------------------------------------------------------------------

Widget::~Widget()
{
    delete ui;
}
//------------------------------------------------------------------------------------

void Widget::changeCourseUSSD()
{

    ui->course->setText(saveMoney[USSD]);
    qDebug() << "lkffnb;onfb;nbonbrbnrb";
}
//------------------------------------------------------------------------------------

void Widget::changeCourseEuro()
{
    ui->course->setText(saveMoney[EURO]);
}
//------------------------------------------------------------------------------------

void Widget::changeCourseCNY()
{
    ui->course->setText(saveMoney[CNY]);
}
//------------------------------------------------------------------------------------

void Widget::saveCourse()
{
    if(ui->saveBox->checkState() == false)
    {
        return;
    }

    if(ui->ussdRButton->isChecked())
    {
        saveMoney[USSD] = ui->course->text();
    }
    else if(ui->euroRButton->isChecked())
    {
        saveMoney[EURO] = ui->course->text();
    }
    else if(ui->cnyRButton->isChecked())
    {
        saveMoney[CNY] = ui->course->text();
    }

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
