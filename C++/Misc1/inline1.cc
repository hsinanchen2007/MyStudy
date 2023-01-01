/*
    Inline function is one of the important feature of C++. So, let’s first understand 
    why inline functions are used and what is the purpose of inline function?

    When the program executes the function call instruction the CPU stores the memory 
    address of the instruction following the function call, copies the arguments of the 
    function on the stack and finally transfers control to the specified function. The 
    CPU then executes the function code, stores the function return value in a predefined 
    memory location/register and returns control to the calling function. This can become 
    overhead if the execution time of function is less than the switching time from the 
    caller function to called function (callee). For functions that are large and/or 
    perform complex tasks, the overhead of the function call is usually insignificant 
    compared to the amount of time the function takes to run. However, for small, 
    commonly-used functions, the time needed to make the function call is often a lot more 
    than the time needed to actually execute the function’s code. This overhead occurs for 
    small functions because execution time of small function is less than the switching time.

    C++ provides an inline functions to reduce the function call overhead. Inline function 
    is a function that is expanded in line when it is called. When the inline function is 
    called whole code of the inline function gets inserted or substituted at the point of 
    inline function call. This substitution is performed by the C++ compiler at compile time. 
    Inline function may increase efficiency if it is small.
    
    The syntax for defining the function inline is:

    inline return-type function-name(parameters)
    {
        // function code
    }  

    Remember, inlining is only a request to the compiler, not a command. Compiler can ignore 
    the request for inlining. Compiler may not perform inlining in such circumstances like:
    1) If a function contains a loop. (for, while, do-while)
    2) If a function contains static variables.
    3) If a function is recursive.
    4) If a function return type is other than void, and the return statement doesn’t exist in 
    function body.
    5) If a function contains switch or goto statement.

    Inline functions provide following advantages:
        1) Function call overhead doesn’t occur.
        2) It also saves the overhead of push/pop variables on the stack when function is called.
        3) It also saves overhead of a return call from a function.
        4) When you inline a function, you may enable compiler to perform context specific optimization 
        on the body of function. Such optimizations are not possible for normal function calls. Other 
        optimizations can be obtained by considering the flows of calling context and the called context.
        5) Inline function may be useful (if it is small) for embedded systems because inline can 
        yield less code than the function call preamble and return.

    Inline function disadvantages:
        1) The added variables from the inlined function consumes additional registers, After in-lining 
        function if variables number which are going to use register increases than they may create 
        overhead on register variable resource utilization. This means that when inline function body 
        is substituted at the point of function call, total number of variables used by the function 
        also gets inserted. So the number of register going to be used for the variables will also get 
        increased. So if after function inlining variable numbers increase drastically then it would 
        surely cause an overhead on register utilization.
        2) If you use too many inline functions then the size of the binary executable file will be 
        large, because of the duplication of same code.
        3) Too much inlining can also reduce your instruction cache hit rate, thus reducing the speed 
        of instruction fetch from that of cache memory to that of primary memory.
        4) Inline function may increase compile time overhead if someone changes the code inside the 
        inline function then all the calling location has to be recompiled because compiler would require 
        to replace all the code once again to reflect the changes, otherwise it will continue with 
        old functionality.
        5) Inline functions may not be useful for many embedded systems. Because in embedded systems 
        code size is more important than speed.
        6) Inline functions might cause thrashing because inlining might increase size of the binary 
        executable file. Thrashing in memory causes performance of computer to degrade.

    The following program demonstrates the use of use of inline function.


    From https://cplusplus.com/articles/2LywvCM9/

    What is C++ inline functions
        In C, we have used Macro function an optimized technique used by compiler to reduce the execution 
        time etc. So Question comes in mind that what’s there in C++ for that and in what all better ways? 
        Inline function is introduced which is an optimization technique used by the compilers especially 
        to reduce the execution time. We will cover “what, why, when & how” of inline functions.

    What is inline function :
        The inline functions are a C++ enhancement feature to increase the execution time of a program. 
        Functions can be instructed to compiler to make them inline so that compiler can replace those function 
        definition wherever those are being called. Compiler replaces the definition of inline functions 
        at compile time instead of referring function definition at runtime.
        
        NOTE- This is just a suggestion to compiler to make the function inline, if function is big (in term 
        of executable instruction etc) then, compiler can ignore the “inline” request and treat the function 
        as normal function.

    How to make function inline:
        To make any function as inline, start its definitions with the keyword “inline”.

        Example –
            Class A
            {
            Public:
                inline int add(int a, int b)
                {
                return (a + b);
                };
            }

            Class A
            {
            Public:
                int add(int a, int b);
            };

            inline int A::add(int a, int b)
            {
            return (a + b);
            }

    Why to use –
        In many places we create the functions for small work/functionality which contain simple and less number 
        of executable instruction. Imagine their calling overhead each time they are being called by callers.
        When a normal function call instruction is encountered, the program stores the memory address of the instructions 
        immediately following the function call statement, loads the function being called into the memory, copies 
        argument values, jumps to the memory location of the called function, executes the function codes, stores 
        the return value of the function, and then jumps back to the address of the instruction that was saved just 
        before executing the called function. Too much run time overhead.

        The C++ inline function provides an alternative. With inline keyword, the compiler replaces the function call 
        statement with the function code itself (process called expansion) and then compiles the entire code. Thus, 
        with inline functions, the compiler does not have to jump to another location to execute the function, and then 
        jump back as the code of the called function is already available to the calling program.
        With below pros, cons and performance analysis, you will be able to understand the “why” for inline keyword

        Pros :-
        1. It speeds up your program by avoiding function calling overhead.
        2. It save overhead of variables push/pop on the stack, when function calling happens.
        3. It save overhead of return call from a function.
        4. It increases locality of reference by utilizing instruction cache.
        5. By marking it as inline, you can put a function definition in a header file (i.e. it can be included in 
        multiple compilation unit, without the linker complaining)

        Cons :-
        1. It increases the executable size due to code expansion.
        2. C++ inlining is resolved at compile time. Which means if you change the code of the inlined function, 
        you would need to recompile all the code using it to make sure it will be updated
        3. When used in a header, it makes your header file larger with information which users don’t care.
        4. As mentioned above it increases the executable size, which may cause thrashing in memory. More number 
        of page fault bringing down your program performance.
        5. Sometimes not useful for example in embedded system where large executable size is not preferred at all 
        due to memory constraints.

    When to use -
        Function can be made as inline as per programmer need. Some useful recommendation are mentioned below-
        1. Use inline function when performance is needed.
        2. Use inline function over macros.
        3. Prefer to use inline keyword outside the class with the function definition to hide implementation details.

    Key Points -
        1. It’s just a suggestion not compulsion. Compiler may or may not inline the functions you marked as inline. 
        It may also decide to inline functions not marked as inline at compilation or linking time.
        2. Inline works like a copy/paste controlled by the compiler, which is quite different from a pre-processor macro: 
        The macro will be forcibly inlined, will pollute all the namespaces and code, won't be easy to debug.
        3. All the member function declared and defined within class are Inline by default. So no need to define explicitly.
        4. Virtual methods are not supposed to be inlinable. Still, sometimes, when the compiler can know for sure 
        the type of the object (i.e. the object was declared and constructed inside the same function body), even a virtual 
        function will be inlined because the compiler knows exactly the type of the object.
        5. Template methods/functions are not always inlined (their presence in an header will not make them automatically 
        inline).
        6. Most of the compiler would do in-lining for recursive functions but some compiler provides #pragmas-
        microsoft c++ compiler - inline_recursion(on) and once can also control its limit with inline_depth.
        In gcc, you can also pass this in from the command-line with --max-inline-insns-recursive
*/

#include <iostream>
using namespace std;

inline int cube(int s)
{
    return s*s*s;
}
int main()
{
    cout << "The cube of 3 is: " << cube(3) << "\n";
    return 0;
} 

// The cube of 3 is: 27


