#pragma once
#include <iostream>
class Point
{
    int x, y;

public:
    Point(int x = 0, int y = 0);
    Point(const Point &);
    Point(Point &&);
    ~Point();

    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);

    Point &operator*(double d);
    Point &operator=(const Point &);
    Point &operator=(Point &&);
};
std::ostream &operator<<(std::ostream &os, const Point &);
Point &operator*(double, Point &);