#include "slateapi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SlateAPI w;
    w.show();

    return a.exec();
}
