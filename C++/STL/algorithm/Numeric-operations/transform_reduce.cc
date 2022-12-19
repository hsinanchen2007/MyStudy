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

https://en.cppreference.com/w/cpp/algorithm/transform_reduce

1) Equivalent to std::transform_reduce(first1, last1, first2, init, std::plus<>(), std::multiplies<>());, 
effectively parallelized version of the default std::inner_product
2) Applies transform to each pair of elements from the ranges [first; last) and the range starting at 
first2 and reduces the results (possibly permuted and aggregated in unspecified manner) along with the 
initial value init over reduce
3) Applies transform to each element in the range [first; last) and reduces the results (possibly permuted 
and aggregated in unspecified manner) along with the initial value init over reduce.
4-6) Same as (1-3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.
The behavior is non-deterministic if reduce is not associative or not commutative.

The behavior is undefined if reduce, or transform modifies any element or invalidates any iterator in the 
input ranges, including their end iterators.

Return value
2) Generalized sum of init and transform(*first,*first2), transform(*(first+1),*(first2+1)), ..., over reduce
3) Generalized sum of init and transform(*first), transform(*(first+1)), ... transform(*(last-1)) over reduce,

where generalized sum GSUM(op, a
1, ..., a
N) is defined as follows:

if N=1, a
1
if N > 1, op(GSUM(op, b
1, ..., b
K), GSUM(op, b
M, ..., b
N)) where
b
1, ..., b
N may be any permutation of a1, ..., aN and
1 < K+1 = M ≤ N

in other words, the results of transform or of reduce may be grouped and arranged in arbitrary order.

*/

#if PARALLEL
#include <execution>
#define PAR std::execution::par,
#else
#define PAR
#endif
 
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <locale>
#include <numeric>
#include <vector>
 
// to parallelize non-associate accumulative operation, you'd better choose
// transform_reduce instead of reduce; e.g., a + b * b != b + a * a
void print_sum_squared(long const num)
{
    std::cout.imbue(std::locale{"en_US.UTF8"});
    std::cout << "num = " << num << '\n';
 
    // create an immutable vector filled with pattern: 1,2,3,4, 1,2,3,4 ...
    const std::vector<long> v { [n = num * 4] {
        std::vector<long> v;
        v.reserve(n);
        std::generate_n(std::back_inserter(v), n,
            [i=0]() mutable { return 1 + i++ % 4; });
        return v;
    }()};
 
    auto squared_sum = [](auto sum, auto val) { return sum + val * val; };
 
    auto sum1 = std::accumulate(v.cbegin(), v.cend(), 0L, squared_sum);
    std::cout << "accumulate(): " << sum1 << '\n';
 
    auto sum2 = std::reduce(PAR v.cbegin(), v.cend(), 0L, squared_sum);
    std::cout << "reduce(): " << sum2 << '\n';
 
    auto sum3 = std::transform_reduce(PAR v.cbegin(), v.cend(), 0L, std::plus{},
                                      [](auto val) { return val * val; });
    std::cout << "transform_reduce(): " << sum3 << "\n\n";
}
 
int main()
{
    print_sum_squared(1);
    print_sum_squared(1'000);
    print_sum_squared(1'000'000);
    // num = 1
    // accumulate(): 30
    // reduce(): 30
    // transform_reduce(): 30
    //
    // num = 1,000
    // accumulate(): 30,000
    // reduce(): -7,025,681,278,312,630,348
    // transform_reduce(): 30,000
    //
    // num = 1,000,000
    // accumulate(): 30,000,000
    // reduce(): -5,314,886,882,370,003,032
    // transform_reduce(): 30,000,000
    // Compile-options for parallel execution on POSIX:
    // g++ -O2 -std=c++17 -Wall -Wextra -pedantic -DPARALLEL ./example.cpp -ltbb -o tr; ./tr
}

