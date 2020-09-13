#include "startwidget.h"
#include "ui_startwidget.h"
#include <QPushButton>
#include "game.h"
#include <QSpinBox>
#include <qdebug.h>
startWidget::startWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startWidget)
{
    ui->setupUi(this);
    connect(ui->start,&QPushButton::released, this, &startWidget::changewin);
}

startWidget::~startWidget()
{
    delete ui;
}

void startWidget::changewin(){
    this->close();
    ra.show();
}
