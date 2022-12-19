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
#include <cstdlib>
#include <ctime>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/minmax

Returns the lowest and the greatest of the given values.

1-2) Returns references to the smaller and the greater of a and b.
3-4) Returns the smallest and the greatest of the values in initializer list ilist.
The (1,3) versions use operator< to compare the values, whereas the (2,4) versions 
use the given comparison function comp.

Return value
1-2) Returns the result of std::pair<const T&, const T&>(a, b) if a<b or if a is 
equivalent to b. Returns the result of std::pair<const T&, const T&>(b, a) if b<a.
3-4) A pair with the smallest value in ilist as the first element and the greatest 
as the second. If several elements are equivalent to the smallest, the leftmost such 
element is returned. If several elements are equivalent to the largest, the rightmost 
such element is returned.

*/

int main()
{
    std::vector<int> v {3, 1, 4, 1, 5, 9, 2, 6}; 
    std::srand(std::time(0));

    // minmax() will return a pair of [min max] range
    std::pair<int, int> bounds = std::minmax(std::rand() % v.size(),
                                             std::rand() % v.size());
 
    std::cout << "v[" << bounds.first << "," << bounds.second << "]: ";
    for (int i = bounds.first; i < bounds.second; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';

    return 0;
    // v[3,7]: 1 5 9 2
}
