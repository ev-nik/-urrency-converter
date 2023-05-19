//----------------------------------
#ifndef WIDGET_H
#define WIDGET_H
//----------------------------------
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
//----------------------------------

namespace Ui { class Widget; }
//----------------------------------

class Widget : public QWidget
{
    Q_OBJECT


public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private:
    Ui::Widget *ui;

    QString ussd;
    QString euro;
    QString cny;

private slots:

    void recalc();

    void changeCourseUSSD();
    void changeCourseEuro();
    void changeCourseCNY();

    void saveCourse();
};
//------------------------------------------------------------------------------------

#endif // WIDGET_H
