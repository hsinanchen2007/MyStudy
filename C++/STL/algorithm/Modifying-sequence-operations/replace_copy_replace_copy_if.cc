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

https://en.cppreference.com/w/cpp/algorithm/replace_copy

Copies the elements from the range [first, last) to another range beginning at d_first replacing all 
elements satisfying specific criteria with new_value. The source and destination ranges cannot overlap.

1) Replaces all elements that are equal to old_value.
3) Replaces all elements for which predicate p returns true.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator to the element past the last element copied.

*/

int main()
{
    std::vector<int> v{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    // replace_copy_if() number larger than 5 to 99
    std::replace_copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), [](int n){return n > 5;}, 99);
    cout << endl;

    // replace_copy(), replace 5 to 99
    std::vector<int> v2{1, 2, 3, 4, 5, 5, 5, 5, 5, 4, 3, 2, 1};
    std::vector<int> result;

    // use back_inster() to add new copied elements into result vector
    // the "ret" is type of std::back_insert_iterator<std::vector<int>>
    auto ret = std::replace_copy(v2.begin(), v2.end(), back_inserter(result), 5, 99);
    for_each(result.begin(), result.end(), [](int v){ cout << v << " "; });
    cout << endl;

    return 0;
    // 5 99 4 2 99 99 1 99 0 3 
    // 1 2 3 4 99 99 99 99 99 4 3 2 1 
}

