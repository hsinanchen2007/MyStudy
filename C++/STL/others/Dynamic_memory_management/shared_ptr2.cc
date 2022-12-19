/*
    From https://thispointer.com//learning-shared_ptr-part-1-usage-details/

    C++11 Smart Pointer – Part 1: shared_ptr Tutorial and Examples
    4 Comments / C++, C++ 11, shared_ptr, Smart Pointers / By Varun
    Best Courses to Learn C++11
    In this article we will discuss a smart pointer implementation provide by c++11 i.e. shared_ptr.


    What is std::shared_ptr<> ?
    shared_ptr is a kind of Smart Pointer class provided by c++11, that is smart enough to automatically delete the associated pointer when its not used anywhere. Thus helps us to completely remove the problem of memory leaks and dangling Pointers.

    shared_ptr and Shared Ownership
    It follows the concept of Shared Ownership i.e. different shared_ptr objects can be associated with same pointer and internally uses the reference counting mechanism to achieve this.

    Each shared_ptr object internally points to two memory locations,
    1.) Pointer to the object

    Advertisements

    2.) Pointer to control data that is used for reference counting

    How Shared Ownership works with the help of Reference Counting:
    When a new shared_ptr object is associated with a pointer,then in its constructor it increases the refernce count associated with this pointer by 1.
    When any shared_ptr object goes out of scope then in its destructor it decrements the reference count of the associated pointer by 1. If reference count becomes 0 then it means no other shared_ptr object is associated with this memory, in that case it deletes that memory using “delete” function.
    Creating a shared_ptr Object
    When we bind a shared_ptr object with raw pointer like,
    std::shared_ptr<int> p1(new int());

    In above line it allocates two memory on heap i.e.
    1.) For int.

    2.) A memory for Reference Counting that will be used to manage the count of shared_ptr objects attached with this memory. Initially it count will be 1.

    Checking reference Count of a shared_ptr object
    We can check that reference count with following function,
    p1.use_count();
    std::make_shared<T>
    How not to assign pointer to shared_ptr,
    //Compile Error
    std::shared_ptr<int> p1 = new int(); // Compile error

    Because shared_ptr constructor taking an argument is Explicit and in above line we are calling it implicitly. Best way to create a new shared_ptr object is using std::make_shared,
    std::shared_ptr<int> p1 = std::make_shared<int>();

    std::make_shared makes one memory allocation for both the object and data structure required for reference counting i.e. new operator will called only once.
    Detaching the associated Raw Pointer
    To make shared_ptr object de-attach its attached pointer call reset() method i.e.

    reset() function with no parameter:
    p1.reset();

    It decrease its reference count by 1 and if reference count becomes 0 then it deleted the pointer
    reset() function with parameter:
    p1.reset(new int(34));

    In this case it will point to new Pointer internally, hence its reference count will again become 1.
    Resetting Using nullptr:
    p1 = nullptr;

    set the shared_ptr object with nullptr.
    shared_ptr is a psuedo pointer
    shared_ptr acts as normal pointer i.e. we can use * and -> with shared_ptr object and can also compare it like other shared_ptr objects;

    Complete example is as follows
*/

#include <iostream>
#include  <memory> // We need to include this for shared_ptr

int main()
{
    // Creating a shared_ptr through make_shared
    std::shared_ptr<int> p1 = std::make_shared<int>();
    *p1 = 78;
    std::cout << "p1 = " << *p1 << std::endl;

    // Shows the reference count
    std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

    // Second shared_ptr object will also point to same pointer internally
    // It will make the reference count to 2.
    std::shared_ptr<int> p2(p1);

    // Shows the reference count
    std::cout << "p2 Reference count = " << p2.use_count() << std::endl;
    std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

    // Comparing smart pointers
    if (p1 == p2)
    {
        std::cout << "p1 and p2 are pointing to same pointer\n";
    }
    std::cout<<"Reset p1 "<<std::endl;
    p1.reset();

    // Reset the shared_ptr, in this case it will not point to any Pointer internally
    // hence its reference count will become 0.
    std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;

    // Reset the shared_ptr, in this case it will point to a new Pointer internally
    // hence its reference count will become 1.
    p1.reset(new int(11));
    std::cout << "p1  Reference Count = " << p1.use_count() << std::endl;

    // Assigning nullptr will de-attach the associated pointer and make it to point null
    p1 = nullptr;
    std::cout << "p1  Reference Count = " << p1.use_count() << std::endl;
    if (!p1)
    {
        std::cout << "p1 is NULL" << std::endl;
    }
    return 0;
}

// p1 = 78
// p1 Reference count = 1
// p2 Reference count = 2
// p1 Reference count = 2
// p1 and p2 are pointing to same pointer
// Reset p1 
// p1 Reference Count = 0
// p1  Reference Count = 1
// p1  Reference Count = 0
// p1 is NULL