#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPushButton>
#include <qlabel.h>
#include "subwidget.h"
namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:

    explicit game(QWidget *parent = 0);
    ~game();
    void startid();

    void star();
    void getn();
    void shenf();

    void selectspeak();     //发言
    void selectspeak1();
    void selectspeak2();

    void selectleader();    //选村长
    void selectleader1();
    void selectleader2();

    void eve();
    void so(int,int);

    void so1();
    void so2();
    void so3();
    void so4();
    void so5();
    void so6();
    void so7();
    void so8();
    void so9();
    void so10();
    void so11();
    void so12();
    void so13();
    void so14();
    void pick();

    int n=0;
private:
    Ui::game *ui;

    QPushButton* number[14];
    int identity[14];       //身份：1黑0红
    QLabel* txt[14];
    int hp[14];             //出局-1，存活0
    int now;                //发言人位
    subwidget w;
    int leader;
    int stk[14]={0};

};

#endif // GAME_H
