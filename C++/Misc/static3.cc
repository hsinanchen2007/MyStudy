/*
    Class objects as static: Just like variables, objects also when declared as static have a scope 
    till the lifetime of program. Consider the below program where the object is non-static.

    // CPP program to illustrate
    // when not using static keyword
    #include<iostream>
    using namespace std;
    
    class GfG
    {
        int i;
        public:
            GfG()
            {
                i = 0;
                cout << "Inside Constructor\n";
            }
            ~GfG()
            {
                cout << "Inside Destructor\n";
            }
    };
    
    int main()
    {
        int x = 0;
        if (x==0)
        {
            GfG obj;
        }
        cout << "End of main\n";
    }
    Output:

    Inside Constructor
    Inside Destructor
    End of main

    In the above program the object is declared inside the if block as non-static. So, the scope of variable 
    is inside the if block only. So when the object is created the constructor is invoked and soon as the control 
    of if block gets over the destructor is invoked as the scope of object is inside the if block only where 
    it is declared.
    
    Let us now see the change in output if we declare the object as static.
*/

// CPP program to illustrate
// class objects as static
#include<iostream>
using namespace std;
  
class GfG
{
    int i = 0;
      
    public:
    GfG()
    {
        i = 0;
        cout << "Inside Constructor\n";
    }
      
    ~GfG()
    {
        cout << "Inside Destructor\n";
    }
};
  
int main()
{
    int x = 0;
    if (x==0)
    {
        // this class is delcared as static, so it will remain until the program ends, not after existing the {}
        static GfG obj;
    }
    cout << "End of main\n";
}

// Inside Constructor
// End of main
// Inside Destructor
