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

https://en.cppreference.com/w/cpp/algorithm/set_union

Constructs a sorted union beginning at d_first consisting of the set of elements present in one or both 
sorted ranges [first1, last1) and [first2, last2).

If some element is found m times in [first1, last1) and n times in [first2, last2), then all m elements 
will be copied from [first1, last1) to d_first, preserving order, and then exactly std::max(n-m, 0) 
elements will be copied from [first2, last2) to d_first, also preserving order.

The resulting range cannot overlap with either of the input ranges.

1) Elements are compared using operator< and the ranges must be sorted with respect to the same.
3) Elements are compared using the given binary comparison function comp and the ranges must be sorted 
with respect to the same.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator past the end of the constructed range.

*/

int main()
{
    {
        // each range has no duplicated elements
        std::vector<int> v1 = {1, 2, 3, 4, 5}; 
        std::vector<int> v2 = {      3, 4, 5, 6, 7}; 
        std::vector<int> dest1;
 
        std::set_union(v1.begin(), v1.end(),
                       v2.begin(), v2.end(),                  
                       std::back_inserter(dest1));
 
        for (const auto &i : dest1) {
            std::cout << i << ' ';
        }   
        std::cout << '\n';
    }
    {
        // range with duplicated elements, it will include duplicated ones 
        // into new range, so for this case, additional two 5 will be included 
        std::vector<int> v1 = {1, 2, 3, 4, 5, 5, 5}; 
        std::vector<int> v2 = {      3, 4, 5, 6, 7}; 
        std::vector<int> dest1;
 
        std::set_union(v1.begin(), v1.end(),
                       v2.begin(), v2.end(),                  
                       std::back_inserter(dest1));
 
        for (const auto &i : dest1) {
            std::cout << i << ' ';
        }   
        std::cout << '\n';
    }

    return 0;
    // 1 2 3 4 5 6 7 
    // 1 2 3 4 5 5 5 6 7
}