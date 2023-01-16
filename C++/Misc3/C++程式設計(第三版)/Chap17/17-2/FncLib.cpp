// FncLib.cpp
#include <cmath>
using std::fabs;
const float Epsilon = 1.0E-16;

// --- 定義函數 Divide() -----
float Divide(float a, float b)
{
    if (fabs(b) <= Epsilon)
      throw "除數為零!";
    return a / b;
}
