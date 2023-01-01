/*
    From https://thispointer.com/overloading-new-and-delete-operators-at-global-and-class-level/

    Overloading new and delete operators at Global and Class level
    Leave a Comment / C++, C++ Interview Questions / By Varun
    Best Courses to Learn C++11
    In this article we will discuss why we should overload new and delete operator and how to do it.


    When we create a new Object on heap by calling new operator then it does following things internally,

    First it allocates the required memory by calling operator new i.e. operator new returns the pointer 
    top memory.
    
    Afterwards, it initializes that memory by calling the constructor of the specified Type.
    Similarly when we delete the dynamically allocated memory it does following steps internally,

    First it de initializes the memory by calling Destructor of the specified Type
    Afterwards, it removes the allocated memory by calling operator delete.
    Now, suppose a new requirement comes i.e. new/delete operator to do some special stuff while allocating 
    memory i.e.

    Advertisements



    1.) Instead of allocating raw memory from heap every time, use memory from a memory pool i.e. fetch memory 
    from a memory pool and return it after usage
    2.) Do some logging, book keeping and decision making while allocating and deallocating memory like, keeping 
    track of how much memory has been used etc.
    3.)etc

    To achieve this above requirement, we need to overload new and delete operator. Lets see how to do oveload them,

    Overloading new and delete at global level
*/

#include <iostream>
#include <cstdlib>

// Overloading Global new operator
void* operator new(size_t sz)
{
  void* m = malloc(sz);
  std::cout<<"User Defined :: Operator new"<<std::endl;
  
  return m;
}

// Overloading Global delete operator
void operator delete(void* m)
{
  std::cout<<"User Defined :: Operator delete"<<std::endl;
  free(m);
}

// Overloading Global new[] operator
void* operator new[](size_t sz)
{
  std::cout<<"User Defined :: Operator new []"<<std::endl;
  void* m = malloc(sz);
  return m;
}

// Overloading Global delete[] operator
void operator delete[](void* m)
{
  std::cout<<"User Defined :: Operator delete[]"<<std::endl;
  free(m);
}

class Dummy
{
public:
  Dummy()
  {
    std::cout<<"Dummy :: Constructor"<<std::endl;
  }
  ~Dummy()
  {
    std::cout<<"Dummy :: Destructor"<<std::endl;
  }
};

int main()
{
  int * ptr = new int;
  delete ptr;

  Dummy * dummyPtr = new Dummy;
  delete dummyPtr;

  int * ptrArr = new int[5];
  delete [] ptrArr;

  return 0;
}

// User Defined :: Operator new
// User Defined :: Operator delete
// User Defined :: Operator new
// Dummy :: Constructor
// Dummy :: Destructor
// User Defined :: Operator delete
// User Defined :: Operator new []
// User Defined :: Operator delete[]

