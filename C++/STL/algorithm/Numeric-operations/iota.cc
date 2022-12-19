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

https://en.cppreference.com/w/cpp/algorithm/iota

Fills the range [first, last) with sequentially increasing values, starting with value 
and repetitively evaluating ++value.

Equivalent operation:
*(first)   = value;
*(first+1) = ++value;
*(first+2) = ++value;
*(first+3) = ++value;
...

Return value
(none)

*/

int main()
{
    vector<int> myV(10);

    // +1 based on given condition
    iota(myV.begin(), myV.end(), 1);
    for_each(myV.begin(), myV.end(), [](int v){ cout << v << " "; });
    cout << endl;

    // +5 based on given condition
    // Note that the given condition value "5" means the "starting value", not means increase by value
    // and every time we call iota, it will be initialized based on the given condition value
    iota(myV.begin(), myV.end(), 5);
    for_each(myV.begin(), myV.end(), [](int v){ cout << v << " "; });
    cout << endl;

    iota(myV.begin(), myV.end(), 20);
    for_each(myV.begin(), myV.end(), [](int v){ cout << v << " "; });
    cout << endl;

    return 0;
    // 1 2 3 4 5 6 7 8 9 10 
    // 5 6 7 8 9 10 11 12 13 14 
    // 20 21 22 23 24 25 26 27 28 29
}
