/*
    From https://thispointer.com//difference-between-a-pointer-and-reference/

    Differences between a pointer and reference
    Leave a Comment / C++, C++ Interview Questions, pointers / By Varun
    Best Courses to Learn C++11
    Differences Between Pointer and Reference in C++ are as follows,


    1.) Reference is a kind of const pointer that de-reference itself automatically. 
    Yes, its similar to const pointer therefore once you have attached a reference to a 
    variable or object then you cannot make it to point to someone else.

    Now if you try to point the already initialized reference to an another variable 
    then reference will not change its reference point, this kind of assignment will 
    only change the value of variable to which reference was pointing.

    [showads ad=inside_post]

    Where as, you can change the value of a pointer i.e. at run time you can force a 
    pointer to point to new memory location.

    Let’s understand by example,

    2.)  Its must to initialize a reference while declaration i.e. Where as, you can 
    declare a pointer without initializing it. Therefore, you can also assign a NULL to 
    pointer. Where as, its not possible with a Reference.

    int abc = 7;
    int & ref = abc; // Correct
    int & y; // Wrong , won't compile
    int * ptr ; // Correct
    ptr = NULL; // Correct
    ref = NULL; // Wrong Won't compile
    3.)  You cann’t have reference of reference, where as you can have pointer to pointer.

    4.)  You can increment and decrement the value of a pointer and can use it for random 
    indexing i.e.

    int * ptr = new int[5];
    *(ptr + 2) = 7;
    But it’s not possible with reference.

    5.)  If you take the address of a reference then it will be similar to the address of 
    cariable to which it is pointing. Where as, in case of pointer it is different.

    6.)  With pointers there is always a risk and extra effort to delete it if allocated on 
    heap. There can be problems like memory leak and dangling pointers. Whereas, in case of 
    references it’s cool i.e. you don’t need to worry about problems like these.
*/

#include <iostream>

int main()
{
    int first = 10;
    int sec = 5;

    // Make Reference ref_1 to point towards variable first.
    int & ref_1 = first;
    std::cout<<"first = "<<first<<std::endl;
    std::cout<<"sec = "<<sec<<std::endl;
    std::cout<<"ref_1 = "<<ref_1<<std::endl;

    // Now if you try to point the reference ref_1 to an another variable i.e. sec
    // then reference will not change its reference point, this kind of assignment
    // will only change the value of variable to which refernce was pointing.
    ref_1 = sec;
    std::cout<<"After changing the ref_1 value"<<std::endl;
    std::cout<<"first = "<<first<<std::endl;
    std::cout<<"sec = "<<sec<<std::endl;
    std::cout<<"ref_1 = "<<ref_1<<std::endl;

    int * ptr = &first;
    std::cout<<"ptr = "<<ptr<<" :: *ptr = "<<(*ptr)<<std::endl;
    sec = 9;
    ptr = &sec;
    std::cout<<"ptr = "<<ptr<<" :: *ptr = "<<(*ptr)<<std::endl;
        
    return 0;
}

// first = 10
// sec = 5
// ref_1 = 10
// After changing the ref_1 value
// first = 5
// sec = 5
// ref_1 = 5
// ptr = 0x7fffa15d16fc :: *ptr = 5
// ptr = 0x7fffa15d16f8 :: *ptr = 9
