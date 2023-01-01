/*
    3) It is undefined behavior to modify a value which is initially declared as const. 
    Consider the following program. The output of the program is undefined. The variable 
    ‘val’ is a const variable and the call ‘fun(ptr1)’ tries to modify ‘val’ using 
    const_cast.

    #include <iostream>

    using namespace std;
    
    int fun(int* ptr)
    {
        *ptr = *ptr + 10;
        return (*ptr);
    }
    
    int main(void)
    {
        const int val = 10;
        const int *ptr = &val;
        int *ptr1 = const_cast <int *>(ptr);
        fun(ptr1);
        cout << val;

        return 0;
    }

    // 10
*/

#include <iostream>

using namespace std;
  
int fun(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}
  
int main(void)
{
    int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast <int *>(ptr);
    fun(ptr1);
    cout << val;

    return 0;
}

// 20
