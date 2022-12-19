#include <string_view>
#include <algorithm>
#include <iostream>
#include <ranges>

/*

https://en.cppreference.com/w/cpp/algorithm/ranges/starts_with

Checks whether the second range matches the prefix of the first range.

1) Let N1 and N2 denote the size of ranges [first1, last1) and [first2, last2) respectively. 
If N1 < N2, returns false. Otherwise, returns true only if every element in the range [first2, last2) 
is equal to the corresponding element in [first1, first1 + N2). Comparison is done by applying 
the binary predicate pred to elements in two ranges projected by proj1 and proj2 respectively.
2) Same as (1), but uses r1 and r2 as the source ranges, as if using ranges::begin(r1) as first1, 
ranges:begin(r2) as first2, ranges::end(r1) as last1, and ranges::end(r2) as last2.
The function-like entities described on this page are niebloids, that is:

Explicit template argument lists may not be specified when calling any of them.
None of them is visible to argument-dependent lookup.
When one of them is found by normal unqualified lookup for the name to the left of the function-call 
operator, it inhibits argument-dependent lookup. In practice, they may be implemented as function 
objects, or with special compiler extensions.

Return value
true if the second range matches the prefix of the first range, false otherwise.

*/

// Below example code is from https://en.cppreference.com/w/cpp/algorithm/ranges/starts_with
int main()
{
    using namespace std::literals;
 
    constexpr auto ascii_upper = [](char8_t c)
    {
        return u8'a' <= c && c <= u8'z' ? static_cast<char8_t>(c + u8'A' - u8'a') : c;
    };
 
    constexpr auto cmp_ignore_case = [=](char8_t x, char8_t y)
    {
        return ascii_upper(x) == ascii_upper(y);
    };
 
    static_assert(std::ranges::starts_with("const_cast", "const"sv));
    static_assert(std::ranges::starts_with("constexpr", "const"sv));
    static_assert(!std::ranges::starts_with("volatile", "const"sv));
 
    std::cout
        << std::boolalpha
        << std::ranges::starts_with(u8"Constantinopolis", u8"constant"sv,
                                    {}, ascii_upper, ascii_upper) << ' '
        << std::ranges::starts_with(u8"Istanbul", u8"constant"sv,
                                    {}, ascii_upper, ascii_upper) << ' '
        << std::ranges::starts_with(u8"Metropolis", u8"metro"sv,
                                    cmp_ignore_case) << ' '
        << std::ranges::starts_with(u8"Acropolis", u8"metro"sv,
                                    cmp_ignore_case) << '\n';
 
    constexpr static auto v = { 1, 3, 5, 7, 9 };
    constexpr auto odd = [](int x) { return x % 2; };
    static_assert( std::ranges::starts_with( v, std::views::iota(1)
                                              | std::views::filter(odd)
                                              | std::views::take(3) ) );
}

