/*
    From https://blog.mbedded.ninja/programming/languages/c-plus-plus/callbacks/
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

    // Alternate way to using a lambda, use std::bind instead. However I recommend the lambda way.
    libraryClass.passACallbackToMe(std::bind(&MyClass::methodToCallback, myClass, std::placeholders::_1, std::placeholders::_2));
}

// Value: 3
