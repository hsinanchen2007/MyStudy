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

https://en.cppreference.com/w/cpp/algorithm/for_each_n

1) Applies the given function object f to the result of dereferencing every iterator in the range 
[first, first + n), in order.
2) Applies the given function object f to the result of dereferencing every iterator in the range 
[first, first + n) (not necessarily in order). The algorithm is executed according to policy. 
This overload does not participate in overload resolution unless 
std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

For both overloads, if the iterator type is mutable, f may modify the elements of the range through 
the dereferenced iterator. If f returns a result, the result is ignored. If n is less than zero, 
the behavior is undefined.

Unlike the rest of the parallel algorithms, for_each_n is not allowed to make copies of the elements 
in the sequence even if they are trivially copyable.

*/

int main()
{
    vector<int> myV = {1, 3, 5, 7, 9, 10};

    // from the myV, the first 3 items including myV.begin(), will * 2
    // the rest after first 3 item will remain same, no *2
    // the given function f is the lambdas function that performs * 2 operation
    for_each_n(myV.begin(), 3, [](int value) { value = value * 2;})

    for (int i : myV) {
        cout << i << endl;
    }

    // 2022.7.31
    // Need C++ 17 or above to compile
    // Note: The return value
    // An iterator equal to first + n, or more formally, to std::advance(first, n).
    
    return 0;
}