#include "startwidget.h"
#include <QApplication>
#include "game.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startWidget nu;
    nu.show();
    return a.exec();
}
