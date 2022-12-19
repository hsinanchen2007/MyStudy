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

https://en.cppreference.com/w/cpp/algorithm/set_symmetric_difference

Computes symmetric difference of two sorted ranges: the elements that are found in either of the ranges, 
but not in both of them are copied to the range beginning at d_first. The resulting range is also sorted.

If some element is found m times in [first1, last1) and n times in [first2, last2), it will be copied to 
d_first exactly std::abs(m-n) times. If m>n, then the last m-n of those elements are copied from [first1,last1), 
otherwise the last n-m elements are copied from [first2,last2). The resulting range cannot overlap with 
either of the input ranges.

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
    // the difference between set_intersection() and set_symmetric_difference() is that,
    // set_symmetric_difference() will find the elements only existed in one range, but
    // set_intersection() will find the elements existed in both ranges
    std::vector<int> v1{1,2,3,4,5,6,7,8     };
    std::vector<int> v2{        5,  7,  9,10};
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
 
    std::vector<int> v_symDifference;
 
    std::set_symmetric_difference(
        v1.begin(), v1.end(),
        v2.begin(), v2.end(),
        std::back_inserter(v_symDifference));
 
    for(int n : v_symDifference)
        std::cout << n << ' ';
    cout << endl;

    return 0;
    // 1 2 3 4 6 8 9 10
}
