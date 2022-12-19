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
#include <cstdint>
#include <iomanip>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/clamp

1) If v compares less than lo, returns lo; otherwise if hi compares less than v, returns hi; 
otherwise returns v. Uses operator< to compare the values.
2) Same as (1), but uses comp to compare the values.
The behavior is undefined if the value of lo is greater than hi.

Return value
Reference to lo if v is less than lo, reference to hi if hi is less than v, otherwise reference 
to v.

*/

int main()
{
    std::cout << " raw   clamped to int8_t   clamped to uint8_t\n";
    for(int const v: {-129, -128, -1, 0, 42, 127, 128, 255, 256}) {
        std::cout << std::setw(04) << v
                  << std::setw(20) << std::clamp(v, INT8_MIN, INT8_MAX)
                  << std::setw(21) << std::clamp(v, 0, UINT8_MAX) << '\n';
    }

    return 0;
    // raw   clamped to int8_t   clamped to uint8_t
    // -129                -128                    0
    // -128                -128                    0
    //   -1                  -1                    0
    //    0                   0                    0
    //   42                  42                   42
    //  127                 127                  127
    //  128                 127                  128
    //  255                 127                  255
    //  256                 127                  255
}
