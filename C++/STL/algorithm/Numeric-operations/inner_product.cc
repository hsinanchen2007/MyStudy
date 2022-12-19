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

https://en.cppreference.com/w/cpp/algorithm/inner_product

Computes inner product (i.e. sum of products) or performs ordered map/reduce operation on the range 
[first1, last1) and the range beginning at first2.

1) Initializes the accumulator acc with the initial value init and then
modifies it with the expression acc = acc + *first1 * *first2, then modifies again with the expression 
acc = acc + *(first1+1) * *(first2+1), etc

(until C++20)
modifies it with the expression acc = std::move(acc) + *first1 * *first2, then modifies again with the 
expression acc = std::move(acc) + *(first1+1) * *(first2+1), etc

(since C++20)
until reaching last1. For built-in meaning of + and *, this computes inner product of the two ranges.
2) Initializes the accumulator acc with the initial value init and then
modifies it with the expression acc = op1(acc, op2(*first1, *first2)), then modifies again with the 
expression acc = op1(acc, op2(*(first1+1), *(first2+1))), etc

(until C++20)
modifies it with the expression acc = op1(std::move(acc), op2(*first1, *first2)), then modifies again 
with the expression acc = op1(std::move(acc), op2(*(first1+1), *(first2+1))), etc

(since C++20)
until reaching last1.
op1 or op2 must not have side effects.

(until C++11)
op1 or op2 must not invalidate any iterators, including the end iterators, or modify any elements of 
the range involved.

(since C++11)

*/

int main()
{
    std::vector<int> a{0, 1, 2, 3, 4};
    std::vector<int> b{5, 4, 2, 3, 1};
 
    // 0*5 + 1*4 + 2*2 + 3*3 + 4*1 = 21
    int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    std::cout << "Inner product of a and b: " << r1 << '\n';
 
    // TODO: how to calculate below?
    int r2 = std::inner_product(a.begin(), a.end(), b.begin(), 0,
                                std::plus<>(), std::equal_to<>());
    std::cout << "Number of pairwise matches between a and b: " <<  r2 << '\n';

    return 0;
    // Inner product of a and b: 21
    // Number of pairwise matches between a and b: 2
}
