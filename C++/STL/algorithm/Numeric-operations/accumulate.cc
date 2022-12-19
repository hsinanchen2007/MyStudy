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

https://en.cppreference.com/w/cpp/algorithm/accumulate

Computes the sum of the given value init and the elements in the range [first, last). The first version 
uses operator+ to sum up the elements, the second version uses the given binary function op, both applying 
std::move to their operands on the left hand side (since C++20).

op must not have side effects. (until C++11)

op must not invalidate any iterators, including the end iterators, nor modify any elements of the range 
involved, nor *last. (since C++11)

*/

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // the initialized sum is 0, then sum up all numbers
    int sum = std::accumulate(v.begin(), v.end(), 0);
 
    // the initialized product is 1, then perform the std::multiplies<int>()
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
 
    // customized function used by std::accumulate() below
    auto dash_fold = [](std::string a, int b) {
                         return std::move(a) + '-' + std::to_string(b);
                     };
 
    std::string s = std::accumulate(std::next(v.begin()), v.end(),
                                    std::to_string(v[0]), // start with first element
                                    dash_fold);
 
    // Right fold using reverse iterators
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
                                     std::to_string(v.back()), // start with last element
                                     dash_fold);
 
    std::cout << "sum: " << sum << '\n'
              << "product: " << product << '\n'
              << "dash-separated string: " << s << '\n'
              << "dash-separated string (right-folded): " << rs << '\n';

    return 0;
    // sum: 55
    // product: 3628800
    // dash-separated string: 1-2-3-4-5-6-7-8-9-10
    // dash-separated string (right-folded): 10-9-8-7-6-5-4-3-2-1
}
