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

https://en.cppreference.com/w/cpp/algorithm/is_heap_until

Examines the range [first, last) and finds the largest range beginning at first which is a max heap.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
The upper bound of the largest range beginning at first which is a max heap. That is, the last iterator 
it for which range [first, it) is a max heap.

*/

int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    // build up heap
    std::make_heap(v.begin(), v.end());
 
    // probably mess up the heap
    v.push_back(2);
    v.push_back(6);
 
    // check the heap until the iterator
    // note that this is one important function in heap operation,
    // as it can distinguish the range of heap and normal vector
    // for example, push_heap()/pop_heap() will add last/move first
    // elements into/from heap
    auto heap_end = std::is_heap_until(v.begin(), v.end());
 
    std::cout << "all of v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    std::cout << "only heap: ";
    for (auto i = v.begin(); i != heap_end; ++i) std::cout << *i << ' ';
    std::cout << '\n';

    return 0;
    // all of v: 9 5 4 1 1 3 2 6 
    // only heap: 9 5 4 1 1 3 2 
}
