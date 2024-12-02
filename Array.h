#pragma once
#include "Point.h"

class Array
{
    int length, capacity;
    Point *data;

public:
    Array(int initialCapacity = 1);
    Array(const Array &);
    Array(Array &&);
    ~Array();

    void append(const Point &);
    void resize(int newCapacity);
    void dispose();
    Array &operator=(const Array &) = delete;
    Array &operator=(Array &&) = delete;
    int getLength() const;
    int getCapacity() const;
    Point &at(int index);
    const Point &at(int index) const;

    Array &operator*(double d);
    const Array operator*(double d) const;

    Array filter(bool (*)(const Point &)) const;
    friend Array &operator*(double d, Array &);
};

const Array operator*(double d, const Array &);
std::ostream &operator<<(std::ostream &os, const Array &);
