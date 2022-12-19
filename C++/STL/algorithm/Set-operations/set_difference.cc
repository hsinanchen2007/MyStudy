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

https://en.cppreference.com/w/cpp/algorithm/set_difference

Copies the elements from the sorted range [first1, last1) which are not found in the sorted range 
[first2, last2) to the range beginning at d_first.

The resulting range is also sorted. Equivalent elements are treated individually, that is, if some 
element is found m times in [first1, last1) and n times in [first2, last2), it will be copied to 
d_first exactly std::max(m-n, 0) times. The resulting range cannot overlap with either of the input 
ranges.

1) Elements are compared using operator< and the ranges must be sorted with respect to the same.
3) Elements are compared using the given binary comparison function comp and the ranges must be 
sorted with respect to the same.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator past the end of the constructed range.

*/

int main()
{
    const std::vector<int> v1 {1, 2, 5, 5, 5, 9};
    const std::vector<int> v2 {2, 5, 7};
    std::vector<int> diff;

    // copy the elements from v1 which NOT existed in v2 to diff by using std::insert()
    // note that the v1/v2 order is important when it compares from/to
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                        std::inserter(diff, diff.begin()));
    for_each(diff.begin(), diff.end(), [](int v){ cout << v << " "; });
    cout << endl;

    // clean up and do it again, but v1/v2 order is changed
    diff.clear();
    std::set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(),
                        std::inserter(diff, diff.begin()));
    for_each(diff.begin(), diff.end(), [](int v){ cout << v << " "; });
    cout << endl;

    return 0;
    // 1 5 5 9 
    // 7 
}
