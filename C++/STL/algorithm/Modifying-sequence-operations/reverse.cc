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

https://en.cppreference.com/w/cpp/algorithm/reverse

1) Reverses the order of the elements in the range [first, last).
Behaves as if applying std::iter_swap to every pair of iterators first+i, (last-i) - 1 
for each non-negative i < (last-first)/2.
2) Same as (1), but executed according to policy. This overload does not participate in 
overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.

Return value
(none)

*/

int main()
{
    std::vector<int> v{1, 2, 3};
    std::reverse(v.begin(), v.end());
    for(auto e : v) std::cout << e;
    std::cout << '\n';

    // below reverse() call, no matter it is v.begin()/v.end() or
    // v.rbegin()/v.rend(), the result will be the same
    std::reverse(v.rbegin(), v.rend());
    for(auto e : v) std::cout << e;
    std::cout << '\n';

    int a[] = {4, 5, 6, 7};
    std::reverse(std::begin(a), std::end(a));
    for(auto e : a) std::cout << e;
    std::cout << '\n';

    return 0;
    // 321
    // 123
    // 7654
}

