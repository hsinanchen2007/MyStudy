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
#include <string_view>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/make_heap

Constructs a max heap in the range [first, last). The first version of the function uses operator< to 
compare the elements, the second uses the given comparison function comp.

Return value
(none)

*/

void print(std::string_view text, std::vector<int> const& v = {}) {
    std::cout << text << ": ";
    for (const auto& e : v) std::cout << e << ' ';
    std::cout << '\n';
}

int main()
{
    print("Max heap");
 
    std::vector<int> v { 3, 2, 4, 1, 5, 9 };
    print("initially, v", v);

    // build up a max heap
    std::make_heap(v.begin(), v.end());
    print("after make_heap, v", v);
 
    // pop out the max element, and it will update the heap automatically
    std::pop_heap(v.begin(), v.end());
    print("after pop_heap, v", v);
 
    auto top = v.back();
    v.pop_back();
    print("former top element", {top});
    print("after removing the former top element, v", v);
 
    print("\nMin heap");
 
    std::vector<int> v1 { 3, 2, 4, 1, 5, 9 };
    print("initially, v1", v1);

    // build up a min heap, note that by default make_heap() will do max heap unless 
    // below compare function specified, std::greater<>{}
    std::make_heap(v1.begin(), v1.end(), std::greater<>{});
    print("after make_heap, v1", v1);
 
    // pop out the min element, and it will update the heap automatically
    std::pop_heap(v1.begin(), v1.end(), std::greater<>{});
    print("after pop_heap, v1", v1);
 
    auto top1 = v1.back();
    v1.pop_back();
    print("former top element", {top1});
    print("after removing the former top element, v1", v1);

    return 0;
    // compiled by "g++ --std=c++17 -g make_heap.cc"
    // Max heap: 
    // initially, v: 3 2 4 1 5 9 
    // after make_heap, v: 9 5 4 1 2 3 
    // after pop_heap, v: 5 3 4 1 2 9 
    // former top element: 9 
    // after removing the former top element, v: 5 3 4 1 2 
    //
    // Min heap: 
    // initially, v1: 3 2 4 1 5 9 
    // after make_heap, v1: 1 2 4 3 5 9 
    // after pop_heap, v1: 2 3 4 9 5 1 
    // former top element: 1 
    // after removing the former top element, v1: 2 3 4 9 5 
}
