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

https://en.cppreference.com/w/cpp/algorithm/reduce

1) same as reduce(first, last, typename std::iterator_traits<InputIt>::value_type{})
3) same as reduce(first, last, init, std::plus<>())
5) Reduces the range [first; last), possibly permuted and aggregated in unspecified manner, 
along with the initial value init over binary_op. 
2,4,6) Same as (1,3,5), but executed according to policy. These overloads do not participate 
in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true. The behavior is non-deterministic if binary_op is not associative or not commutative.

The behavior is undefined if binary_op modifies any element or invalidates any iterator in 
[first; last], including the end iterator.

*/

#if PARALLEL
#include <execution>
#define SEQ std::execution::seq,
#define PAR std::execution::par,
#else
#define SEQ
#define PAR
#endif
 
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

int main()
{
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout << std::fixed << std::setprecision(1);
    auto eval = [](auto fun) {
        const auto t1 = std::chrono::high_resolution_clock::now();
        const auto [name, result] = fun();
        const auto t2 = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double, std::milli> ms = t2 - t1;
        std::cout << std::setw(28) << std::left << name << "sum: "
                  << result << "\t time: " << ms.count() << " ms\n";
    };
    {
        const std::vector<double> v(100'000'007, 0.1);
 
        eval([&v]{ return std::pair{"std::accumulate (double)",
            std::accumulate(v.cbegin(), v.cend(), 0.0)}; } );
        eval([&v]{ return std::pair{"std::reduce (seq, double)",
            std::reduce(SEQ v.cbegin(), v.cend())}; } );
        eval([&v]{ return std::pair{"std::reduce (par, double)",
            std::reduce(PAR v.cbegin(), v.cend())}; } );
    }
    {
        const std::vector<long> v(100'000'007, 1);
 
        eval([&v]{ return std::pair{"std::accumulate (long)",
            std::accumulate(v.cbegin(), v.cend(), 0)}; } );
        eval([&v]{ return std::pair{"std::reduce (seq, long)",
            std::reduce(SEQ v.cbegin(), v.cend())}; } );
        eval([&v]{ return std::pair{"std::reduce (par, long)",
            std::reduce(PAR v.cbegin(), v.cend())}; } );
    }

    return 0;
    // POSIX: g++ -std=c++23 ./example.cpp -ltbb -O3; ./a.out
    // std::accumulate (double)    sum: 10,000,000.7    time: 356.9 ms
    // std::reduce (seq, double)   sum: 10,000,000.7    time: 140.1 ms
    // std::reduce (par, double)   sum: 10,000,000.7    time: 140.1 ms
    // std::accumulate (long)      sum: 100,000,007     time: 46.0 ms
    // std::reduce (seq, long)     sum: 100,000,007     time: 67.3 ms
    // std::reduce (par, long)     sum: 100,000,007     time: 63.3 ms
    
    // POSIX: g++ -std=c++23 ./example.cpp -ltbb -O3 -DPARALLEL; ./a.out
    // std::accumulate (double)    sum: 10,000,000.7    time: 353.4 ms
    // std::reduce (seq, double)   sum: 10,000,000.7    time: 140.7 ms
    // std::reduce (par, double)   sum: 10,000,000.7    time: 24.7 ms
    // std::accumulate (long)      sum: 100,000,007     time: 42.4 ms
    // std::reduce (seq, long)     sum: 100,000,007     time: 52.0 ms
    // std::reduce (par, long)     sum: 100,000,007     time: 23.1 ms
}
