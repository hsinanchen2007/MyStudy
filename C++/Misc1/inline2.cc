/*
    Inline function and classes:
    It is also possible to define the inline function inside the class. In fact, 
    all the functions defined inside the class are implicitly inline. Thus, all the 
    restrictions of inline functions are also applied here. If you need to explicitly 
    declare inline function in the class then just declare the function inside 
    the class and define it outside the class using inline keyword.

    For example:

        class S
        {
        public:
            inline int square(int s) // redundant use of inline
            {
                // this function is automatically inline
                // function body
            }
        };

    The above style is considered as a bad programming style. The best programming style 
    is to just write the prototype of function inside the class and specify it as an 
    inline in the function definition.
    
    For example:

        class S
        {
        public:
            int square(int s); // declare the function
        };
        
        inline int S::square(int s) // use inline prefix
        {
        
        }

    The following program demonstrates this concept:


    What is wrong with macro?
    Readers familiar with the C language knows that C language uses macro. The preprocessor 
    replace all macro calls directly within the macro code. It is recommended to always use 
    inline function instead of macro. According to Dr. Bjarne Stroustrup the creator of C++ 
    that macros are almost never necessary in C++ and they are error prone. There are some 
    problems with the use of macros in C++. Macro cannot access private members of class. 
    Macros looks like function call but they are actually not.
    
    Example:

        #include <iostream>
        using namespace std;
        class S
        {
            int m;
        public:
        #define MAC(S::m)    // error
        };

    C++ compiler checks the argument types of inline functions and necessary conversions are 
    performed correctly. Preprocessor macro is not capable for doing this. One other thing is 
    that the macros are managed by preprocessor and inline functions are managed by C++ compiler.

    Remember: It is true that all the functions defined inside the class are implicitly inline 
    and C++ compiler will perform inline call of these functions, but C++ compiler cannot perform 
    inlining if the function is virtual. The reason is call to a virtual function is resolved at 
    runtime instead of compile time. Virtual means wait until runtime and inline means during 
    compilation, if the compiler doesn’t know which function will be called, how it can perform 
    inlining?

    One other thing to remember is that it is only useful to make the function inline if the 
    time spent during a function call is more compared to the function body execution time. 
    An example where inline function has no effect at all:

        inline void show()
        {
            cout << "value of S = " << S << endl;
        }

    The above function relatively takes a long time to execute. In general function which performs 
    input output (I/O) operation shouldn’t be defined as inline because it spends a considerable 
    amount of time. Technically inlining of show() function is of limited value because the amount 
    of time the I/O statement will take far exceeds the overhead of a function call.

    Depending upon the compiler you are using the compiler may show you warning if the function is 
    not expanded inline. Programming languages like Java & C# doesn’t support inline functions.
    But in Java, the compiler can perform inlining when the small final method is called, because 
    final methods can’t be overridden by sub classes and call to a final method is resolved at compile 
    time. In C# JIT compiler can also optimize code by inlining small function calls (like replacing 
    body of a small function when it is called in a loop).

    Last thing to keep in mind that inline functions are the valuable feature of C++. An appropriate 
    use of inline function can provide performance enhancement but if inline functions are used arbitrarily 
    then they can’t provide better result. In other words don’t expect better performance of program. 
    Don’t make every function inline. It is better to keep inline functions as small as possible.
*/

#include <iostream>
using namespace std;
class operation
{
    int a,b,add,sub,mul;
    float div;
public:
    void get();
    void sum();
    void difference();
    void product();
    void division();
};
inline void operation :: get()
{
    cout << "Enter first value:";
    cin >> a;
    cout << "Enter second value:";
    cin >> b;
}
  
inline void operation :: sum()
{
    add = a+b;
    cout << "Addition of two numbers: " << a+b << "\n";
}
  
inline void operation :: difference()
{
    sub = a-b;
    cout << "Difference of two numbers: " << a-b << "\n";
}
  
inline void operation :: product()
{
    mul = a*b;
    cout << "Product of two numbers: " << a*b << "\n";
}
  
inline void operation ::division()
{
    div=a/b;
    cout<<"Division of two numbers: "<<a/b<<"\n" ;
}
  
int main()
{
    cout << "Program using inline function\n";
    operation s;
    s.get();
    s.sum();
    s.difference();
    s.product();
    s.division();
    return 0;
}

// Program using inline function
// Enter first value:1
// Enter second value:2
// Addition of two numbers: 3
// Difference of two numbers: -1
// Product of two numbers: 2
// Division of two numbers: 0
