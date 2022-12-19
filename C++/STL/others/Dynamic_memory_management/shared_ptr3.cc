/*
    From https://thispointer.com//shared_ptr-and-custom-deletor/

    C++11 Smart Pointer – Part 2: shared_ptr and Custom Deletor
    2 Comments / C++, C++ 11, shared_ptr, Smart Pointers / By Varun
    In this article we will discuss how to use custom deleter with std::shared_ptr.


    When a shared_ptr object goes out of scope, its destructor is called. Inside its destructor it decrements the reference count by 1 and if new value of reference count is 0 then it deletes the associated raw pointer.

    To delete the internal raw pointer in destructor, by default shared_ptr calls the delete() function i.e.
    delete Pointer;

    But its not always that we want to use delete function in destruction, there can be other requirements too like,
    If shared_ptr object points to an array instead of a simple pointer,
    std::shared_ptr<int> p3(new int[12]);

    In its destructor shared_ptr will try to delete the int array i.e. int [] by calling
    delete

    function, whereas as correct way is using
    delete []
    Advertisements



    Adding custom deleter to shared_ptr<>
    In such case we can pass a callback to shared_ptr’s constructor, that will be called from its destructor for deletion i.e.

    Custom Deleter as function Pointer
    // function that calls the delete [] on received pointer
    void deleter(Sample * x)
    {
        std::cout << "DELETER FUNCTION CALLED\n";
        delete[] x;
    }

    Pass the function pointer in constructor of shared_ptr to provide custom deleter i.e.
    // Creating a shared+ptr with custom deleter
    std::shared_ptr<Sample> p3(new Sample[12], deleter);

    Check complete example as follows
*/

#include <iostream>
#include <memory>

struct Sample
{
    Sample()
    {
        std::cout << "CONSTRUCTOR\n";
    }
    ~Sample()
    {
        std::cout << "DESTRUCTOR\n";
    }
};

// function that calls the delete [] on received pointer
void deleter(Sample * x)
{
    std::cout << "DELETER FUNCTION CALLED\n";
    delete [] x;
}

int main()
{
    // Creating a shared+ptr with custom deleter
    std::shared_ptr<Sample> p3(new Sample[12], deleter);
    return 0;
}

// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// CONSTRUCTOR
// DELETER FUNCTION CALLED
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
// DESTRUCTOR
