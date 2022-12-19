/*
    From https://blog.mbedded.ninja/programming/languages/c-plus-plus/callbacks/

    If you have authorship of the library wanting to callback, then you can do even better than 
    described above. What I would recommend here is to change the signature away from a C-style 
    callback and use std::function and lambdas instead. Rather than the library accepting a C-style 
    callback in the format int (callback*) (int num1, int num2), update the library to accept a 
    std::function<int(int, int)> callback. This allows you to pass in a lambda, which as you’ll 
    see below, allows you to easily call a member function.
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

class LibraryClass {
public:
	void passACallbackToMe(std::function<int(int, int)> callback) {
	    // Now invoke (call) the callback
		int o = callback(1, 2);
        printf("Value: %i\n", o); // We might be on an embedded system, use printf() and not std::cout
	}
};

class MyClass {
public:
      int methodToCallback(int num1, int num2) {
          return num1 + num2;
      }
};

int main()
{
    MyClass myClass;
    
    LibraryClass libraryClass;

    // Use a lambda to capture myClass and call the member method
    libraryClass.passACallbackToMe([&myClass](int num1, int num2) -> int {
        return myClass.methodToCallback(num1, num2);
    });
}

// Value: 3
