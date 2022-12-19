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

https://en.cppreference.com/w/cpp/algorithm/copy

Copies the elements in the range, defined by [first, last), to another range beginning at d_first.

1) Copies all elements in the range [first, last) starting from first and proceeding to last - 1. 
The behavior is undefined if d_first is within the range [first, last). In this case, std::copy_backward 
may be used instead.
3) Only copies the elements for which the predicate pred returns true. The relative order of the elements 
that are copied is preserved. The behavior is undefined if the source and the destination ranges overlap.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Output iterator to the element in the destination range, one past the last element copied.


copy_if() 算法可以从源序列复制使谓词返回 true 的元素，所以可以把它看作一个过滤器。前两个参数定义源序列的输入迭代器，
第三个参数是指向目的序列的第一个位置的输出迭代器，第 4 个参数是一个谓词。会返回一个输出迭代器，它指向最后一个被复制元素
的下一个位置。下面是一个使用 copy_if() 的示例：
std::vector<string> names {"A1", "Beth", "Carol", "Dan", "Eve","Fred", "George", "Harry", "Iain", "Joe"};
std::unordered_set<string> more_names {"Jean", "John"};
size_t max_length{4};
std::copy_if(std::begin(names), std::end(names), std::inserter(more_names, std::begin(more_names)), 
[max_length](const string& s) { return s.length() <= max_length;});

因为作为第 4 个参数的 lambda 表达式所添加的条件，这里的 copy_if() 操作只会复制 names 中的 4 个字符串或更少。目的容器
是一个 unordered_set 容器 more_names，它已经包含两个含有 4 个字符的名称。和前面的章节一样，insert_itemtor 会将元素
添加到限定的关联容器中。如果想要展示它是如何工作的，可以用 copy() 算法列出 more_names 的内容：
std::copy(std::begin(more_names), std::end(more_names), std::ostream iterator <string>{std::cout, " "});
std::cout << std::endl;

当然，copy_if() 的目的容器也可以是一个流迭代器：
std::vector<string> names { "Al", "Beth", "Carol", "Dan", "Eve","Fred", "George", "Harry", "Iain", "Joe"};
size_t max_length{4};
std::copy_if(std::begin(names), std::end(names), std::ostream iterator< string> {std::cout," "}, 
[max_length](const string& s) { return s.length() > max_length; });
std::cout << std::endl;

这里会将 names 容器中包含的含有 4 个以上字符的名称写到标准输出流中。这段代码会输出如下内容：
Carol George Harry

输入流迭代器可以作为 copy_if() 算法的源，也可以将它用在其他需要输入迭代器的算法上。例如：
std::unordered_set<string> names;
size_t max_length {4};
std::cout << "Enter names of less than 5 letters. Enter Ctrl+Z on a separate line to end:\n";
std::copy_if(std::istream_iterator<string>{std::cin},std:: istream iterator<string>{}, 
std::inserter(names, std::begin (names)),[max_length](const string& s) { return s.length() <= max_length; });
std::copy(std::begin(names), std::end(names), std::ostream_iterator <string>{std::cout," "});
std::cout << std::endl;
容器 names 最初是一个空的 unordered_set。只有当从标准输入流读取的姓名的长度小于或等于 4 个字符时，copy_if() 算法才会复制它们。

执行这段代码可能会产生如下输出：
Enter names of less than 5 letters. Enter Ctrl+Z on a separate line to end:
Jim Bethany Jean Al Algernon Bill Adwina Ella Frederick Don ^Z
Ella Jim Jean Al Bill Don

超过 5 个字母的姓名可以从 cin 读入，但是被忽略掉，因为在这种情况下第 4 个参数 的判定会返回 false。因此，输入的 10 个姓名里
面只有 6 个会被存储在容器中。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事
+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    std::vector<int> from_vector(10);
    std::vector<int> to_vector;

    // iota() will increase 1 based on given range
    std::iota(from_vector.begin(), from_vector.end(), 0);
 
    // perform copy operation, one interesting key point of std::back_inserter(to_vector) usage
    //  -- if we don't declare to_vector's size, and use to_vector.begin(), it will cause fatal
    //     because to_vector itself is still empty, and std::copy() will not construct an object
    //     for to_vector to append new item on it
    //  -- by using std::back_inserter(to_vector), it will help to construct and append one object
    //     into to_vector automatically, so even if we don't define the size of vector from the
    //     beginning, it will do it for caller, so there is no fatal. It is likely doing
    //     construct + push_back(new_item) to to_vector
    //  -- if we define size of to_vector at the beginning, and also use std::back_inserter(to_vector),
    //     the defined items remain same (default 0 here), and all new items will be appended to 
    //     to_vector, there is no fatal
    std::copy(from_vector.begin(), from_vector.end(),  std::back_inserter(to_vector));
    for_each(to_vector.begin(), to_vector.end(), [](int v) { cout << v << " ";});
    cout << endl;

    // now, we use STL's constructor way, we need to construct the construct_to_vector
    // at the beginning when we declare this constainer
    std::vector<int> construct_to_vector(from_vector);
    for_each(construct_to_vector.begin(), construct_to_vector.end(), [](int v) { cout << v << " ";});
    cout << endl;

    // by purpose to add all "0" into to_vector first
    to_vector.clear();
    for (int i = 0; i < 10; i++) {
        to_vector.push_back(0);
    }
    // then copy it from from_vector, now we can use to_vector.begin() because
    // to_vector already has enough size to hold all elements from_vector
    std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
    for_each(to_vector.begin(), to_vector.end(), [](int v) { cout << v << " ";});
    cout << endl;

    // by purpose to add all "0" into to_vector first
    to_vector.clear();
    for (int i = 0; i < 10; i++) {
        to_vector.push_back(0);
    }

    // now, we only copy even numbers
    std::copy_if(from_vector.begin(), from_vector.end(), to_vector.begin(), [](int v){ return (v % 2 == 0);});
    for_each(to_vector.begin(), to_vector.end(), [](int v) { cout << v << " ";});
    cout << endl;

    return 0;
    // 0 1 2 3 4 5 6 7 8 9 
    // 0 1 2 3 4 5 6 7 8 9 
    // 0 1 2 3 4 5 6 7 8 9 
    // 0 2 4 6 8 0 0 0 0 0
}
