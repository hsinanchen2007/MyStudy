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
#include <cctype>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/includes

Returns true if the sorted range [first2, last2) is a subsequence of the sorted range [first1, last1). 
(A subsequence need not be contiguous.)

1) Both ranges must be sorted with operator<.
3) Both ranges must be sorted with the given comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
true if [first2, last2) is a subsequence of [first1, last1); otherwise false.

*/

template<class Os, class Co> Os& operator<<(Os& os, const Co& v) {
    for (auto i : v) os << i << ' ';
    return os << '\t';
}
 
int main()
{
    const auto
        v1 = {'a', 'b', 'c', 'f', 'h', 'x'},
        v2 = {'a', 'b', 'c'},
        v3 = {'a', 'c'},
        v4 = {'a', 'a', 'b'},
        v5 = {'g'},
        v6 = {'a', 'c', 'g'},
        v7 = {'A', 'B', 'C'};
    
    auto no_case = [](char a, char b) { return std::tolower(a) < std::tolower(b); };
    
    // note that the requirement of the includes() needed a sorted range compared to 
    // another sorted range
    std::cout
    << v1 << "\nincludes:\n" << std::boolalpha
    << v2 << ": " << std::includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << '\n'
    << v3 << ": " << std::includes(v1.begin(), v1.end(), v3.begin(), v3.end()) << '\n'
    << v4 << ": " << std::includes(v1.begin(), v1.end(), v4.begin(), v4.end()) << '\n'
    << v5 << ": " << std::includes(v1.begin(), v1.end(), v5.begin(), v5.end()) << '\n'
    << v6 << ": " << std::includes(v1.begin(), v1.end(), v6.begin(), v6.end()) << '\n'
    << v7 << ": " << std::includes(v1.begin(), v1.end(), v7.begin(), v7.end(), no_case)
          << " (case-insensitive)\n";

    return 0;
    // a b c f h x 	
    // includes:
    // a b c 	: true
    // a c 	: true
    // a a b 	: false
    // g 	: false
    // a c g 	: false
    // A B C 	: true (case-insensitive)
}
