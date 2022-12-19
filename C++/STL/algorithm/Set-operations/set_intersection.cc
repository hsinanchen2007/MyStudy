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

https://en.cppreference.com/w/cpp/algorithm/set_intersection

Constructs a sorted range beginning at d_first consisting of elements that are found in both sorted ranges 
[first1, last1) and [first2, last2). If some element is found m times in [first1, last1) and n times in 
[first2, last2), the first std::min(m, n) elements will be copied from the first range to the destination 
range. The order of equivalent elements is preserved. The resulting range cannot overlap with either of the 
input ranges.

1) Elements are compared using operator< and the ranges must be sorted with respect to the same.
3) Elements are compared using the given binary comparison function comp and the ranges must be sorted with 
respect to the same.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload resolution 
unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator past the end of the constructed range.

*/

int main()
{
    // for demo purpose, below shows 5 and 7 are the intersection
    std::vector<int> v1{1,2,3,4,5,6,7,8};
    std::vector<int> v2{        5,  7,  9,10};

    // set operations required sorted ranges
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
 
    std::vector<int> v_intersection;
 
    std::set_intersection(v1.begin(), v1.end(),
                          v2.begin(), v2.end(),
                          std::back_inserter(v_intersection));
    for(int n : v_intersection)
        std::cout << n << ' ';
    cout << endl;

    return 0;
    // 5 7
}
