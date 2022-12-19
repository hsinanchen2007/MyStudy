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

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/shift

Shifts the elements in the range [first, last) by n positions.

1) Shifts the elements towards the beginning of the range. If n == 0 || n >= last - first, there are no effects. 
If n < 0, the behavior is undefined. Otherwise, for every integer i in [0, last - first - n), moves the element 
originally at position first + n + i to position first + i. The moves are performed in increasing order of i 
starting from ​0​.
3) Shifts the elements towards the end of the range. If n == 0 || n >= last - first, there are no effects. 
If n < 0, the behavior is undefined. Otherwise, for every integer i in [0, last - first - n), moves the element 
originally at position first + i to position first + n + i. If ForwardIt meets the LegacyBidirectionalIterator 
requirements, then the moves are performed in decreasing order of i starting from last - first - n - 1.
2,4) Same as (1) and (3), respectively, but executed according to policy and the moves may be performed in any 
order. This overload participates in overload resolution only if 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> is true

Return value
1-2) The end of the resulting range. If n is less than last - first, returns first + (last - first - n). 
Otherwise, returns first.
3-4) The beginning of the resulting range. If n is less than last - first, returns first + n. Otherwise, returns 
last.

*/

struct S {
    int value{0};
    bool specified_state{true};
 
    S(int v = 0) : value{v} {}
    S(S const& rhs) = default;
    S(S&& rhs) { *this = std::move(rhs); }
    S& operator=(S const& rhs) = default;
    S& operator=(S&& rhs) {
        if (this != &rhs) {
            value = rhs.value;
            specified_state = rhs.specified_state;
            rhs.specified_state = false;
        }
        return *this;
    }
};
 
template <typename T>
std::ostream& operator<< (std::ostream& os, std::vector<T> const& v) {
    for (const auto& s : v) {
        if constexpr (std::is_same_v<T, S>)
            s.specified_state ? os << s.value << ' ' : os << ". ";
        else if constexpr (std::is_same_v<T, std::string>)
            os << (s.empty() ? "." : s) << ' ';
        else
            os << s << ' ';
    }
    return os;
}

int main()
{
    std::cout << std::left;
 
    std::vector<S>            a{1, 2, 3, 4, 5, 6, 7};
    std::vector<int>          b{1, 2, 3, 4, 5, 6, 7};
    std::vector<std::string>  c{"α", "β", "γ", "δ", "ε", "ζ", "η"};
 
    std::cout << "vector<S> \tvector<int> \tvector<string>\n";
    std::cout << a << "  " << b << "  " << c << '\n';
 
    std::shift_left(begin(a), end(a), 3);
    std::shift_left(begin(b), end(b), 3);
    std::shift_left(begin(c), end(c), 3);
    std::cout << a << "  " << b << "  " << c << '\n';
 
    std::shift_right(begin(a), end(a), 2);
    std::shift_right(begin(b), end(b), 2);
    std::shift_right(begin(c), end(c), 2);
    std::cout << a << "  " << b << "  " << c << '\n';
 
    std::shift_left(begin(a), end(a), 8);  // has no effect: n >= last - first
    std::shift_left(begin(b), end(b), 8);  // ditto
    std::shift_left(begin(c), end(c), 8);  // ditto
    std::cout << a << "  " << b << "  " << c << '\n';
 
    //  std::shift_left(begin(a), end(a),-3);  // UB, e.g. segfault.)

    return 0;
    // vector<S> 	vector<int> 	vector<string>
    // 1 2 3 4 5 6 7   1 2 3 4 5 6 7   α β γ δ ε ζ η 
    // 4 5 6 7 . . .   4 5 6 7 5 6 7   δ ε ζ η . . . 
    // . . 4 5 6 7 .   4 5 4 5 6 7 5   . . δ ε ζ η . 
    // . . 4 5 6 7 .   4 5 4 5 6 7 5   . . δ ε ζ η .
}
