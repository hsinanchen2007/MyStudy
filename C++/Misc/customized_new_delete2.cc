/*
    From https://thispointer.com/overloading-new-and-delete-operators-at-global-and-class-level/

    We need to overload new[] and delete[] along with new & delete to keep dynamic allocation of 
    arrays in synch with other objects.

    Now as we can see it overloaded the new and delete operator at global level therefore every 
    object created on heap through new operator was created by our custom overloaded operator. 
    But suppose we want to overload new and delete for a specific class only then how to do it?

    Overloading new and delete for a specific Class
*/

#include <iostream>
#include <cstdlib>

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
  // Overloading CLass specific new operator
  static void* operator new(size_t sz)
  {
    void* m = malloc(sz);
    std::cout<<"Dummy :: Operator new"<<std::endl;
    return m;
  }
  // Overloading CLass specific delete operator
  static void operator delete(void* m)
  {
    std::cout<<"Dummy :: Operator delete"<<std::endl;
    free(m);
  }
};

int main()
{
  int * ptr = new int;
  delete ptr;
  Dummy * dummyPtr = new Dummy;
  delete dummyPtr;
  return 0;
}

// Dummy :: Operator new
// Dummy :: Constructor
// Dummy :: Destructor
// Dummy :: Operator delete

