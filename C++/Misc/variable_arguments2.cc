/*
    From https://thispointer.com//how-to-pass-variable-arguments-in-a-function/

    How to pass variable arguments in a function
    Leave a Comment / C++ Interview Questions, Variable Arguments / By Varun
    In this article we will discuss how to pass variable number of arguments in a function.

    Requirement:

    Suppose I want to create a function that take variable number of arguments and 
    use them to perform some task.

    For example,
    Create a function that will return the sum of all the passed arguments i.e.
    findSum(3,1,4,2);
    //Here first argument represents the number of arguments passed after the first arguments.
    //This function will return 7
    findSum(5,7,8,2,1,0);
    //Here first argument represents the number of arguments passed after the first arguments.
    //This function will return 18

    As you can see in above example in function findAll() we have passes different number of 
    arguments in same program and it used them to show the result.
    So, we need to create a function that can accept variable number of arguments and use them.
    Advertisements

    Now lets see how to implement this functionality

    Declaring a function that can accept variable arguments
    int findSum(int noOfElements, ...);

    Here … is “ellipsis”, which represents variable number of arguments.
    Imp Points:
    First agrument is neccasary in a function that accepts variable list of arguments.
    Also variable number of arguments represented by … (ellipsis) should be the last argument 
    in a function.

    Reading Variable Arguments inside a function
    Create a list of variable arguments using va_list i.e.
    va_list varList;

    Now initialize the list using va_start() i.e.
    va_start( varList, noOfElements );

    Here first agrument is the list of type va_list and second argument is argument that is 
    passed just before the “…” in function. This function va_start() initializes the va_list.
    Now to read the first entry from this va_list use va_arg() function i.e.
    int x = va_arg(varList, int);

    This function accepts the va_list and type of argument as argument and return the next entry 
    in list.
    We will iterate through all the variable arguments passed in the function by calling this function 
    in a loop.
    But how do we know, how many elements is passed in this variable list?

    For this we will use the first argument passed i.e. noOfElements. User will the count of arguments 
    in this argument i.e.
    findSum(5,7,8,2,1,0);
    // 5 Here represents that next 5 arguments are in variable argument list.

    Now lets iterate over the variable argument list
    int sum = 0;
    for(int i = 0; i < numOfElements; i++)
    {
    int x = va_arg(varList, int);
    sum = sum + x;
    }

    In the end we need to clean up this variable argument list i.e.
    va_end ( varList );

    va_list, va_start, va_arg, va_end are defined in header file <stdarg.h>
    How this variable argument stuff works internally
    Whenever we pass some argument in a function, all the arguments are stored in a stack and if we know 
    the address of starting point of variable argument then we can easily fetch the next value.
    Therefore in va_start we need to pass the argument that jus preceds the variable arguments, so that 
    it can fetch the calculate the starting address of variable arg list.
    Then in va_arg we need to pass the type of next argument, so that it can fetch that bytes only to create 
    the argument.

    Complete example is as follows,
*/

#include <iostream>
#include <stdarg.h>

void findSum(int numOfElements, ...)
{
    va_list varList;
    va_start(varList, numOfElements);
    int sum = 0;

    for(int i = 0; i < numOfElements; i++)
    {
        int x = va_arg(varList, int);
        sum = sum + x;
    }
    std::cout<<"Sum = "<<sum<<std::endl;
    
    va_end ( varList );
}

int main()
{
    findSum(3,1,4,2);
    findSum(5,7,8,2,1,0);
    return 0;
}

// Sum = 7
// Sum = 18
