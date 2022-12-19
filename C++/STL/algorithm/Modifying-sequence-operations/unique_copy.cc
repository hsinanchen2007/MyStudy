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

https://en.cppreference.com/w/cpp/algorithm/unique_copy

Copies the elements from the range [first, last), to another range beginning at d_first in such a way that 
there are no consecutive equal elements. Only the first element of each group of equal elements is copied.

1) Elements are compared using operator==. The behavior is undefined if it is not an equivalence relation.
3) Elements are compared using the given binary predicate p. The behavior is undefined if it is not an 
equivalence relation.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload resolution 
unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Output iterator to the element past the last written element.

*/

int main()
{
    std::string s1 = "The      string    with many       spaces!";
    std::cout << "before: " << s1 << '\n';
 
    std::string s2;
    std::unique_copy(s1.begin(), s1.end(), std::back_inserter(s2),
                     [](char c1, char c2){ return c1 == ' ' && c2 == ' '; });
 
    std::cout << "after:  " << s2 << '\n';

    return 0;
    // before: The      string    with many       spaces!
    // after:  The string with many spaces!
}

