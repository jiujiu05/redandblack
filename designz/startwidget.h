#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "game.h"
#include "ui_game.h"

namespace Ui {
class startWidget;
}

class startWidget : public QWidget
{
    Q_OBJECT

public:
    void changewin();
    int num;
    explicit startWidget(QWidget *parent = 0);
    ~startWidget();
    game ra;
public slots:

private:
    Ui::startWidget *ui;


};

#endif // STARTWIDGET_H
