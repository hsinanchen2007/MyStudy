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
#include <random>
#include <cassert>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/is_sorted_until

Examines the range [first, last) and finds the largest range beginning at first in which the elements 
are sorted in non-descending order.

A sequence is sorted with respect to a comparator comp if for any iterator it pointing to the sequence 
and any non-negative integer n such that it + n is a valid iterator pointing to an element of the sequence, 
comp(*(it + n), *it) evaluates to false.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
The upper bound of the largest range beginning at first in which the elements are sorted in ascending 
order. That is, the last iterator it for which range [first, it) is sorted.

*/

int main()
{
    std::random_device rd;
    std::mt19937 g(rd());
    const int N = 6;
    int nums[N] = {3, 1, 4, 1, 5, 9};
 
    const int min_sorted_size = 4;
 
    for (int sorted_size = 0; sorted_size < min_sorted_size; )
    {
        std::shuffle(nums, nums + N, g);

        // return the iterator of last element that is still sorted
        int *const sorted_end = std::is_sorted_until(nums, nums + N);
        sorted_size = std::distance(nums, sorted_end);
        assert(sorted_size >= 1);
 
        for (auto i : nums) std::cout << i << ' ';
        std::cout << " : " << sorted_size << " initial sorted elements\n"
                  << std::string(sorted_size * 2 - 1, '^') << '\n';
    }

    return 0;
}
