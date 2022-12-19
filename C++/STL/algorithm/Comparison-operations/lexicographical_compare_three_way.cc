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
#include <compare>  // this is for C++ 20
#include <iomanip>
#include <iostream>
#include <string_view>
#include <utility>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare_three_way

Lexicographically compares two ranges [first1, last1) and [first2, last2) using three-way comparison 
and produces a result of the strongest applicable comparison category type.

1) Returns the order between the first non-equivalent pair of elements according to comp in both ranges 
if any, otherwise (if one ranges is equivalent to the prefix of another according to comp), returns the 
order between the length of both ranges.

2) Equivalent to:
return std::lexicographical_compare_three_way(
    first1, last1, first2, last2, std::compare_three_way());

Return value
The value of a comparison category type specified above.

*/
 
void show_result(std::string_view s1, std::string_view s2, std::strong_ordering o)
{
    std::cout << quoted(s1) << " is ";
    (o < 0) ? std::cout << "less than " :
    (o > 0) ? std::cout << "greater than " :
              std::cout << "equal to ";
    std::cout << quoted(s2) << '\n';
}
 
int main()
{
    auto cmp_icase = [](char x, char y) {
        const auto ux { std::toupper(x) };
        const auto uy { std::toupper(y) };
        return (ux < uy) ? std::strong_ordering::less:
               (ux > uy) ? std::strong_ordering::greater:
                           std::strong_ordering::equal;
    };
 
    for (const auto& [s1, s2] : { std::pair{"one"sv, "ONE"sv},
                                           {"two"sv, "four"sv},
                                           {"three"sv, "two"sv} }) {
        const auto res = std::lexicographical_compare_three_way(
            s1.cbegin(), s1.cend(), s2.cbegin(), s2.cend(), cmp_icase);
        show_result(s1, s2, res);
    }

    return 0;
}
