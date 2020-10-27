#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //creates an instance
    MainWindow w;
    w.show();
    return a.exec(); //this is the main event loop
}
