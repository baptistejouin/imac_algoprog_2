#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point)
{
    // recursiv Mandelbrot

    // check n
    if (n == 0)
        return 0;
    // check length of z if Mandelbrot, return 1 or n (check the difference)
    if (z.length() < 2)
        return 1;

    // otherwise, process the square of z and recall isMandebrot
    Point z1;

    // mise au carré de z
    z1.x = (z.x * z.x) - (z.y * z.y);
    z1.y = 2 * z.x * z.y;

    // new z1 = z² + point
    z1.x += point.x;
    z1.y += point.y;

    return isMandelbrot(z1, n - 1, point);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}
