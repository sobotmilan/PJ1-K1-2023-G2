#include "Point.h"
#include <iostream>
using namespace std;
Point::Point(int x, int y) : x(x), y(y)
{
}
Point::Point(const Point &other) : Point(other.x, other.y)
{
}
Point::Point(Point &&other) : Point(other.x, other.y)
{
    other.x = 0;
    other.y = 0;
}
Point::~Point()
{
}
int Point::getX() const
{
    return this->x;
}
int Point::getY() const
{
    return this->y;
}
void Point::setX(int value)
{
    this->x = value;
}
void Point::setY(int value)
{
    this->y = value;
}
Point &Point::operator*(double d)
{
    this->x *= d;
    this->y *= d;
    return *this;
}
Point &operator*(double d, Point &t)
{
    t.setX(t.getX() * d);
    t.setY(t.getY() * d);
    return t;
}
std::ostream &operator<<(std::ostream &os, const Point &t)
{
    os << "(" << t.getX() << "," << t.getY() << ")";
    return os;
}
Point &Point::operator=(const Point &other)
{
    if (this == &other)
        return *this;
    this->x = other.x;
    this->y = other.y;
    return *this;
}
Point &Point::operator=(Point &&other)
{
    if (this == &other)
        return *this;
    this->x = other.x;
    this->y = other.y;
    other.x = 0;
    other.y = 0;
    return *this;
}