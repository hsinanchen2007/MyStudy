/*
    dynamic_cast conversion
    C++ C++ language Expressions 
    Safely converts pointers and references to classes up, down, and sideways along the inheritance 
    hierarchy.

    Syntax
    dynamic_cast < new-type > ( expression )		
    new-type	-	pointer to complete class type, reference to complete class type, or pointer to 
    (optionally cv-qualified) void
    expression	-	lvalue (until C++11)glvalue (since C++11) of a complete class type if new-type 
    is a reference, prvalue of a pointer to complete class type if new-type is a pointer.
    If the cast is successful, dynamic_cast returns a value of type new-type. If the cast fails and 
    new-type is a pointer type, it returns a null pointer of that type. If the cast fails and new-type 
    is a reference type, it throws an exception that matches a handler of type std::bad_cast.

    Explanation
    Only the following conversions can be done with dynamic_cast, except when such conversions would 
    cast away constness or volatility.

    1) If the type of expression is exactly new-type or a less cv-qualified version of new-type, the 
    result is the value of expression, with type new-type. (In other words, dynamic_cast can be used 
    to add constness. An implicit conversion and static_cast can perform this conversion as well.)
    2) If the value of expression is the null pointer value, the result is the null pointer value of 
    type new-type.
    3) If new-type is a pointer or reference to Base, and the type of expression is a pointer or reference 
    to Derived, where Base is a unique, accessible base class of Derived, the result is a pointer or 
    reference to the Base class subobject within the Derived object pointed or identified by expression. 
    (Note: an implicit conversion and static_cast can perform this conversion as well.)
    4) If expression is a pointer to a polymorphic type, and new-type is a pointer to void, the result 
    is a pointer to the most derived object pointed or referenced by expression.
    5) If expression is a pointer or reference to a polymorphic type Base, and new-type is a pointer or 
    reference to the type Derived a runtime check is performed:
    a) The most derived object pointed/identified by expression is examined. If, in that object, expression 
    points/refers to a public base of Derived, and if only one object of Derived type is derived from the 
    subobject pointed/identified by expression, then the result of the cast points/refers to that Derived 
    object. (This is known as a "downcast".)
    b) Otherwise, if expression points/refers to a public base of the most derived object, and, simultaneously, 
    the most derived object has an unambiguous public base class of type Derived, the result of the cast 
    points/refers to that Derived (This is known as a "sidecast".)
    c) Otherwise, the runtime check fails. If the dynamic_cast is used on pointers, the null pointer value 
    of type new-type is returned. If it was used on references, the exception std::bad_cast is thrown.
    6) When dynamic_cast is used in a constructor or a destructor (directly or indirectly), and expression 
    refers to the object that's currently under construction/destruction, the object is considered to be 
    the most derived object. If new-type is not a pointer or reference to the constructor's/destructor's 
    own class or one of its bases, the behavior is undefined.
    
    Similar to other cast expressions, the result is:

    an lvalue if new-type is a reference type
    an rvalue if new-type is a pointer type
    (until C++11)
    an lvalue if new-type is an lvalue reference type (expression must be an lvalue)
    an xvalue if new-type is an rvalue reference type (expression may be lvalue or rvalue (until C++17) must 
    be a glvalue (prvalues are materialized) (since C++17) of a complete class type)
    a prvalue if new-type is a pointer type
    (since C++11)
    Notes
    A downcast can also be performed with static_cast, which avoids the cost of the runtime check, but it's 
    only safe if the program can guarantee (through some other logic) that the object pointed to by expression 
    is definitely Derived.
    Some forms of dynamic_cast rely on runtime type identification (RTTI), that is, information about each 
    polymorphic class in the compiled program. Compilers typically have options to disable the inclusion of 
    this information.
    
    Keywords
    dynamic_cast

    Example
*/

#include <iostream>
 
struct V
{
    virtual void f() {} // must be polymorphic to use runtime-checked dynamic_cast
};
 
struct A : virtual V {};
 
struct B : virtual V
{
    B(V* v, A* a)
    {
        // casts during construction (see the call in the constructor of D below)
        dynamic_cast<B*>(v); // well-defined: v of type V*, V base of B, results in B*
        dynamic_cast<B*>(a); // undefined behavior: a has type A*, A not a base of B
    }
};
 
struct D : A, B
{
    D() : B(static_cast<A*>(this), this) {}
};
 
struct Base
{
    virtual ~Base() {}
};
 
struct Derived: Base
{
    virtual void name() {}
};
 
int main()
{
    D d; // the most derived object
    A& a = d; // upcast, dynamic_cast may be used, but unnecessary
 
    [[maybe_unused]]
    D& new_d = dynamic_cast<D&>(a); // downcast
    [[maybe_unused]]
    B& new_b = dynamic_cast<B&>(a); // sidecast
 
    Base* b1 = new Base;
    if (Derived* d = dynamic_cast<Derived*>(b1); d != nullptr)
    {
        std::cout << "downcast from b1 to d successful\n";
        d->name(); // safe to call
    }
 
    Base* b2 = new Derived;
    if (Derived* d = dynamic_cast<Derived*>(b2); d != nullptr)
    {
        std::cout << "downcast from b2 to d successful\n";
        d->name(); // safe to call
    }
 
    delete b1;
    delete b2;
}

// downcast from b2 to d successful

