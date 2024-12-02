#include "Point.h"
#include "Array.h"
#include <iostream>
using namespace std;

int main()
{
    auto filter = [](const Point &other) -> bool
    {
        if (other.getX() > 0)
            return true;
        else
            return false;
    };
    Point a(-1, -2);
    Point b(3, 4);
    cout << a << endl;
    cout << b << endl;
    cout << (a * 3) << endl;
    Array c(1);
    c.append(b);
    c.append(a);
    cout << "test at funkcije ispod:" << endl;
    cout << "c.at(0): " << c.at(0) << endl;
    cout << "c.at(1): " << c.at(1) << endl;
    cout << c << endl;
    cout << (c * 3) << endl;
    cout << (3 * c) << endl;
    cout << c.filter(filter) << endl;

    const Array d(std::move(c));
    cout << "test at funkcije ispod:" << endl;
    cout << "d.at(0): " << d.at(0) << endl;
    cout << "d.at(1): " << d.at(1) << endl;
    cout << d << endl;
    cout << (d * 3) << endl;
    cout << (3 * d) << endl;
    cout << d.filter(filter) << endl;
    cout << d << endl;

    return 0;
}