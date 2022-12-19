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

https://en.cppreference.com/w/cpp/algorithm/is_heap

Checks whether the elements in range [first, last) are a max heap.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
true if the range is max heap, false otherwise.

*/

int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9 };
 
    std::cout << "initially, v:\n";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    // check if the given vector is a max heap or not
    if (!std::is_heap(v.begin(), v.end()) && 
        !std::is_heap(v.rbegin(), v.rend())) {
        std::cout << "making heap...\n";
        // build up a heap
        std::make_heap(v.begin(), v.end());
    }
 
    std::cout << "after make_heap, v:\n";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    return 0;
    // initially, v:
    // 3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 
    // making heap...
    // after make_heap, v:
    // 9 6 9 5 5 9 7 1 1 3 5 8 3 4 2 
}
