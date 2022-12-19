/*
    explicit specifier
    C++ C++ language Classes 
    explicit	(1)	
    explicit ( expression )	(2)	(since C++20)
    expression	-	contextually converted constant expression of type bool

    1) Specifies that a constructor or conversion function (since C++11)or deduction guide (since C++17) 
    is explicit, that is, it cannot be used for implicit conversions and copy-initialization.
    2) The explicit specifier may be used with a constant expression. The function is explicit if and only if 
    that constant expression evaluates to true. (since C++20)

    The explicit specifier may only appear within the decl-specifier-seq of the declaration of a constructor 
    or conversion function (since C++11) within its class definition.

    Notes
    A constructor with a single non-default parameter (until C++11) that is declared without the function 
    specifier explicit is called a converting constructor.

    Both constructors (other than copy/move) and user-defined conversion functions may be function templates; 
    the meaning of explicit does not change.

    A ( token that follows explicit is parsed as part of the explicit specifier:

    struct S {
        explicit (S)(const S&);    // error in C++20, OK in C++17
        explicit (operator int)(); // error in C++20, OK in C++17
    };
    (since C++20)
    Feature-test macro	Value	Std	Comment
    __cpp_conditional_explicit	201806L	(C++20)	explicit(bool)
*/

struct A
{
    A(int) { }      // converting constructor
    A(int, int) { } // converting constructor (C++11)
    operator bool() const { return true; }
};
 
struct B
{
    explicit B(int) { }
    explicit B(int, int) { }
    explicit operator bool() const { return true; }
};
 
int main()
{
    A a1 = 1;      // OK: copy-initialization selects A::A(int)
    A a2(2);       // OK: direct-initialization selects A::A(int)
    A a3 {4, 5};   // OK: direct-list-initialization selects A::A(int, int)
    A a4 = {4, 5}; // OK: copy-list-initialization selects A::A(int, int)
    A a5 = (A)1;   // OK: explicit cast performs static_cast
    if (a1) { }    // OK: A::operator bool()
    bool na1 = a1; // OK: copy-initialization selects A::operator bool()
    bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization
 
//  B b1 = 1;      // error: copy-initialization does not consider B::B(int)
    B b2(2);       // OK: direct-initialization selects B::B(int)
    B b3 {4, 5};   // OK: direct-list-initialization selects B::B(int, int)
//  B b4 = {4, 5}; // error: copy-list-initialization does not consider B::B(int, int)
    B b5 = (B)1;   // OK: explicit cast performs static_cast
    if (b2) { }    // OK: B::operator bool()
//  bool nb1 = b2; // error: copy-initialization does not consider B::operator bool()
    bool nb2 = static_cast<bool>(b2); // OK: static_cast performs direct-initialization
 
    [a4, a5, na1, na2, b5, nb2] { }; // may suppress "unused variable" warnings
}
