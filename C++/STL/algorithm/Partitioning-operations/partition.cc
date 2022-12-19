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

https://en.cppreference.com/w/cpp/algorithm/partition

1) Reorders the elements in the range [first, last) in such a way that all elements for which the 
predicate p returns true precede the elements for which predicate p returns false. Relative order 
of the elements is not preserved.
2) Same as (1), but executed according to policy. This overload does not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator to the first element of the second group.

*/

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if(first == last) return;
    auto pivot = *std::next(first, std::distance(first,last)/2);
    auto middle1 = std::partition(first, last, [pivot](const auto& em) {
        return em < pivot;
    });
    auto middle2 = std::partition(middle1, last, [pivot](const auto& em) {
        return !(pivot < em);
    });
    quicksort(first, middle1);
    quicksort(middle2, last);
} 

int main()
{
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "Original vector:\n    ";
    for(int elem : v) std::cout << elem << ' ';
 
    // partition the given vector into two groups, even then odd
    auto it = std::partition(v.begin(), v.end(), [](int i){return i % 2 == 0;});
 
    std::cout << "\nPartitioned vector:\n    ";
    std::copy(std::begin(v), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << " * " " ";
    std::copy(it, std::end(v), std::ostream_iterator<int>(std::cout, " "));
 
    std::forward_list<int> fl = {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
    std::cout << "\nUnsorted list:\n    ";
    for(int n : fl) std::cout << n << ' ';
    std::cout << '\n';  
 
    // quick sort
    quicksort(std::begin(fl), std::end(fl));
    std::cout << "Sorted using quicksort:\n    ";
    for(int fi : fl) std::cout << fi << ' ';
    std::cout << '\n';
    return 0;
    // Original vector:
    //  0 1 2 3 4 5 6 7 8 9 
    // Partitioned vector:
    //  0 8 2 6 4  *  5 3 7 1 9 
    // Unsorted list:
    //  1 30 -4 3 5 -4 1 6 -8 2 -5 64 1 92 
    // Sorted using quicksort:
    //  -8 -5 -4 -4 1 1 1 2 3 5 6 30 64 92 
}
