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

https://en.cppreference.com/w/cpp/algorithm/count

Returns the number of elements in the range [first, last) satisfying specific criteria.

1) counts the elements that are equal to value.
3) counts elements for which predicate p returns true.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate 
in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.

Return value
number of elements satisfying the condition.

Complexity
exactly last - first comparisons / applications of the predicate

*/

int main()
{
    vector<int> myV = {1, 3, 3, 3, 3, 3, 3, 4, 5, 7, 9, 10};

    // count()
    cout << "Number of 3 in myV vector is " << count(myV.begin(), myV.end(), 3) << endl;
    cout << "Number of 11 in myV vector is " << count(myV.begin(), myV.end(), 11) << endl;

    // count_if()
    cout << "Number equal or larger than 7 in myV vector is " << count_if(myV.begin(), myV.end(), [](int value){ return (value >= 7); }) << endl;

    // 2022.7.31
    // when we need lambdas function, we need to use count_if(). count() can only hold a specific value

    return 0;
}
