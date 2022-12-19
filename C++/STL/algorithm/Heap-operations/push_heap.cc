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

https://en.cppreference.com/w/cpp/algorithm/push_heap

Inserts the element at the position last-1 into the max heap defined by the range [first, last-1). 
The first version of the function uses operator< to compare the elements, the second uses the given 
comparison function comp.

Return value
(none)

*/

int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    // build up a heap
    std::make_heap(v.begin(), v.end());
 
    std::cout << "v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    // just append the new element into vector without any heap work
    v.push_back(6);
 
    std::cout << "before push_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    // now, push_heap(), which means update the last added element before
    // into the heap and update all elements accordingly
    std::push_heap(v.begin(), v.end());
 
    std::cout << "after push_heap:  ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    // what if we add more than one elements and call push_heap()?
    v.push_back(60);
    v.push_back(-45);

    std::push_heap(v.begin(), v.end());
    std::cout << "after 1st push_heap:  ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::push_heap(v.begin(), v.end());
    std::cout << "after 2nd push_heap:  ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    // we need to call make_heap() again if there are more than one element
    // added into the vector
    std::make_heap(v.begin(), v.end());
    std::cout << "after make_heap() again:  ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    return 0;
    // v: 9 5 4 1 1 3 
    // before push_heap: 9 5 4 1 1 3 6 
    // after push_heap:  9 5 6 1 1 3 4 
    // after 1st push_heap:  9 5 6 1 1 3 4 60 -45 
    // after 2nd push_heap:  9 5 6 1 1 3 4 60 -45 
    // after make_heap() again:  60 9 6 5 1 3 4 1 -45 
}
