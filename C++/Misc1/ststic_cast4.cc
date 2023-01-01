/*
    static_cast conversion
    C++ C++ language Expressions 
    Converts between types using a combination of implicit and user-defined conversions.

    Syntax
    static_cast < new-type > ( expression )		
    Returns a value of type new-type.

    Explanation
    Only the following conversions can be done with static_cast, except when such conversions 
    would cast away constness or volatility.

    1) If new-type is a reference to some class D and expression is an lvalue of its non-virtual 
    base B, or new-type is a pointer to some complete class D and expression is a prvalue pointer 
    to its non-virtual base B, static_cast performs a downcast. (This downcast is ill-formed if 
    B is ambiguous, inaccessible, or virtual base (or a base of a virtual base) of D.)
    Such a downcast makes no runtime checks to ensure that the object's runtime type is actually D, 
    and may only be used safely if this precondition is guaranteed by other means, such as when 
    implementing static polymorphism. Safe downcast may be done with dynamic_cast. If the object 
    expression refers or points to is actually a base class subobject of an object of type D, the 
    result refers to the enclosing object of type D. Otherwise, the behavior is undefined:

    struct B {};
    struct D : B { B b; };
    
    D d;
    B& br1 = d;
    B& br2 = d.b;
    
    static_cast<D&>(br1); // OK: lvalue denoting the original d object
    static_cast<D&>(br2); // UB: the b subobject is not a base class subobject
    2) If new-type is an rvalue reference type, static_cast converts the value of glvalue, class 
    prvalue, or array prvalue (until C++17)any lvalue (since C++17) expression to xvalue referring 
    to the same object as the expression, or to its base sub-object (depending on new-type). If the 
    target type is an inaccessible or ambiguous base of the type of the expression, the program is 
    ill-formed. If the expression is a bit-field lvalue, it is first converted to prvalue of the 
    underlying type. This type of static_cast is used to implement move semantics in std::move. 
    (since C++11)
    3) If there is an implicit conversion sequence from expression to new-type, or if overload resolution 
    for a direct initialization of an object or reference of type new-type from expression would 
    find at least one viable function, then static_cast<new-type>(expression) returns the imaginary 
    variable Temp initialized as if by new-type Temp(expression);, which may involve implicit conversions, 
    a call to the constructor of new-type or a call to a user-defined conversion operator. For 
    non-reference new-type, the result object of the static_cast prvalue expression is what's 
    direct-initialized. (since C++17)
    4) If new-type is the type void (possibly cv-qualified), static_cast discards the value of expression 
    after evaluating it.
    5) If a standard conversion sequence from new-type to the type of expression exists, that does 
    not include lvalue-to-rvalue, array-to-pointer, function-to-pointer, null pointer, null member 
    pointer, function pointer, (since C++17) or boolean conversion, then static_cast can perform 
    the inverse of that implicit conversion.
    6) If conversion of expression to new-type involves lvalue-to-rvalue, array-to-pointer, or 
    function-to-pointer conversion, it can be performed explicitly by static_cast.
    7) Scoped enumeration type can be converted to an integer or floating-point type.
    When the target type is bool (possibly cv-qualified), the result is false if the original value 
    is zero and true for all other values. For the remaining integral types, the result is the value 
    of the enum if it can be represented by the target type and unspecified otherwise.

    (until C++20)
    The result is the same as implicit conversion from the enum's underlying type to the destination type.

    (since C++20)
    (since C++11)
    8) A value of integer or enumeration type can be converted to any complete enumeration type.
    If the underlying type is not fixed, the behavior is undefined if the value of expression is 
    out of range (the range is all values possible for the smallest bit field large enough to hold 
    all enumerators of the target enumeration).
    If the underlying type is fixed, the result is the same as converting the original value first 
    to the underlying type of the enumeration and then to the enumeration type.
    A value of a floating-point type can also be converted to any complete enumeration type.
    The result is the same as converting the original value first to the underlying type of the enumeration, 
    and then to the enumeration type.
    9) A pointer to member of some complete class D can be upcast to a pointer to member of its 
    unambiguous, accessible base class B. This static_cast makes no checks to ensure the member actually 
    exists in the runtime type of the pointed-to object.
    10) A prvalue of type pointer to void (possibly cv-qualified) can be converted to pointer to any 
    object type. If the original pointer value represents an address of a byte in memory that does not 
    satisfy the alignment requirement of the target type, then the resulting pointer value is unspecified. 
    Otherwise, if the original pointer value points to an object a, and there is an object b of the target 
    type (ignoring cv-qualification) that is pointer-interconvertible (as defined below) with a, the 
    result is a pointer to b. Otherwise the pointer value is unchanged. Conversion of any pointer to pointer 
    to void and back to pointer to the original (or more cv-qualified) type preserves its original value.
    As with all cast expressions, the result is:

    an lvalue if new-type is an lvalue reference type or an rvalue reference to function type (since C++11);
    an xvalue if new-type is an rvalue reference to object type;
    (since C++11)
    a prvalue otherwise.
    Two objects a and b are pointer-interconvertible if:

    they are the same object, or
    one is a union object and the other is a non-static data member of that object, or
    one is a standard-layout class object and the other is the first non-static data member of that object 
    or any base class subobject of that object, or
    there exists an object c such that a and c are pointer-interconvertible, and c and b are pointer-interconvertible.
    union U { int a; double b; } u;
    void* x = &u;                        // x's value is "pointer to u"
    double* y = static_cast<double*>(x); // y's value is "pointer to u.b"
    char* z = static_cast<char*>(x);     // z's value is "pointer to u"
    Notes
    static_cast may also be used to disambiguate function overloads by performing a function-to-pointer 
    conversion to specific type, as in

    std::for_each(files.begin(), files.end(),
                static_cast<std::ostream&(*)(std::ostream&)>(std::flush));
    Keywords
    static_cast

    Example
*/

#include <vector>
#include <iostream>
 
struct B
{
    int m = 42;
    const char* hello() const
    {
        return "Hello world, this is B!\n";
    }
};
 
struct D : B
{
    const char* hello() const
    {
        return "Hello world, this is D!\n";
    }
};
 
enum class E { ONE = 1, TWO, THREE };
enum EU { ONE = 1, TWO, THREE };
 
int main()
{
    // 1. static downcast
    D d;
    B& br = d; // upcast via implicit conversion
    std::cout << "1) " << br.hello();
    D& another_d = static_cast<D&>(br); // downcast
    std::cout << "1) " << another_d.hello();
 
    // 2. lvalue to xvalue
    std::vector<int> v0{1,2,3};
    std::vector<int> v2 = static_cast<std::vector<int>&&>(v0);
    std::cout << "2) after move, v0.size() = " << v0.size() << '\n';
 
    // 3. initializing conversion
    int n = static_cast<int>(3.14);
    std::cout << "3) n = " << n << '\n';
    std::vector<int> v = static_cast<std::vector<int>>(10);
    std::cout << "3) v.size() = " << v.size() << '\n';
 
    // 4. discarded-value expression
    static_cast<void>(v2.size());
 
    // 5. inverse of implicit conversion
    void* nv = &n;
    int* ni = static_cast<int*>(nv);
    std::cout << "4) *ni = " << *ni << '\n';
 
    // 6. array-to-pointer followed by upcast
    D a[10];
    [[maybe_unused]]
    B* dp = static_cast<B*>(a);
 
    // 7. scoped enum to int
    E e = E::TWO;
    int two = static_cast<int>(e);
    std::cout << "7) " << two << '\n';
 
    // 8. int to enum, enum to another enum
    E e2 = static_cast<E>(two);
    [[maybe_unused]]
    EU eu = static_cast<EU>(e2);
 
    // 9. pointer to member upcast
    int D::*pm = &D::m;
    std::cout << "9) " << br.*static_cast<int B::*>(pm) << '\n';
 
    // 10. void* to any type
    void* voidp = &e;
    [[maybe_unused]]
    std::vector<int>* p = static_cast<std::vector<int>*>(voidp);
}

// 1) Hello world, this is B!
// 1) Hello world, this is D!
// 2) after move, v0.size() = 0
// 3) n = 3
// 3) v.size() = 10
// 4) *ni = 3
// 7) 2
// 9) 42
