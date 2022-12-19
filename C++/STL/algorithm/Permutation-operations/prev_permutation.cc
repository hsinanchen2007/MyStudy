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

https://en.cppreference.com/w/cpp/algorithm/prev_permutation

Transforms the range [first, last) into the previous permutation from the set of all permutations 
that are lexicographically ordered with respect to operator< or comp. Returns true if such permutation 
exists, otherwise transforms the range into the last permutation (as if by std::sort(first, last); 
std::reverse(first, last);) and returns false.

Return value
true if the new permutation precedes the old in lexicographical order. false if the first permutation 
was reached and the range was reset to the last permutation.


next_permutation() 是按照字典升序的方式生成的排列。当我们想以降序的方式生成排列时，可以使用 prev_permutation()。

prev_permutation 和 next_permutation() 一样有两个版本，默认使用 < 来比较元素。因为排列是以降序的方式生成的，所以
算法大多数时候会返回 true。当生成最大排列时，返回 false。例如：

std::vector<double> data {44.5, 22.0, 15.6, 1.5};
do {
    std::copy(std::begin(data), std::end(data), std::ostream_iterator<double> {std::cout, " "});
    std::cout << std::endl;
} while(std::prev_permutation(std::begin(data), std::end(data)));

这段代码会输出 data 中 4 个 double 值的全部 24 种排列，因为初始序列是最大排列，所以 prev_permutation() 会在输入
最小排列时，才返回 false。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享
创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    std::string s="abc";
    std::sort(s.begin(), s.end(), std::greater<char>());
    do {
        std::cout << s << ' ';
    } while(std::prev_permutation(s.begin(), s.end()));
    std::cout << '\n';

    return 0;
    // cba cab bca bac acb abc
}
