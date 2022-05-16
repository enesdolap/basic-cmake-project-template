#include "example.h"

example::example(/* args */)
{
}

example::~example()
{
}

unsigned int example::factorial(unsigned int number)
{
    return number <= 1 ? number : this->factorial(number - 1) * number;
}
