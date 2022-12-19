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

https://en.cppreference.com/w/cpp/algorithm/exclusive_scan

Computes an exclusive prefix sum operation using binary_op (or std::plus<>() for overloads (1-2)) 
for the range [first, last), using init as the initial value, and writes the results to the range 
beginning at d_first. "exclusive" means that the i-th input element is not included in the i-th sum.

Formally, assigns through each iterator i in [d_first, d_first + (last - first)) the value of the 
generalized noncommutative sum of init, *j... for every j in [first, first + (i - d_first)) over 
binary_op,

where generalized noncommutative sum GNSUM(op, a
1, ..., a
N) is defined as follows:

if N=1, a
1
if N > 1, op(GNSUM(op, a
1, ..., a
K), GNSUM(op, a
M, ..., a
N)) for any K where 1 < K+1 = M ≤ N

In other words, the summation operations may be performed in arbitrary order, and the behavior is 
nondeterministic if binary_op is not associative.

Overloads (2,4) are executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

binary_op shall not invalidate iterators (including the end iterators) or subranges, nor modify 
elements in the ranges [first, last) or [d_first, d_first + (last - first)). Otherwise, the behavior 
is undefined.

Return value
Iterator to the element past the last element written.


https://en.cppreference.com/w/cpp/algorithm/inclusive_scan

Computes an inclusive prefix sum operation using binary_op (or std::plus<>() for overloads (1-2)) 
for the range [first, last), using init as the initial value (if provided), and writes the results 
to the range beginning at d_first. "inclusive" means that the i-th input element is included in 
the i-th sum.

Formally, assigns through each iterator i in [d_first, d_first + (last - first)) the value of:

for overloads (1-4), the generalized noncommutative sum of *j... for every j in [first, first + 
(i - d_first + 1)) over binary_op
for overloads (5-6), the generalized noncommutative sum of init, *j... for every j in [first, 
first + (i - d_first + 1)) over binary_op

where generalized noncommutative sum GNSUM(op, a
1, ..., a
N) is defined as follows:

if N=1, a
1
if N > 1, op(GNSUM(op, a
1, ..., a
K), GNSUM(op, a
M, ..., a
N)) for any K where 1 < K+1 = M ≤ N
In other words, the summation operations may be performed in arbitrary order, and the behavior is 
nondeterministic if binary_op is not associative.

Overloads (2,4,6) are executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

binary_op shall not invalidate iterators (including the end iterators) or subranges, nor modify 
elements in the ranges [first, last) or [d_first, d_first + (last - first)). Otherwise, the behavior 
is undefined.

Return value
Iterator to the element past the last element written.

*/

int main()
{
    std::vector data {3, 1, 4, 1, 5, 9, 2, 6};
    
    std::cout << "exclusive sum: ";
    std::exclusive_scan(data.begin(), data.end(),
                std::ostream_iterator<int>(std::cout, " "),
                0);
    std::cout << "\ninclusive sum: ";
    std::inclusive_scan(data.begin(), data.end(),
                std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << "\n\nexclusive product: ";  
    std::exclusive_scan(data.begin(), data.end(),
                std::ostream_iterator<int>(std::cout, " "),
                1, std::multiplies<>{});		      
    std::cout << "\ninclusive product: ";
    std::inclusive_scan(data.begin(), data.end(),
                std::ostream_iterator<int>(std::cout, " "),
                std::multiplies<>{});		      
                
    return 0;
    // exclusive sum: 0 3 4 8 9 14 23 25 
    // inclusive sum: 3 4 8 9 14 23 25 31 
    // 
    // exclusive product: 1 3 3 12 12 60 540 1080 
    // inclusive product: 3 3 12 12 60 540 1080 6480
}
