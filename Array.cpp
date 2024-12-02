#include "Array.h"
#include <climits>
#include <iostream>
static Point ERROR(INT_MIN, INT_MIN);

Array::Array(int initialCapacity) : capacity(initialCapacity), length(0)
{
    if (this->capacity < 0)
        this->capacity = 0;
    this->data = new Point[this->capacity];
}
Array::Array(const Array &other) : capacity(other.capacity), length(other.length), data(new Point[other.capacity])
{
    for (int i = 0; i < this->length; i++)
        this->data[i] = other.data[i];
}
Array::Array(Array &&other) : capacity(other.capacity), length(other.length), data(other.data)
{
    other.data = nullptr;
    other.length = 0;
    other.capacity = 0;
}
Array::~Array()
{
    this->dispose();
    this->capacity = 0;
    this->length = 0;
}
void Array::dispose()
{
    delete[] this->data;
    this->data = nullptr;
}
void Array::append(const Point &other)
{
    if (this->length >= this->capacity)
        this->resize(this->capacity * 2);

    this->data[this->length++] = other;
}
void Array::resize(int newCapacity)
{
    if (this->capacity == 0)
        newCapacity = 1;
    this->length = this->length > newCapacity ? newCapacity : this->length;
    Point *temp = new Point[newCapacity];
    for (int i = 0; i < this->length; i++)
        temp[i] = this->data[i];
    this->dispose();
    this->data = temp;
    this->capacity = newCapacity;
}
Point &Array::at(int index)
{
    if (index > -1 && index < this->length)
        return this->data[index];
    else
        return ERROR;
}
const Point &Array::at(int index) const
{
    if (index > -1 && index < this->length)
        return this->data[index];
    else
        return ERROR;
}

Array &Array::operator*(double d)
{
    for (int i = 0; i < this->length; i++)
        this->data[i] = this->data[i] * d;
    return *this;
}
const Array Array::operator*(double d) const
{
    Array result(*this);
    for (int i = 0; i < this->length; i++)
        result.data[i] = (result.data[i] * d);
    return result;
}
int Array::getLength() const
{
    return this->length;
}
int Array::getCapacity() const
{
    return this->capacity;
}
Array Array::filter(bool (*f)(const Point &)) const
{
    Array result(this->capacity);
    result.length = 0;
    for (int i = 0; i < this->length; i++)
        if ((*f)(this->data[i]))
        {
            result.data[i] = this->data[i];
            result.length++;
        }
    if (result.length < this->length)
        result.resize(result.length);
    return result;
}

Array &operator*(double d, Array &other)
{
    for (int i = 0; i < other.getLength(); i++)
        other.data[i] = other.data[i] * d;
    return other;
}
const Array operator*(double d, const Array &other)
{
    const Array result(other * d);
    return result;
}
std::ostream &operator<<(std::ostream &os, const Array &other)
{
    os << "[ ";
    for (int i = 0; i < other.getLength(); i++)
        os << other.at(i) << " ";
    os << "]";
    return os;
}