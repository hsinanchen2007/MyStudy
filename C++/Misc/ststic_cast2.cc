/*
    Lets the try to understand the above output:

    When obj is created then constructor is called which in our case is also a Conversion 
    Constructor(For C++14 rules are bit changed).
    
    When you create str out of obj, compiler will not thrown an error as we have defined 
    the Conversion operator.
    
    When you make obj=20, you are actually calling the conversion constructor.
    
    When you make str2 out of static_cast, it is quite similar to string str=obj;, but with 
    a tight type checking.
    
    When you write obj=static_cast<Int>(30), you are converting 30 into Int using static_cast.

    So if the return type is same as original class, Conversion Ctor called, otherwise
    Conversion Operator
*/

#include <iostream>
#include <string>

using namespace std;

class Int {
    int x;
  
public:
    Int(int x_in = 0)
        : x{ x_in }
    {
        cout << "Conversion Ctor called" << endl;
    }

    operator string()
    {
        cout << "Conversion Operator" << endl;
        return to_string(x);
    }
};

int main()
{
    Int obj(3);
    string str = obj;
    obj = 20;
    string str2 = static_cast<string>(obj);
    obj = static_cast<Int>(30);

    return 0;
}

// Conversion Ctor called, Int obj(3);
// Conversion Operator, string str = obj;
// Conversion Ctor called, obj = 20;
// Conversion Operator, string str2 = static_cast<string>(obj);
// Conversion Ctor called, obj = static_cast<Int>(30);
