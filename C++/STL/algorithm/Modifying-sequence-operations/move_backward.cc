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

https://en.cppreference.com/w/cpp/algorithm/move_backward

Moves the elements from the range [first, last), to another range ending at d_last. The elements are moved 
in reverse order (the last element is moved first), but their relative order is preserved.

The behavior is undefined if d_last is within (first, last]. std::move must be used instead of 
std::move_backward in that case.

*/

int main()
{
    vector<string> src{"foo", "bar", "baz"};
    vector<string> dst{"qux", "quux", "quuz", "corge"};
    vector<string> src2{"AAA", "BBB", "CCC", "DDD"};

    for_each(dst.begin(), dst.end(), [](string item){ cout << item << endl;});

    // overwrite move from src to dst
    std::move_backward(src.begin(), src.end(), dst.end());

    for_each(dst.begin(), dst.end(), [](string item){ cout << item << endl;});
    cout << "size of src after move is: " << src.size() << endl;
    for_each(src.begin(), src.end(), [](string item){ cout << item << endl;});

    // overwrite move reverse from src2 to dst
    std::move_backward(src2.rbegin(), src2.rend(), dst.end());

    for_each(dst.begin(), dst.end(), [](string item){ cout << item << endl;});
    cout << "size of src2 after move is: " << src2.size() << endl;
    for_each(src2.begin(), src2.end(), [](string item){ cout << item << endl;});

    // 2022.8.20
    // As we can see, after move, original src and src2 are empty although their size values 
    // remain same, so we cannot use size to determine whether items are already moved or not
    // the "value" of item are all gone and moved to target
    // at target side, new values will overwrite original values

    return 0;
    // qux
    // quux
    // quuz
    // corge
    // qux
    // foo
    // bar
    // baz
    // size of src after move is: 3
    // 
    //
    //
    // DDD
    // CCC
    // BBB
    // AAA
    // size of src2 after move is: 4
    // 
    //
    //
    //
}
