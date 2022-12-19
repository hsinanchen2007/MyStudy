/*
    const_cast conversion
    C++ C++ language Expressions 
    Converts between types with different cv-qualification.

    Syntax
    const_cast < new-type > ( expression )		
    Returns a value of type new-type.

    Explanation
    Only the following conversions can be done with const_cast. In particular, only const_cast 
    may be used to cast away (remove) constness or volatility.

    1) Two possibly multilevel pointers to the same type may be converted between each other, 
    regardless of cv-qualifiers at each level.
    2) lvalue of any type T may be converted to a lvalue or rvalue reference to the same type T, 
    more or less cv-qualified. Likewise, a prvalue of class type or an xvalue of any type may 
    be converted to a more or less cv-qualified rvalue reference. The result of a reference 
    const_cast refers to the original object if expression is a glvalue and to the materialized 
    temporary otherwise (since C++17).
    3) Same rules apply to possibly multilevel pointers to data members and possibly multilevel 
    pointers to arrays of known and unknown bound (arrays to cv-qualified elements are considered 
    to be cv-qualified themselves) (since C++17)
    4) null pointer value may be converted to the null pointer value of new-type
    As with all cast expressions, the result is:

    an lvalue if new-type is an lvalue reference type or an rvalue reference to function type 
    (since C++11);
    an xvalue if new-type is an rvalue reference to object type;
    (since C++11)
    a prvalue otherwise.
    Notes
    Pointers to functions and pointers to member functions are not subject to const_cast

    const_cast makes it possible to form a reference or pointer to non-const type that is actually 
    referring to a const object or a reference or pointer to non-volatile type that is actually referring 
    to a volatile object. Modifying a const object through a non-const access path and referring to 
    a volatile object through a non-volatile glvalue results in undefined behavior.

    Keywords
    const_cast
*/

#include <iostream>
 
struct type
{
    int i;
 
    type(): i(3) {}
 
    void f(int v) const
    {
        // this->i = v;                 // compile error: this is a pointer to const
        const_cast<type*>(this)->i = v; // OK as long as the type object isn't const
    }
};
 
int main() 
{
    int i = 3;                 // i is not declared const
    const int& rci = i; 
    const_cast<int&>(rci) = 4; // OK: modifies i
    std::cout << "i = " << i << '\n';
 
    type t; // if this was const type t, then t.f(4) would be undefined behavior
    t.f(4);
    std::cout << "type::i = " << t.i << '\n';
 
    const int j = 3; // j is declared const
    [[maybe_unused]]
    int* pj = const_cast<int*>(&j);
    // *pj = 4;      // undefined behavior
 
    [[maybe_unused]]
    void (type::* pmf)(int) const = &type::f; // pointer to member function
    // const_cast<void(type::*)(int)>(pmf);   // compile error: const_cast does
                                              // not work on function pointers
}

// i = 4
// type::i = 4
