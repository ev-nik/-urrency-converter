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

private slots:

    void recalc();

    void changeCourseUSSD();
    void changeCourseEuro();
    void changeCourseCNY();
};
//------------------------------------------------------------------------------------

#endif // WIDGET_H
