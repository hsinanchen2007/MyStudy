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

https://en.cppreference.com/w/cpp/algorithm/rotate_copy

1) Copies the elements from the range [first, last), to another range beginning at d_first in such a way, 
that the element *(n_first) becomes the first element of the new range and *(n_first - 1) becomes the last 
element. The behavior is undefined if either [first, n_first) or [n_first, last) is not a valid range, or 
the source and destination ranges overlap.
2) Same as (1), but executed according to policy. This overload does not participate in overload resolution 
unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Output iterator to the element past the last element copied.


rotate_copy() 算法会在新序列中生成一个序列的旋转副本，并保持原序列不变。rotate_copy() 的前 3 个参数和 copy() 是相同的；
第 4 个参数是一个输出迭代器，它指向目的序列的第一个元素。这个算法会返回一个目的序列的输出迭代器，它指向最后一个被复制元素的下一个
位置。例如：

std::vector<string> words {"one", "two", "three", "four", "five","six", "seven", "eight", "nine"，"ten"};
auto start = std::find(std::begin(words), std::end(words), "two");
auto end_iter = std::find (std::begin(words) , std::end (words) ,"eight");
std::vector<string> words_copy;
std::rotate_copy(start, std::find(std::begin(words), std::end(words),"five") , end_iter, std::back_inserter (words_copy));
std::copy(std::begin(words_copy), std::end(words_copy),std::ostream_iterator<string> {std::cout, " "});
std::cout << std::endl;

这段代码会对 word 中从 "two" 到 "seven" 的元素生成一个旋转副本。通过使用 back_insert_iterator 将复制的元素追加到 words_copy 
容器中，back_insert_iterator 会调用 words_copy 容器的成员函数 push_back() 来插入每个元素。这段代码产生的输出如下：
five six seven two three four

这里 rotate_copy() 返回的迭代器是 words_copy 中元素的结束迭代器。在这段代码中，并没有保存和使用它，但它却很有用。例如：
std::vector<string> words {"one”，"two", "three", "four", "five","six", "seven", "eight", "nine", "ten"};
auto start = std::find (std::begin(words) , std::end(words) ,"two");
auto end_iter = std::find(std::begin(words) , std::end(words),"eight"); std::vector<string> words_copy {20}; // vector with 20 default elements
auto end_copy_iter = std::rotate_copy(start,std::find(std::begin(words), std::end(words), "five"), end_iter, std::begin(words_copy));
std::copy (std::begin (words_copy),end_copy_iter, std::ostream_iterator<string>{std::cout," "});
std::cout << std::endl;

生成的 words_copy 容器默认有 20 个元素。rotate_copy() 算法现在会将现有元素的旋转序列保存到 words_copy 中。在输出时，这个算法返回
的迭代器可以用来确定 words_copy 的尾部边界；如果没有它，就必须通过源序列的元素个数来计算出尾部边界。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程
+工作记录+生活日常+编程资料。

*/

int main()
{
    std::vector<int> src = {1, 2, 3, 4, 5}; 
    std::vector<int> dest(src.size());                                          
    auto pivot = std::find(src.begin(), src.end(), 3); 
 
    std::rotate_copy(src.begin(), pivot, src.end(), dest.begin());
    for (int i : dest) {
        std::cout << i << ' ';
    }   
    std::cout << '\n';
 
    // copy the rotation result directly to the std::cout
    pivot = std::find(dest.begin(), dest.end(), 1);
    std::rotate_copy(dest.begin(), pivot, dest.end(),
                     std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    return 0;
    // 3 4 5 1 2 
    // 1 2 3 4 5 
}

