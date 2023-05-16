#include "Widget.h"
#include "ui_Widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)

{
    ui->setupUi(this);

    setWindowTitle("Конвертер валют"); // Меняем заголовок окна

    ui->info->clear(); // Убрал лишний текст

    ui->inputRub->setFocus(); // Ставим фокус на ввод рублей

    connect(ui->inputRub, SIGNAL(textChanged(QString)), this, SLOT(recalc()));
    connect(ui->courseDollar, SIGNAL(textChanged(QString)), this, SLOT(recalc()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::recalc()
{

    bool ok = false;
    QString course = ui->courseDollar->text();
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
