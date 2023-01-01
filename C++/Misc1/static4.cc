/*
    Static functions in a class: Just like the static data members or static variables inside the class, 
    static member functions also does not depend on object of class. We are allowed to invoke a static 
    member function using the object and the ‘.’ operator but it is recommended to invoke the static members 
    using the class name and the scope resolution operator.

    Static member functions are allowed to access only the static data members or other static member 
    functions, they can not access the non-static data members or member functions of the class.
*/

// C++ program to demonstrate static
// member function in a class
#include<iostream>
using namespace std;
  
class GfG
{
   public:
      
    // static member function
    static void printMsg()
    {
        cout<<"Welcome to GfG!";
    }
};
  
// main function
int main()
{
    // invoking a static member function
    GfG::printMsg();
}

// Welcome to GfG!
