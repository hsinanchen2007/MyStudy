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

https://en.cppreference.com/w/cpp/algorithm/partial_sum

Computes the partial sums of the elements in the subranges of the range [first, last) and writes them to the 
range beginning at d_first. The first version uses operator+ to sum up the elements, the second version uses 
the given binary function op, both applying std::move to their operands on the left hand side (since C++20).

Equivalent operation:

*(d_first)   = *first;
*(d_first+1) = *first + *(first+1);
*(d_first+2) = *first + *(first+1) + *(first+2);
*(d_first+3) = *first + *(first+1) + *(first+2) + *(first+3);
...

op must not have side effects. (until C++11)

op must not invalidate any iterators, including the end iterators, or modify any elements of the range involved.
(since C++11)

*/

int main()
{
    std::vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
 
    std::cout << "The first 10 even numbers are: ";
    std::partial_sum(v.begin(), v.end(), 
                     std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
    std::cout << "The first 10 powers of 2 are: ";
    for (auto n : v) {
        std::cout << n << " ";
    }
    std::cout << '\n';

    return 0;
    // The first 10 even numbers are: 2 4 6 8 10 12 14 16 18 20 
    // The first 10 powers of 2 are: 2 4 8 16 32 64 128 256 512 1024
}
