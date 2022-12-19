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

https://en.cppreference.com/w/cpp/algorithm/adjacent_difference

Computes the differences between the second and the first of each adjacent pair of elements of the range 
[first, last) and writes them to the range beginning at d_first + 1. An unmodified copy of *first is written 
to *d_first.

1,3) First, creates an accumulator acc whose type is InputIt's value type, initializes it with *first, 
and assigns the result to *d_first. Then, for every iterator i in [first + 1, last) in order, creates an 
object val whose type is InputIt's value type, initializes it with *i, computes val - acc (until C++20)val - 
std::move(acc) (since C++20) (overload (1)) or op(val, acc) (until C++20)op(val, std::move(acc)) (since C++20) 
(overload (3)), assigns the result to *(d_first + (i - first)), and move assigns from val to acc. 
first may be equal to d_first.

2,4) Performs *d_first = *first;. For every d in [1, last - first - 1], assigns *(first + d) - *(first + d - 1) 
(overload (2)) or op(*(first + d), *(first + d - 1)) (overload (4)) to *(d_first + d). This is executed 
according to policy. These overloads do not participate in overload resolution unless 
std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.
The behavior is undefined if the input and output ranges overlap in any way.

Equivalent operation:

*(d_first)   = *first;
*(d_first+1) = *(first+1) - *(first);
*(d_first+2) = *(first+2) - *(first+1);
*(d_first+3) = *(first+3) - *(first+2);
...

op must not have side effects. (until C++11)

op must not invalidate any iterators, including the end iterators, or modify any elements of the ranges involved. 
(since C++11)

*/

auto print = [](auto comment, auto const& sequence) {
    std::cout << comment;
    for (const auto& n : sequence)
        std::cout << n << ' ';
    std::cout << '\n';
};

int main()
{
    // Default implementation - the difference b/w two adjacent items
    std::vector<int> v = {4, 6, 9, 13, 18, 19, 19, 15, 10};
    print("Initially, v = ", v);

    // 4 - 0 = 4
    // 6 - 4 = 2
    // 9 - 6 = 3
    // 13 - 9 = 4
    // 18 - 13 = 5
    // 19 - 18 = 1
    // 19 - 19 = 0
    // 15 - 19 = -4
    // 10 - 15 = -5
    std::adjacent_difference(v.begin(), v.end(), v.begin());
    print("Modified v = ", v);
 
    // Fibonacci
    std::array<int, 10> a {1};
    adjacent_difference(begin(a), std::prev(end(a)), std::next(begin(a)), std::plus<> {});
    print("Fibonacci, a = ", a);

    return 0;
    // Initially, v = 4 6 9 13 18 19 19 15 10 
    // Modified v = 4 2 3 4 5 1 0 -4 -5 
    // Fibonacci, a = 1 1 2 3 5 8 13 21 34 55 
}
