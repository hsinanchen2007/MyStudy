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

https://en.cppreference.com/w/cpp/algorithm/minmax_element

Finds the smallest and greatest element in the range [first, last).

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
a pair consisting of an iterator to the smallest element as the first element and an iterator to the 
greatest element as the second. Returns std::make_pair(first, first) if the range is empty. If several 
elements are equivalent to the smallest element, the iterator to the first such element is returned. 
If several elements are equivalent to the largest element, the iterator to the last such element is 
returned.

*/

int main()
{
    const auto v = { 3, 9, 1, 4, 2, 5, 9 };
    const auto [min, max] = std::minmax_element(begin(v), end(v));
 
    std::cout << "min = " << *min << ", max = " << *max << '\n';

    return 0;
    // min = 1, max = 9
}
