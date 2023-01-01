/*
    Static variables in a class: As the variables declared as static are initialized only once as 
    they are allocated space in separate static storage so, the static variables in a class are shared 
    by the objects. There can not be multiple copies of same static variables for different objects. 
    Also because of this reason static variables can not be initialized using constructors.
*/

// C++ program to demonstrate static
// variables inside a class
#include<iostream>
using namespace std;
  
class GfG
{
   public:
     static int i;
      
     GfG()
     {
        // Do nothing
     };
};

// note, this libe below is needed as the static variable is shared by multiple objects (instances) of
// this class, and static variable cannot be initialized at constructor. Also, when it is being initialized
// outside class, it doesn't have "static" keyword again but with "className::staticVariable"
int GfG::i = 1;

int main()
{
  GfG obj1;
  GfG obj2;
  obj1.i = 2;
  obj2.i = 3;
    
  // prints value of i
  // here, it will print 3 as last assignment is set to 3, and this static variable shared by instances
  // will be set to 3 cross all class instances
  cout << obj1.i<<" "<<obj2.i;   
}

// 3 3
