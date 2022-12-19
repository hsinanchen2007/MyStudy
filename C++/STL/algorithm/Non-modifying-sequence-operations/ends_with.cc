#include <algorithm>
#include <array>
#include <iostream>
 
/*

https://en.cppreference.com/w/cpp/algorithm/ranges/ends_with

Checks whether the second range matches the suffix of the first range.

1) Let N1 and N2 be ranges::distance(first1, last1) and ranges::distance(first2, last2) 
respectively. If N1 < N2, returns false. Otherwise, returns true if only if every element 
in the range [first2, last2) is equal to the corresponding element in [first1 + N1 - N2, last1). 
Comparison is done by applying the binary predicate pred to elements in two ranges 
projected by proj1 and proj2 respectively.
2) Same as (1), but uses r1 and r2 as the source ranges, as if using ranges::begin(r1) 
as first1, ranges:begin(r2) as first2, ranges::end(r1) as last1, and ranges::end(r2) as last2.
The function-like entities described on this page are niebloids, that is:

Explicit template argument lists may not be specified when calling any of them.
None of them is visible to argument-dependent lookup.
When one of them is found by normal unqualified lookup for the name to the left of the 
function-call operator, it inhibits argument-dependent lookup. In practice, they may be 
implemented as function objects, or with special compiler extensions.

Return value
true if the second range matches the suffix of the first range, false otherwise.

*/

// Below example code is from https://en.cppreference.com/w/cpp/algorithm/ranges/ends_with

int main()
{
    std::cout
        << std::boolalpha
        << std::ranges::ends_with("static_cast", "cast") << '\n'
        << std::ranges::ends_with("const_cast", "cast") << '\n'
        << std::ranges::ends_with("reinterpret_cast", "cast") << '\n'
        << std::ranges::ends_with("dynamic_cast", "cast") << '\n'
        << std::ranges::ends_with("move", "cast") << '\n'
        << std::ranges::ends_with("move_if_noexcept", "cast") << '\n'
        << std::ranges::ends_with("forward", "cast") << '\n';
    static_assert(
        !  std::ranges::ends_with("as_const", "cast") and
        !! std::ranges::ends_with("bit_cast", "cast") and
        !  std::ranges::ends_with("to_underlying", "cast") and
        !! std::ranges::ends_with(std::array{1,2,3,4}, std::array{3,4}) and
        !  std::ranges::ends_with(std::array{1,2,3,4}, std::array{4,5})
        );
}