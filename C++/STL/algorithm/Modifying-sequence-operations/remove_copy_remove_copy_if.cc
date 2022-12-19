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

// for std::quoted() usage
#include <iomanip>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/remove_copy

Copies elements from the range [first, last), to another range beginning at d_first, omitting the 
elements which satisfy specific criteria. Source and destination ranges cannot overlap.

1) Ignores all elements that are equal to value.
3) Ignores all elements for which predicate p returns true.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator to the element past the last element copied.

*/

int main()
{
    // example from https://en.cppreference.com/w/cpp/algorithm/remove_copy
    std::string str = "#Return #Value #Optimization";
    std::cout << "before: " << std::quoted(str) << "\n";
 
    std::cout << "after:  \"";
    std::remove_copy(str.begin(), str.end(),
                     std::ostream_iterator<char>(std::cout), '#');
    std::cout << "\"\n";

    // example from http://c.biancheng.net/view/617.html
    using Name = std::pair<string, string>;
    std::set<Name> blacklist {Name {"Al", "Bedo"}, Name {"Ann", "Ounce"}, Name {"Jo", "King" } };
    std::deque<Name> candidates {Name {"Stan", "Down"}, Name { "Al", "Bedo"},Name {"Dan", "Druff"}, Name {"Di", "Gress"}, Name {"Ann", "Ounce"},Name {"Bea", "Gone"}};
    std::deque<Name> validated;
    std::remove_copy_if(std::begin(candidates) , std::end(candidates), std::back_inserter(validated), [&blacklist] (const Name& name) { return blacklist.count(name); });
    std::cout << endl << "After removing blocklist names: " << endl;
    for_each(validated.begin(), validated.end(), [](const Name& name){ cout << name.first << " " << name.second << endl; });

    return 0;
    // before: "#Return #Value #Optimization"
    // after:  "Return Value Optimization"
    // 
    // After removing blocklist names: 
    // Stan Down
    // Dan Druff
    // Di Gress
    // Bea Gone
}

