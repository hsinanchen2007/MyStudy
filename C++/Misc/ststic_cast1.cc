/*
    A Cast operator is an unary operator which forces one data type to be converted into 
    another data type. C++ supports four types of casting:

    1. Static Cast
    2. Dynamic Cast
    3. Const Cast
    4. Reinterpret Cast

    Static Cast: This is the simplest type of cast which can be used. It is a compile time 
    cast.It does things like implicit conversions between types (such as int to float, or 
    pointer to void*), and it can also call explicit conversion functions (or implicit ones).
*/

#include <iostream>

using namespace std;

int main()
{
    float f = 3.5;

    int a = f; // this is how you do in C
    int b = static_cast<int>(f);
    cout << a << " " << b << endl;

    return 0;
}

// 3 3

