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

https://en.cppreference.com/w/cpp/algorithm/reverse_copy

1) Copies the elements from the range [first, last) to another range beginning at d_first 
in such a way that the elements in the new range are in reverse order. Behaves as if by 
executing the assignment *(d_first + (last - first) - 1 - i) = *(first + i) once for each 
non-negative i < (last - first).
If the source and destination ranges (that is, [first, last) and [d_first, d_first+(last-first)), 
respectively) overlap, the behavior is undefined.
2) Same as (1), but executed according to policy. This overload does not participate in 
overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.

Return value
Output iterator to the element past the last element copied.


reverse_copy() 算法可以将源序列复制到目的序列中，目的序列中的元素是逆序的。定义源序列的前两个迭代器参数必须是双向迭代器。
目的序列由第三个参数指定，它是目的序列的开始迭代器，也是一个输出迭代器。如果序列是重叠的，函数的行为是未定义的。这个算法
会返回一个输出迭代器，它指向目的序列最后一个元素的下一个位置。

下面是一个使用 reverse_copy() 和 copy_if() 的示例：
// Testing for palindromes using reverse_copy()
#include <iostream>                                      // For standard streams
#include <iterator>                                      // For stream iterators and begin() and end()
#include <algorithm>                                     // For reverse_copy() and copy_if()
#include <cctype>                                        // For toupper() and isalpha()
#include <string>
using std::string;
int main()
{
    while(true)
    {
        string sentence;
        std::cout << "Enter a sentence or Ctrl+Z to end: ";
        std::getline(std::cin, sentence);
        if(std::cin.eof()) break;
        // Copy as long as the characters are alphabetic & convert to upper case
        string only_letters;
        std::copy_if(std::begin(sentence), std::end(sentence), std::back_inserter(only_letters),[](char ch) { return std::isalpha(ch); });
        std::for_each(std::begin(only_letters), std::end(only_letters), [](char& ch) { ch = toupper(ch); });
        // Make a reversed copy
        string reversed;
        std::reverse_copy(std::begin(only_letters), std::end(only_letters), std::back_inserter(reversed));
        std::cout << '"' << sentence << '"'<< (only_letters == reversed ? " is" : " is not") << " a palindrome." << std::endl;
    }
}
这个程序会检查一条语句(也可以是很多条语句)是否是回文的。回文语句是指正着读或反着读都相同的句子，前提是忽略一些像空格或标点这样的细节。
while 使我们可以检查尽可能多的句子。用 getline() 读一条句子到 sentence 中。如果读到 Ctrl+Z，输入流中会设置 1 个EOF标志，它会
结束循环。用 copy_if() 将 sentence 中的字母复制到 only_letters。这个 lambda 表达式只在参数是学母时返回 true，所以其他的任何
字符都会被忽略。然后用 back_inserter() 生成的 back_insert_iterator 对象将这些字符追加到 only_letter。

for_each() 算法会将三个参数指定的函数对象应用到前两个参数定义的序列的元素上，因此这里会将 only_letters 中的字符全部转换为大写。
然后用 reverse_copy() 算法生成和 only_letters 的内容相反的内容。比较 only_letters 和 reversed 来判断输入的语句是否为回文。

该程序的输出结果为：
Enter a sentence or Ctrl+Z to end: Lid off a daffodil.
"Lid off a daffodil." is a palindrome.
Enter a sentence or Ctrl+Z to end: Engaga le jeu que je le gagne.
"Engaga le jeu que je le gagne." is not a palindrome.
Enter a sentence or Ctrl+Z to end: ^Z

reverse() 算法可以在原地逆序它的两个双向迭代器参数所指定序列的元素。可以如下 所示用它来代替上述程序中的 reverse_copy():
string reversed {only_letters};
std::reverse(std::begin(reversed), std::end(reversed));
这两条语句会替换上述程序中 reversed 的定义和 reverse_copy() 调用。它们生成一个 only_letters 的副本 reversed，然后调用 
reverse() 原地逆序 reversed 中的字符序列。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事
+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    auto print = [](std::vector<int> const& v) { 
        for (const auto& value : v)
            std::cout << value << ' ';
        std::cout << '\t';
    };
 
    std::vector<int> v({1,2,3});
    print(v);
 
    std::vector<int> destination(3);
    std::reverse_copy(std::begin(v), std::end(v), std::begin(destination));
    print(destination);
 
    // Note, again, like reverse(), if we use rbegin()/rend(), its behavior is still reverse current elements 
    // in the container, not reverse them based on from rbegin()/rend()
    std::reverse_copy(std::rbegin(v), std::rend(v), std::begin(destination));
    print(destination);
    std::cout << '\n';

    return 0;
    // 1 2 3   3 2 1   1 2 3 
}

