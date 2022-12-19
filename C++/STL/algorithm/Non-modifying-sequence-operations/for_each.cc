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
#include <iterator>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/for_each


1) Applies the given function object f to the result of dereferencing every iterator in the range [first, last), in order.
2) Applies the given function object f to the result of dereferencing every iterator in the range [first, last) 
(not necessarily in order). The algorithm is executed according to policy. This overload does not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

For both overloads, if the iterator type is mutable, f may modify the elements of the range through the dereferenced iterator. 
If f returns a result, the result is ignored.

Unlike the rest of the parallel algorithms, for_each is not allowed to make copies of the elements in the sequence even 
if they are trivially copyable.

*/

int result = 0;

int main()
{
    vector<int> myV = {1, 3, 5, 7, 9};    
    int another_result = 0;

    // a simple template way to define a lambdas function and allow variables from outside
    auto myFunc = [&another_result](int value) { another_result = another_result + value; };

    // use for_each() to sum up all values in the given vector, result is from global variable
    // lambdas function has no name
    for_each(myV.begin(), myV.end(), [](int value) { result = result + value; });
    cout << "Result1 of sum is " << result << endl;

    // use for_each() to sum up all values in the given vector, result is from lambdas capture way
    // where we define a local variable and pass it by reference to myFunc
    for_each(myV.begin(), myV.end(), myFunc);
    cout << "Result2 of sum is " << another_result << endl;

    // a simple template way to define a lambdas function and allow variables from outside
    // here we don't specify the variable name, but just use reference &, we will continue
    // adding sum into another_result
    auto myFunc2 = [&](int value) { another_result = another_result + value; };
    for_each(myV.begin(), myV.end(), myFunc2);
    cout << "Result3 of sum is " << another_result << endl;

    // another way to use lambdas function
    auto myFunc3([&](int value) { another_result = another_result + value; });
    for_each(myV.begin(), myV.end(), myFunc3);
    cout << "Result4 of sum is " << another_result << endl;

    // define a local variable used by lambdas function, initializes it 0, and return its sum 
    // every time it is called. Note that "myResult" cannot be defined by int or auto here
    // inside lambdas function
    for_each(myV.begin(), myV.end(), [myResult = 0](int value) mutable { 
        myResult = myResult + value; cout << "Result5 of sum now is " << myResult << endl; });

    return 0;
    // Result1 of sum is 25
    // Result2 of sum is 25
    // Result3 of sum is 50
    // Result4 of sum is 75
    // Result5 of sum now is 1
    // Result5 of sum now is 4
    // Result5 of sum now is 9
    // Result5 of sum now is 16
    // Result5 of sum now is 25
}
