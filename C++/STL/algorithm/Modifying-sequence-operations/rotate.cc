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

https://en.cppreference.com/w/cpp/algorithm/rotate

1) Performs a left rotation on a range of elements.
Specifically, std::rotate swaps the elements in the range [first, last) in such a way that the element 
n_first becomes the first element of the new range and n_first - 1 becomes the last element.
A precondition of this function is that [first, n_first) and [n_first, last) are valid ranges.
2) Same as (1), but executed according to policy. This overload does not participate in overload resolution 
unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
(none) (until C++11)
Iterator to the new location of the element pointed by first. Equal to first + (last - n_first) (since C++11)


rotate() 算法会从左边选择序列的元素。它的工作机制如图 1 所示。


图 1 rotate()算法的工作方式(点此查看大图)

为了理解如何旋转序列，可以将序列中的元素想象成手镯上的珠子。rotate() 操作会导致一个新元素成为开始迭代器所指向的第一个元素。
在旋转之后，最后一个元素会在新的第一个元素之前。

rotate() 的第一个参数是这个序列的开始迭代器；第二个参数是指向新的第一个元素的迭代器，它必定在序列之内。第三个参数是这个序列
的结束迭代器。图 1 中的示例说明在容器 ns 上的旋转操作使值为 4 的元素成为新的第一个元素，最后一个元素的值为 3。元素的圆形序列
会被维持，因此可以有效地旋转元素环，直到新的第一个元素成为序列的开始。这个算法会返回一个迭代器，它指向原始的第一个元素所在的
新位置。例如：

std::vector<string> words { "one", "two", "three", "four", "five","six", "seven", "eight"};
auto iter = std::rotate(std::begin(words), std::begin(words)+3, std::end(words));
std::copy(std::begin(words), std::end(words),std::ostream_iterator<string> {std::cout, " "});
std::cout << std::endl << "First element before rotation: " << *iter << std::endl;

这段代码对 words 中的所有元素进行了旋转。执行这段代码会生成如下内容：
four five six seven eight one two three
First element before rotation: one

输出说明 "four" 成为新的第一个元素，而且 rotate() 返回的迭代器指向之前的第一个元素"one"。

当然，不需要对容器中的全部元素进行旋转。例如：
std::vector<string> words { "one", "two", "three", "four", "five","six", "seven", "eight", "nine", "ten"};
auto start = std::find(std:rbegin(words), std::end(words), "two");
auto end_iter = std::find(std::begin(words), std::end(words), "eight");
auto iter = std::rotate(start, std::find(std::begin(words), std::end (words), "five") , end_iter);
std::copy(std::begin(words), std::end(words), std::ostream_iterator<string>{std::cout, " "});
std::cout << std::endl << "First element before rotation: " << *iter << std::endl;
这里用 find() 算法分别获取了和"two"、"eight"匹配的元素的迭代器。它们定义了被旋转的序列，这个序列是容器元素的子集。这个序列会
被旋转为使"five"成为第一个元素，输出说明它是按预期工作的：

one five six seven two three four eight nine ten
First element before rotation: two

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事
+学习历程+工作记录+生活日常+编程资料。

*/

auto print = [](auto const& remark, auto const& v) {
    std::cout << remark;
    for (int n: v)
        std::cout << n << ' ';
    std::cout << '\n';
};
 
int main()
{
    std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
 
    print("before sort:\t\t", v);
 
    // insertion sort
    for (auto i = v.begin(); i != v.end(); ++i) {
        std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
    }
 
    print("after sort:\t\t", v);
 
    // simple rotation to the left
    std::rotate(v.begin(), v.begin() + 1, v.end());
 
    print("simple rotate left:\t", v);
 
    // simple rotation to the right
    std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
 
    print("simple rotate right:\t", v);

    return 0;
    // before sort:            2 4 2 0 5 10 7 3 7 1 
    // after sort:             0 1 2 2 3 4 5 7 7 10 
    // simple rotate left:     1 2 2 3 4 5 7 7 10 0 
    // simple rotate right:    0 1 2 2 3 4 5 7 7 10 
}
