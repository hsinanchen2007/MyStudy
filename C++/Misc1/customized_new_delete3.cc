/*
    From https://thispointer.com/restrict-dynamic-deletion-of-objects-created-on-stack/

    Restrict dynamic deletion of objects created on stack

    Many times we encounter a situation where we need to delete a pointer but we are not 
    sure that how this pointer is created i.e. either on Heap or on stack.

    Check out this function,
    class Dummy;
    void deletePointer(Dummy * ptr)
    {
        // Do you know this passed pointer was
        // created on heap or stack ???
        delete ptr;
    }

    In this it’s receiving a pointer and deleting it. But wait a minute….
    What is this passed pointer is created on stack instead of heap ?
    i.e.
    Dummy obj;
    Dummy * dPtr = &obj;
    deletePointer(dPtr);

    BOOM………….
    In this type of case our application will crash.
    Can we do something about it? Can we add a restriction in my class, so that pointer of 
    object created on Stack can not be deleted dynamically i.e. by delete operator?

    Yes we can do this.

    Adding restriction on deletion of objects created on stack through delete operator
    Mark each object created on heap and for other objects this marking will return false.

    For this we will require following items in our class

    Each Object will contain a member variable that will tell that current object is created 
    on heap or not.
    A static member variable in class that we will set in new operator and constructor
    How This will work,

    Each time we create an object on heap first operator new is called to allocate the memory 
    and then its constructor is called. So, overload the new operator and add mark that new operator 
    is called. Then in constructor check if new opeartor mark is true it means the current object 
    is created on heap, so just update a member variable i.e. Heap marking for this current object. 
    Afterwards reset the new operator Mask.

    [showads ad=inside_post]

    Now we have a member function that can tell if current object is created on heap or not.

    Now overload the delete operator and before calling global operator on passed pointer check 
    if it was created on heap or not.

    Checkout following example.
*/

#include <iostream>
#include <cstdlib>
#include <new>
class Dummy
{
    // Track the last call of new operator
    static bool m_islastCallOnHeap;

    // Tells if current object is created on
    // Heap or not
    bool m_isOnHeap;
public:
    Dummy()
    {
        // Set the Heap flag for current Object
        m_isOnHeap = m_islastCallOnHeap;
        // reset the last call mark of new operator
        m_islastCallOnHeap = false;
    }

    static void* operator new(size_t sz)
    {
        std::cout << "operator new called\n"; // Current Object will be created on heap
        m_islastCallOnHeap = true; // Call the global new operator
        return ::operator new(sz);
    }

    static void operator delete(void* ptr)
    {
        Dummy * resPtr = (Dummy *) (ptr);
        // Before deleting check if passed object pointer
        // was created on heap or not.
        if (resPtr->m_isOnHeap)
        {
            ::operator delete(ptr);
            std::cout << "delete successful\n";
        }
        else
            std::cout
                    << "Sorry Dude.. This Object is not allocated from Heap\n";
    }

    bool isOnHeap()
    {
        return m_isOnHeap;
    }
};

bool Dummy::m_islastCallOnHeap = false;

int main()
{
    Dummy resObj;
    Dummy * resPtr_2 = &resObj;

    // Deleting the Object created on Stack
    // through delete operator
    delete resPtr_2;

    // normal call by calling new and delete same object
    Dummy *anotherObj = new Dummy();
    delete anotherObj;

    return 0;
}

// Sorry Dude.. This Object is not allocated from Heap
// operator new called
// delete successful
