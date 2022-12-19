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

https://en.cppreference.com/w/cpp/algorithm/partial_sort_copy

Sorts some of the elements in the range [first, last) in ascending order, storing the result in 
the range [d_first, d_last).

At most d_last - d_first of the elements are placed sorted to the range [d_first, d_first + n). 
n is the number of elements to sort (n = min(last - first, d_last - d_first)). The order of equal 
elements is not guaranteed to be preserved.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
an iterator to the element defining the upper boundary of the sorted range, i.e. 
d_first + min(last - first, d_last - d_first).

*/

int main()
{
    const auto v0 = {4, 2, 5, 1, 3};
    std::vector<int> v1{10, 11, 12};
    std::vector<int> v2{10, 11, 12, 13, 14, 15, 16};
    std::vector<int>::iterator it;
 
    // v1 vector size is smaller
    it = std::partial_sort_copy(v0.begin(), v0.end(), v1.begin(), v1.end());
 
    std::cout << "Writing to the smaller vector in ascending order gives: ";
    for (int a : v1) {
        std::cout << a << " ";
    }
    std::cout << '\n';
    if(it == v1.end())
        std::cout << "The return value is the end iterator\n";
 
    // v2 vector size is larger
    it = std::partial_sort_copy(v0.begin(), v0.end(), v2.begin(), v2.end(), 
                                std::greater<int>());
 
    std::cout << "Writing to the larger vector in descending order gives: ";
    for (int a : v2) {
        std::cout << a << " ";
    }
    std::cout << '\n' << "The return value is the iterator to " << *it << '\n';

    return 0;
    // Writing to the smaller vector in ascending order gives: 1 2 3 
    // The return value is the end iterator
    // Writing to the larger vector in descending order gives: 5 4 3 2 1 15 16 
    // The return value is the iterator to 15
}
