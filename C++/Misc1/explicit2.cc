/*
    Explicit Keyword in C++ is used to mark constructors to not implicitly convert types in C++. 
    It is optional for constructors that take exactly one argument and work on constructors(with 
    a single argument) since those are the only constructors that can be used in typecasting.

    Let’s understand explicit keyword through an example. 

    Predict the output of the following C++ Program

    // C++ program to illustrate default
    // constructor without 'explicit'
    // keyword
    #include <iostream>

    using namespace std;
    
    class Complex {
    private:
        double real;
        double imag;
    
    public:
    
        // Parameterized constructor
        Complex(double r = 0.0,
                double i = 0.0) : real(r),
                                imag(i)
        {
        }
    
        // A method to compare two
        // Complex numbers
        bool operator == (Complex rhs)
        {
            return (real == rhs.real &&
                    imag == rhs.imag);
        }
    };
    
    // Driver Code
    int main()
    {
        // a Complex object
        Complex com1(3.0, 0.0);
    
        if (com1 == 3.0)
            cout << "Same";
        else
            cout << "Not Same";
        return 0;
    }

    Output

    Same

    As discussed in this article, in C++, if a class has a constructor which can be called with a single argument, 
    then this constructor becomes a conversion constructor because such a constructor allows conversion of the single 
    argument to the class being constructed. In this case, when com1 == 3.0 is called, 3.0 is implicitly converted 
    to Complex type because the default constructor can be called with only 1 argument because both parameters are 
    default arguments and we can choose not to provide them.

    We can avoid such implicit conversions as these may lead to unexpected results. We can make the constructor explicit 
    with the help of an explicit keyword. For example, if we try the following program that uses explicit keywords 
    with a constructor, we get a compilation error.

    // C++ program to illustrate
    // default constructor with
    // 'explicit' keyword
    #include <iostream>
    using namespace std;
    
    class Complex {
    private:
        double real;
        double imag;
    
    public:
        // Default constructor
        explicit Complex(double r = 0.0,
                        double i = 0.0) :
                        real(r), imag(i)
        {
        }
    
        // A method to compare two
        // Complex numbers
        bool operator == (Complex rhs)
        {
            return (real == rhs.real &&
                    imag == rhs.imag);
        }
    };
    
    // Driver Code
    int main()
    {
        // a Complex object
        Complex com1(3.0, 0.0);
    
        if (com1 == 3.0)
            cout << "Same";
        else
            cout << "Not Same";
        return 0;
    }
    Output

    Compiler Error : no match for 'operator==' in 'com1 == 3.0e+0'
    We receive an error here because to avoid any unexpected errors we have made our constructor an explicit constructor 
    and 3.0 won’t be converted to Complex by our constructor on its own.

    We can still typecast the double values to Complex, but now we have to explicitly typecast it. For example, the following 
    program works fine.
*/

// C++ program to illustrate
// default constructor with
// 'explicit' keyword
#include <iostream>
using namespace std;
 
class Complex {
private:
    double real;
    double imag;
 
public:
   
    // Default constructor
    explicit Complex(double r = 0.0,
                     double i = 0.0):
                     real(r) , imag(i)
    {
    }
 
    // A method to compare two
    // Complex numbers
    bool operator == (Complex rhs)
    {
        return (real == rhs.real &&
                imag == rhs.imag);
    }
};
 
// Driver Code
int main()
{
    // a Complex object
    Complex com1(3.0, 0.0);
 
    // the additional "(Complex)" below perform the conversion so the operator 
    // can work properly, otherwise it has no corresponding type for operator
    if (com1 == (Complex)3.0)
        cout << "Same";
    else
        cout << "Not Same";
    return 0;
}

// Same
