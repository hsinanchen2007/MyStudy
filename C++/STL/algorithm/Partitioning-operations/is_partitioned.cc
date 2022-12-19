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

https://en.cppreference.com/w/cpp/algorithm/is_partitioned

1) Returns true if all elements in the range [first, last) that satisfy the predicate p appear before all 
elements that don't. Also returns true if [first, last) is empty.
2) Same as (1), but executed according to policy. This overload does not participate in overload resolution 
unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
true if the range [first, last) is empty or is partitioned by p. false otherwise.

*/

int main()
{
    std::array<int, 9> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
 
    auto is_even = [](int i){ return i % 2 == 0; };
    std::cout.setf(std::ios_base::boolalpha);
    for_each(v.begin(), v.end(), [](int v){ cout << v << " ";});
    // no group yet, return false
    std::cout << std::is_partitioned(v.begin(), v.end(), is_even) << ' ' << endl;
 
    // divide the elements in the range to two groups
    std::partition(v.begin(), v.end(), is_even);
    for_each(v.begin(), v.end(), [](int v){ cout << v << " ";});
    // two groups now, return true
    std::cout << std::is_partitioned(v.begin(), v.end(), is_even) << ' ' << endl;

    // reverse, now first part is odd, which is_even will return false, so is_partition returns false
    std::reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int v){ cout << v << " ";});
    std::cout << std::is_partitioned(v.cbegin(), v.cend(), is_even) << ' ' << endl;

    // by using rbegin()/rend(), first part is even, which is_even will return true, so is_partition returns true
    for_each(v.rbegin(), v.rend(), [](int v){ cout << v << " ";});
    std::cout << std::is_partitioned(v.crbegin(), v.crend(), is_even) << endl;

    return 0;
    // 1 2 3 4 5 6 7 8 9 false 
    // 8 2 6 4 5 3 7 1 9 true 
    // 9 1 7 3 5 4 6 2 8 false 
    // 8 2 6 4 5 3 7 1 9 true
}
