/*
    Understanding “volatile” qualifier in C | Set 1 (Introduction)
    Difficulty Level : Medium
    Last Updated : 15 Jun, 2022
    Read
    Discuss
    Practice
    Video
    Courses

    In spite of tons of literature on C language, “volatile” keyword is somehow not understood well 
    (even by experienced C programmers). We think that the main reason for this is due to not having 
    real-world use-case of a ‘volatile‘ variable in typical C programs that are written in high level 
    language. Basically, unless you’re doing some low level hardware programming in C, you probably 
    won’t use a variable while is qualified as “volatile“. By low level programming, we mean a piece 
    of C code which is dealing with peripheral devices, IO ports (mainly memory mapped IO ports), 
    Interrupt Service Routines (ISRs) which interact with Hardware. That’s why it’s not so straight 
    forward to have a sample working C program which can easily show-case the exact effect of “volatile” 
    keyword. 

    In fact, in this article, if we could explain the meaning and purpose of ‘volatile‘, it would 
    serve as basic groundwork for further study and use of ‘volatile’ in C. To understand ‘volatile’, 
    we first need to have some background about what a compiler does to a C program. At high level, 
    we know that a compiler converts C code to Machine code so that the executable can be run without 
    having actual source code. Similar to other technologies, compiler technology had also evolved a lot. 
    While translating Source code to Machine code, compilers typically try to optimize the output so 
    that lesser Machine code needs to be executed finally. One such optimization is removing unnecessary 
    Machine code for accessing variable which is not changing from Compiler’s perspective. Suppose 
    we have the following code:

        uint32 status = 0;
        
        while (status == 0)
        {
        // Let us assume that status isn't being changed
        // in this while loop or may be in our whole program
        
        // So long as status (which could be reflecting
        // status of some IO port) is ZERO, do something

        }

    An optimizing Compiler would see that status isn’t being changed by while loop. So there’s no need to 
    access status variable again and again after each iteration of loop. So the Compiler would convert this 
    loop to a infinite loop i.e. while (1) so that the Machine code to read status isn’t needed. Please note 
    that compiler isn’t aware of that status is a special variable which can be changed from outside the 
    current program at any point of time e.g. some IO operation happened on a peripheral device for which 
    device IO port was memory mapped to this variable. So in reality, we want compiler to access status 
    variable after every loop iteration even though it isn’t modified by our program which is being compiled 
    by Compiler.
    
    One can argue that we can turn-off all the compiler optimizations for such programs so that we don’t run 
    into this situation. This is not an option due to multiple reasons such as 
    A) Each compiler implementation is different so it’s not a portable solution 
    B) Just because of one variable, we don’t want to turn of all the other optimizations which compiler does 
    at other portions of our program. 
    C) By turning off all the optimizations, our low level program couldn’t work as expected e.g. too much 
    increase in size or delayed execution.
    
    That’s where “volatile” comes in picture. Basically, we need to instruct Compiler that status is special 
    variable so that no such optimization are allowed on this variable. With this, we would define our variable 
    as follows:
    
        volatile uint32 status = 0;

    For simplicity of explanation purpose, we choose the above example. But in general, volatile is used with 
    pointers such as follows:

        volatile uint32 * statusPtr = 0xF1230000

    Here, statusPtr is pointing to a memory location (e.g. for some IO port) at which the content can change 
    at any point of time from some peripheral device. Please note that our program might not have any control 
    or knowledge about when that memory would change. So we would make it “volatile” so that compiler doesn’t 
    perform optimization for the volatile variable which is pointed by statusPtr.

    In the context of our discussion about “volatile“, we quote C language standard i.e. ISO/IEC 9899 C11 – 
    clause 6.7.3 “An object that has volatile-qualified type may be modified in ways unknown to the implementation 
    or have other unknown side effects.” “A volatile declaration may be used to describe an object corresponding 
    to a memory-mapped input/output port or an object accessed by an asynchronously interrupting function. Actions 
    on objects so declared shall not be ‘‘optimized out’’ by an implementation or reordered except as permitted 
    by the rules for evaluating expressions.”

    Basically, C standard says that “volatile” variables can change from outside the program and that’s why 
    compilers aren’t supposed to optimize their access. Now, you can guess that having too many ‘volatile‘ variables 
    in your program would also result in lesser & lesser compiler optimization. We hope it gives you enough background 
    about meaning and purpose of “volatile”.
    From this article, we would like you to take-away the concept of “volatile variable –> don’t do compiler 
    optimization for that variable“!
    
    The following article explains volatile through more examples. 
    Understanding “volatile” qualifier in C | Set 2 (Examples)
    If you like GeeksforGeeks and would like to contribute, you can also write an article using write.geeksforgeeks.org or mail 
    your article to review-team@geeksforgeeks.org. See your article appearing on the GeeksforGeeks main page and help other Geeks.
    Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.


    Understanding “volatile” qualifier in C | Set 2 (Examples)
    Difficulty Level : Medium
    Last Updated : 17 Jun, 2022
    Read
    Discuss
    Practice
    Video
    Courses

    
    The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change 
    in ways that cannot be determined by the compiler. 

    Objects declared as volatile are omitted from optimization because their values can be changed by code outside the 
    scope of current code at any time. The system always reads the current value of a volatile object from the memory 
    location rather than keeping its value in a temporary register at the point it is requested, even if a previous 
    instruction asked for the value from the same object. So the simple question is, how can the value of a variable change 
    in such a way that the compiler cannot predict? Consider the following cases for an answer to this question: 

    1) Global variables modified by an interrupt service routine outside the scope: For example, a global variable can 
    represent a data port (usually a global pointer, referred to as memory mapped IO) which will be updated dynamically. 
    The code reading the data port must be declared as volatile in order to fetch the latest data available at the port. 
    Failing to declare the variable as volatile will result in the compiler optimizing the code in such a way that it will 
    read the port only once and keep using the same value in a temporary register to speed up the program (speed optimization). 
    In general, an ISR is used to update these data ports when there is an interrupt due to the availability of new data. 

    
    2) Global variables within a multi-threaded application: There are multiple ways for threads’ communication, viz., 
    message passing, shared memory, mail boxes, etc. A global variable is weak form of shared memory. When two threads are 
    sharing information via global variables, those variables need to be qualified with volatile. Since threads run asynchronously, 
    any update of global variables due to one thread should be fetched freshly by the other consumer thread. The compiler 
    can read the global variables and place them in temporary variables of the current thread context. To nullify the 
    effect of compiler optimizations, such global variables need to be qualified as volatile.


    If we do not use volatile qualifier, the following problems may arise: 
    1) Code may not work as expected when optimization is turned on. 
    2) Code may not work as expected when interrupts are enabled and used.

    Let us see an example to understand how compilers interpret volatile keyword. Consider the below code. We are changing 
    the value of a const object using a pointer and we are compiling code without optimization option. Hence the compiler 
    won’t do any optimization and will change the value of the const object.

    // Compile code without optimization option
    #include <stdio.h>
    int main(void)
    {
        const int local = 10;
        int *ptr = (int*) &local;
    
        printf("Initial value of local : %d \n", local);
    
        *ptr = 100;
    
        printf("Modified value of local: %d \n", local);
    
        return 0;
    }

    When we compile code with “–save-temps” option of gcc, it generates 3 output files:
    1) preprocessed code (having .i extension) 
    2) assembly code (having .s extension) and 
    3) object code (having .o extension). 

    We compiled code without optimization, that’s why the size of assembly code will be larger (which is highlighted in \
    red below).

    Output: 

    [narendra@ubuntu]$ gcc volatile.c -o volatile –save-temps
    [narendra@ubuntu]$ ./volatile
    Initial value of local : 10
    Modified value of local: 100
    [narendra@ubuntu]$ ls -l volatile.s
    -rw-r–r– 1 narendra narendra 731 2016-11-19 16:19 volatile.s
    [narendra@ubuntu]$
    Let us compile the same code with optimization option (i.e. -O option). In the below code, “local” is declared as const 
    (and non-volatile). The GCC compiler does optimization and ignores the instructions which try to change the value of 
    the const object. Hence the value of the const object remains same. 


    #include <stdio.h>
    
    int main(void)
    {
        const int local = 10;
        int *ptr = (int*) &local;
    
        printf("Initial value of local : %d \n", local);
    
        *ptr = 100;
    
        printf("Modified value of local: %d \n", local);
    
        return 0;
    }
    For the above code, the compiler does optimization, that’s why the size of assembly code will reduce.

    Output: 

    [narendra@ubuntu]$ gcc -O3 volatile.c -o volatile –save-temps
    [narendra@ubuntu]$ ./volatile
    Initial value of local : 10
    Modified value of local: 10
    [narendra@ubuntu]$ ls -l volatile.s
    -rw-r–r– 1 narendra narendra 626 2016-11-19 16:21 volatile.s
    Let us declare the const object as volatile and compile code with optimization option. Although we compile code with 
    optimization option, the value of the const object will change because the variable is declared as volatile which means, 
    don’t do any optimization. 

    Output: 

    [narendra@ubuntu]$ gcc -O3 volatile.c -o volatile –save-temp
    [narendra@ubuntu]$ ./volatile
    Initial value of local : 10
    Modified value of local: 100
    [narendra@ubuntu]$ ls -l volatile.s
    -rw-r–r– 1 narendra narendra 711 2016-11-19 16:22 volatile.s
    [narendra@ubuntu]$
    
    The above example may not be a good practical example, but the purpose was to explain how compilers interpret volatile 
    keyword. As a practical example, think of the touch sensor on mobile phones. The driver abstracting the touch sensor 
    will read the location of touch and send it to higher level applications. The driver itself should not modify (const-ness) 
    the read location, and make sure it reads the touch input every time fresh (volatile-ness). Such driver must read the 
    touch sensor input in const volatile manner.

    Note: The above codes are compiler specific and may not work on all compilers. The purpose of the examples is to make 
    readers understand the concept.
*/

/* Compile code with optimization option */
#include <stdio.h>
 
int main(void)
{
    const volatile int local = 10;
    int *ptr = (int*) &local;
 
    printf("Initial value of local : %d \n", local);
 
    *ptr = 100;
 
    printf("Modified value of local: %d \n", local);
 
    return 0;
}

// Initial value of local : 10 
// Modified value of local: 100 
