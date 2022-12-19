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

https://en.cppreference.com/w/cpp/algorithm/max

Returns the greater of the given values.

1-2) Returns the greater of a and b.
3-4) Returns the greatest of the values in initializer list ilist.
The (1,3) versions use operator< to compare the values, the (2,4) versions use the given 
comparison function comp.

Return value
1-2) The greater of a and b. If they are equivalent, returns a.
3-4) The greatest value in ilist. If several values are equivalent to the greatest, returns 
the leftmost one.


https://en.cppreference.com/w/cpp/algorithm/min

Returns the smaller of the given values.

1-2) Returns the smaller of a and b.
3-4) Returns the smallest of the values in initializer list ilist.
The (1,3) versions use operator< to compare the values, the (2,4) versions use the given 
comparison function comp.

Return value
1-2) The smaller of a and b. If the values are equivalent, returns a.
3-4) The smallest value in ilist. If several values are equivalent to the smallest, returns 
the leftmost such value.

*/

int main()
{
    std::cout << "larger of 1 and 9999 is " << std::max(1, 9999) << '\n'
              << "larger of 'a', and 'b' is '" << std::max('a', 'b') << "'\n"
              << "largest of 1, 10, 50, and 200 is " << std::max({1, 10, 50, 200}) << '\n'
              << "longest of \"foo\", \"bar\", and \"hello\" is \""
              << std::max({ "foo", "bar", "hello" },
                          [](const std::string_view s1, const std::string_view s2) {
                              return s1.size() < s2.size();
                          }) << "\"\n";

    vector<float> myF = {-0.51, 1.38, 4.96, 2.87, 3.13, 0.95, 8.96};
    cout << std::max({-0.51, 1.38, 4.96, 2.87, 3.13, 0.95, 8.96}) << endl;

    // cannot do this way, the elements needed to be initialized and called inside std::max()
    // cout << std::max(myF) << endl;

    // return min element
    cout << std::min({-0.51, 1.38, 4.96, 2.87, 3.13, 0.95, 8.96}) << endl;

    return 0;
    // larger of 1 and 9999 is 9999
    // larger of 'a', and 'b' is 'b'
    // largest of 1, 10, 50, and 200 is 200
    // longest of "foo", "bar", and "hello" is "hello"
    // 8.96
    // -0.51
}
