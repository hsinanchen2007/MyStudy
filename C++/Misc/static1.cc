/*
    Static keyword has different meanings when used with different types. 

    We can use static keyword with:
        Static Variables : Variables in a function, Variables in a class
        Static Members of Class : Class objects and Functions in a class

    Let us now look at each one of these use of static in details:

    Static Variables

    Static variables in a Function: When a variable is declared as static, space for it gets allocated for the 
    lifetime of the program. Even if the function is called multiple times, space for the static variable is 
    allocated only once and the value of variable in the previous call gets carried through the next function 
    call. This is useful for implementing coroutines in C/C++ or any other application where previous state of 
    function needs to be stored.
*/

// C++ program to demonstrate 
// the use of static Static 
// variables in a Function
#include <iostream>
#include <string>
using namespace std;
  
void demo()
{ 
    // static variable
    static int count = 0;
    cout << count << " ";
      
    // value is updated and
    // will be carried to next
    // function calls
    count++;
}
  
int main()
{
    for (int i=0; i<5; i++)    
        demo();
    return 0;
}

// 0 1 2 3 4
