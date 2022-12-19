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

https://en.cppreference.com/w/cpp/algorithm/sort_heap

Converts the max heap [first, last) into a sorted range in ascending order. The resulting range 
no longer has the heap property.

The first version of the function uses operator< to compare the elements, the second uses the given 
comparison function comp.

Return value
(none)

*/

int main()
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9}; 
 
    std::make_heap(v.begin(), v.end());
 
    std::cout << "heap:\t";
    for (const auto &i : v) {
        std::cout << i << ' ';
    }   
 
    std::sort_heap(v.begin(), v.end());
 
    std::cout << "\nsorted:\t";
    for (const auto &i : v) {                                                   
        std::cout << i << ' ';
    }   
    std::cout << '\n';

    // check if the given vector is a max heap or not
    if (!std::is_heap(v.begin(), v.end(), less<int>{})) {
        std::cout << "Not max heap anymore after sort_heap()" << endl;
    }

    // sort from less to larger
    std::cout << "sort() from less to larger:\t";
    sort(v.begin(), v.end(), less<int>());
    for (const auto &i : v) {                                                   
        std::cout << i << ' ';
    }   
    std::cout << '\n';

    // sort from larger to less
    std::cout << "sort() from larger to less:\t";
    sort(v.begin(), v.end(), greater<int>());
    for (const auto &i : v) {                                                   
        std::cout << i << ' ';
    }   
    std::cout << '\n';

    // max heap
    std::make_heap(v.begin(), v.end(), less<int>());
    std::cout << "max heap:\t";
    for (const auto &i : v) {
        std::cout << i << ' ';
    }   
    std::cout << '\n';

    // min heap
    std::make_heap(v.begin(), v.end(), greater<int>());
    std::cout << "min heap:\t";
    for (const auto &i : v) {
        std::cout << i << ' ';
    }   
    std::cout << '\n';

    return 0;
    // heap:	9 5 4 1 1 3 
    // sorted:	1 1 3 4 5 9 
    // Not max heap anymore after sort_heap()
    // sort() from less to larger:	1 1 3 4 5 9 
    // sort() from larger to less:	9 5 4 3 1 1 
    // max heap:	9 5 4 3 1 1 
    // min heap:	1 1 4 3 5 9 
}
