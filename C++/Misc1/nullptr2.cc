/*
    nullptr, the pointer literal
    C++ C++ language Expressions 

    Syntax
    nullptr		(since C++11)
    
    Explanation
    The keyword nullptr denotes the pointer literal. It is a prvalue of type std::nullptr_t. 
    There exist implicit conversions from nullptr to null pointer value of any pointer type 
    and any pointer to member type. Similar conversions exist for any null pointer constant, 
    which includes values of type std::nullptr_t as well as the macro NULL.

    Example
    Demonstrates that nullptr retains the meaning of null pointer constant even if it is no 
    longer a literal.
*/

#include <cstddef>
#include <iostream>
 
template<class T>
constexpr T clone(const T& t)
{
    return t;
}
 
void g(int*)
{
    std::cout << "Function g called\n";
}
 
int main()
{
    g(nullptr);        // Fine
    g(NULL);           // Fine
    g(0);              // Fine
 
    g(clone(nullptr)); // Fine
    //  g(clone(NULL));    // ERROR: non-literal zero cannot be a null pointer constant
    //  g(clone(0));       // ERROR: non-literal zero cannot be a null pointer constant
}

// Function g called
// Function g called
// Function g called
// Function g called
