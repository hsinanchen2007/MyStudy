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

https://en.cppreference.com/w/cpp/algorithm/random_shuffle

Reorders the elements in the given range [first, last) such that each possible permutation of those 
elements has equal probability of appearance.

1) The random number generator is implementation-defined, but the function std::rand is often used.
2) The random number generator is the function object r.
3) The random number generator is the function object g.

Return value
(none)

*/

// example from https://en.cppreference.com/w/cpp/algorithm/random_shuffle
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(v.begin(), v.end(), g);
 
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    return 0;
    // 8 6 10 4 2 3 7 1 9 5
}
