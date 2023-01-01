/*
    From https://en.cppreference.com/w/c/variadic

    Variadic functions are functions (e.g. printf) which take a variable number of arguments.

    The declaration of a variadic function uses an ellipsis as the last parameter, e.g. int 
    printf(const char* format, ...);. See variadic arguments for additional detail on the syntax 
    and automatic argument conversions.

    Accessing the variadic arguments from the function body uses the following library facilities:

    Macros
    Defined in header <stdarg.h>
    va_start
    
        The va_start macro enables access to the variable arguments following the named argument 
        parmN (until C23).

        va_start shall be invoked with an instance to a valid va_list object ap before any calls 
        to va_arg.

        If parmN is declared with register storage class specifier, with an array type, with a 
        function type, or with a type not compatible with the type that results from default argument 
        promotions, the behavior is undefined.

        (until C23)
        Only the first argument passed to va_start is evaluated. Any additional arguments are neither 
        expanded nor used in any way.

        (since C23)
        Parameters
        ap	-	an instance of the va_list type
        parmN	-	the named parameter preceding the first variable parameter
        Expanded value
        (none)

    enables access to variadic function arguments
    (function macro)
    va_arg
    
        The va_arg macro expands to an expression of type T that corresponds to the next parameter from 
        the va_list ap.

        Prior to calling va_arg, ap must be initialized by a call to either va_start or va_copy, with no 
        intervening call to va_end. Each invocation of the va_arg macro modifies ap to point to the next 
        variable argument.

        If the type of the next argument in ap (after promotions) is not compatible with T, the behavior 
        is undefined, unless:

        one type is a signed integer type, the other type is the corresponding unsigned integer type, and 
        the value is representable in both types; or one type is pointer to void and the other is a pointer 
        to a character type. If va_arg is called when there are no more arguments in ap, the behavior is undefined.

        Parameters
        ap	-	an instance of the va_list type
        T	-	the type of the next parameter in ap
        Expanded value
        the next variable parameter in ap

    accesses the next variadic function argument
    (function macro)
    va_copy
    
        The va_copy macro copies src to dest.

        va_end should be called on dest before the function returns or any subsequent re-initialization of dest 
        (via calls to va_start or va_copy).

        Parameters
        dest	-	an instance of the va_list type to initialize
        src	-	the source va_list that will be used to initialize dest
        Expanded value
        (none)

        (C99)
    
    makes a copy of the variadic function arguments
    (function macro)
    va_end
    
        The va_end macro performs cleanup for an ap object initialized by a call to va_start or va_copy. va_end 
        may modify ap so that it is no longer usable.

        If there is no corresponding call to va_start or va_copy, or if va_end is not called before a function 
        that calls va_start or va_copy returns, the behavior is undefined.

        Parameters
        ap	-	an instance of the va_list type to clean up
        Expanded value
        (none)

    ends traversal of the variadic function arguments
    (function macro)
    Type
    va_list
    
        va_list is a complete object type suitable for holding the information needed by the macros va_start, 
        va_copy, va_arg, and va_end.

        If a va_list instance is created, passed to another function, and used via va_arg in that function, then 
        any subsequent use in the calling function should be preceded by a call to va_end.

        It is legal to pass a pointer to a va_list object to another function and then use that object after the 
        function returns.

    holds the information needed by va_start, va_arg, va_end, and va_copy
    (typedef)
*/

// some often common headers and namespace
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>

// need to additional header file here
#include <stdarg.h>

using namespace std;

void simple_printf(const char* fmt, ...)
{
    // 1. call va_list to get args
    va_list args;

    // 2. call va_start(args, first_argument)
    va_start(args, fmt);
 
    // 3. loop for all arguments
    while (*fmt != '\0') {
        if (*fmt == 'd') {
            // 4. call va_arg(args, type of argument) to get argument value
            int i = va_arg(args, int);
            printf("%d\n", i);
        } else if (*fmt == 'c') {
            // A 'char' variable will be promoted to 'int'
            // A character literal in C is already 'int' by itself
            // 4. call va_arg(args, type of argument) to get argument value
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            // 4. call va_arg(args, type of argument) to get argument value
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
        ++fmt;
    }
 
    // 5. call va_end() to end of args
    va_end(args);
}
 
int main(void)
{
    simple_printf("dcff", 3, 'a', 1.999, 42.5); 
}

// 3
// a
// 1.999000
// 42.500000
