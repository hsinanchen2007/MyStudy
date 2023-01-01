/*
    From https://www.oreilly.com/library/view/c-cookbook/0596007612/ch15s02.html

    Problem
    You plan to call some function func1, and at runtime you need it to invoke another function func2. 
    For one reason or another, however, you cannot simply hardcode the name of func2 within func1. 
    func2 may not be known definitively at compile time, or perhaps func1 belongs to a third-party API 
    that you can’t change and recompile. In either case, you need a callback function.

    Solution
    In the case of the functions above, declare func1 to take a pointer to a function, and pass it the 
    address of func2 at runtime. Use a typedef to make the messy syntax easier to read and debug. 
    Example 15-1 shows how to implement a callback function with a function pointer.

    Example 15-1. A callback function

    #include <iostream>

    // An example of a callback function
    bool updateProgress(int pct) {
    
    std::cout << pct << "% complete...\n";
    return(true);
    }

    // A typedef to make for easier reading
    typedef bool (*FuncPtrBoolInt)(int);

    // A function that runs for a while
    void longOperation(FuncPtrBoolInt f) {

    for (long l = 0; l < 100000000; l++)
        if (l % 10000000 == 0)
            f(l / 1000000);
    }

    int main() {

    longOperation(updateProgress); // ok
    }
    Discussion
    In a situation such as that shown in Example 15-1, a function pointer is a good idea if updateProgress 
    and longOperation shouldn’t know anything about each other. For example, a function that updates the progress 
    by displaying it to the user—either in a user interface (UI) dialog box, in a console window, or somewhere 
    else—does ...
*/

// some often common headers and namespace
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

// An example of a callback function
bool updateProgress(int pct) {
  
   std::cout << pct << "% complete...\n";
   return(true);
}

// A typedef to make for easier reading
typedef bool (*FuncPtrBoolInt)(int);

// A function that runs for a while
void longOperation(FuncPtrBoolInt f) {

   for (long l = 0; l < 100000000; l++)
      if (l % 10000000 == 0)
         f(l / 1000000);
}

int main() {
   longOperation(updateProgress); // ok
}

// 0% complete...
// 10% complete...
// 20% complete...
// 30% complete...
// 40% complete...
// 50% complete...
// 60% complete...
// 70% complete...
// 80% complete...
// 90% complete...


