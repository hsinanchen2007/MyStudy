// FncLib.cpp
#include <cmath>
using std::fabs;
const float Epsilon = 1.0E-16;

// --- �w�q��� Divide() -----
float Divide(float a, float b)
{
    if (fabs(b) <= Epsilon)
      throw "���Ƭ��s!";
    return a / b;
}
