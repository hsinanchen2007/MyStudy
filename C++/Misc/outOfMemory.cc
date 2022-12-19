#include<iostream>
#include <cstdlib>
#include<new>

void out_of_memory()
{
    std::cout<<"Out of Memory :: Handler \n";
    // If not able to make memory available then exit else return.
    std::exit (1);
}

int main()
{
    // by try {} catch (...) {...} 
#if 0
    try
    {
        // Keep allocating memory dynamically on heap
        // in a cycle till new throws an exception
        while(true)
        {
            int * ptr = new int[10000000];
        }
    }
    catch (std::bad_alloc& excepObj)
    {
        std::cout << "bad_alloc Exception :: OUt Of Memory " << excepObj.what() << '\n';
    }
#endif

    // By using new handler
    std::set_new_handler(out_of_memory);

    while(true)
    {
        int * ptr = new int[10000000];
    }

    return 0;
}