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

https://en.cppreference.com/w/cpp/algorithm/pop_heap

Swaps the value in the position first and the value in the position last-1 and makes the subrange [first, last-1) 
into a heap. This has the effect of removing the first element from the heap defined by the range [first, last).

The first version of the function uses operator< to compare the elements, which makes the heap a max heap. The second 
uses the given comparison function comp.

Return value
(none)

*/

int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    std::make_heap(v.begin(), v.end());
 
    std::cout << "v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    // moves the largest to the end, so the last element will be the largest one
    // note that all elements in the heap will be updated accordingly
    std::pop_heap(v.begin(), v.end()); 
 
    std::cout << "after pop_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    int largest = v.back();
    v.pop_back();  // actually removes the largest element
    std::cout << "largest element: " << largest << '\n';
 
    std::cout << "heap without largest: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    return 0;
    // v: 9 5 4 1 1 3 
    // after pop_heap: 5 3 4 1 1 9 
    // largest element: 9
    // heap without largest: 5 3 4 1 1 
}
