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
#include <random>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/iter_swap

Swaps the values of the elements the given iterators are pointing to.

Return value
(none)

*/

template<class ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end)
{
    for (ForwardIt i = begin; i != end; ++i)
        std::iter_swap(i, std::min_element(i, end));
}
 
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-9, +9);
    std::vector<int> v;
    std::generate_n(back_inserter(v), 20, bind(dist, gen));
 
    std::cout << "Before sort: " << std::showpos;
    for(auto e : v) std::cout << e << ' ';
 
    selection_sort(v.begin(), v.end());
 
    std::cout << "\nAfter sort : ";
    for(auto e : v) std::cout << e << ' ';
    std::cout << '\n';

    return 0;
    // compile with g++ --std=c++2a -g iter_swap.cc
    // Before sort: -7 -2 +2 -4 +3 +5 +2 -6 +9 +5 +1 -8 +1 +5 +6 -9 +1 -3 -6 -3 
    // After sort : -9 -8 -7 -6 -6 -4 -3 -3 -2 +1 +1 +1 +2 +2 +3 +5 +5 +5 +6 +9 
}
