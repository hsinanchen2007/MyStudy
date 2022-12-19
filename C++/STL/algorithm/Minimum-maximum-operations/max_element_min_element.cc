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

https://en.cppreference.com/w/cpp/algorithm/max_element

Finds the greatest element in the range [first, last).

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator to the greatest element in the range [first, last). If several elements in the range are equivalent 
to the greatest element, returns the iterator to the first such element. Returns last if the range is empty.


https://en.cppreference.com/w/cpp/algorithm/min_element

Finds the smallest element in the range [first, last).

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator to the smallest element in the range [first, last). If several elements in the range are equivalent 
to the smallest element, returns the iterator to the first such element. Returns last if the range is empty.

*/

static bool abs_compare(int a, int b)
{
    return (std::abs(a) < std::abs(b));
}

int main()
{
    std::vector<int> v{ 3, 1, -14, 1, 5, 9 }; 
    std::vector<int>::iterator result;
 
    // regular max_element which check the original values
    result = std::max_element(v.begin(), v.end());
    std::cout << "max element at index : " << std::distance(v.begin(), result) << " value " << *result << '\n';
 
    // use abs_compare() to check absolute values
    result = std::max_element(v.begin(), v.end(), abs_compare);
    std::cout << "max element (absolute) at index : " << std::distance(v.begin(), result) << " value " << *result << '\n';

    // regular min_element which check the original values
    result = std::min_element(v.begin(), v.end());
    std::cout << "min element at index : " << std::distance(v.begin(), result) << " value " << *result << '\n';
 
    // use abs_compare() to check absolute values
    result = std::min_element(v.begin(), v.end(), abs_compare);
    std::cout << "min element (absolute) at index : " << std::distance(v.begin(), result) << " value " << *result << '\n';

    return 0;
    // max element at index : 5 value 9
    // max element (absolute) at index : 2 value -14
    // min element at index : 2 value -14
    // min element (absolute) at index : 1 value 1
}
