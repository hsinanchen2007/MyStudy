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

https://en.cppreference.com/w/cpp/algorithm/find_first_of

Searches the range [first, last) for any of the elements in the range [s_first, s_last).

1) Elements are compared using operator==.
3) Elements are compared using the given binary predicate p.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate 
in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.

Return value
Iterator to the first element in the range [first, last) that is equal to an element 
from the range [s_first, s_last). If no such element is found, last is returned.


在某些情境中，我们可能需要在 A 序列中查找和 B 序列中任意元素相匹配的第一个元素，这时就可以使用 find_first_of() 
函数。

仅仅用一句话概述 find_first_of() 函数的功能，读者可能并不理解。别急，下面我们将从语法格式的角度继续阐述该函数
的功能。

find_first_of() 函数定义于<algorithm>头文件中，因此使用该函数之前，程序中要先引入此头文件：
#include <algorithm>

find_first_of() 函数有 2 种语法格式，分别是：
//以判断两者相等作为匹配规则
InputIterator find_first_of (InputIterator first1, InputIterator last1,
                             ForwardIterator first2, ForwardIterator last2);
//以 pred 作为匹配规则
InputIterator find_first_of (InputIterator first1, InputIterator last1,
                             ForwardIterator first2, ForwardIterator last2,
                             BinaryPredicate pred);
其中，各个参数的含义如下：
first1、last1：都为输入迭代器，它们的组合 [first1, last1) 用于指定该函数要查找的范围；
first2、last2：都为正向迭代器，它们的组合 [first2, last2) 用于指定要进行匹配的元素所在的范围；
pred：可接收一个包含 2 个形参且返回值类型为 bool 的函数，该函数可以是普通函数（又称为二元谓词函数），也可以是
函数对象。有关谓词函数，读者可阅读《C++谓词函数》一节详细了解。

find_first_of() 函数用于在 [first1, last1) 范围内查找和 [first2, last2) 中任何元素相匹配的第一个元素。
如果匹配成功，该函数会返回一个指向该元素的输入迭代器；反之，则返回一个和 last1 迭代器指向相同的输入迭代器。

值得一提的是，不同语法格式的匹配规则也是不同的：
第 1 种语法格式：逐个取 [first1, last1) 范围内的元素（假设为 A），和 [first2, last2) 中的每个元素（假设为 B）
做 A==B 运算，如果成立则匹配成功；
第 2 种语法格式：逐个取 [first1, last1) 范围内的元素（假设为 A），和 [first2, last2) 中的每个元素（假设为 B）
一起带入 pred(A, B) 谓词函数，如果函数返回 true 则匹配成功。注意，当采用第一种语法格式时，如果 [first1, last1) 
或者 [first2, last2) 范围内的元素类型为自定义的类对象或者结构体变量，此时应对 == 运算符进行重载，使其适用于当前
场景。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::find_first_of
#include <vector>       // std::vector

using namespace std;

//自定义二元谓词函数，作为 find_first_of() 函数的匹配规则
bool mycomp(int c1, int c2) {
    return (c2 % c1 == 0);
}

//以函数对象的形式定义一个 find_first_of() 函数的匹配规则
class mycomp2 {
public:
    bool operator()(const int& c1, const int& c2) {
        return (c2 % c1 == 0);
    }
};

int main() {
    char url[] = "http://c.biancheng.net/stl/";
    char ch[] = "stl";
    //调用第一种语法格式，找到 url 中和 "stl" 任一字符相同的第一个字符
    char *it = find_first_of(url, url + 27, ch, ch + 4);
    if (it != url + 27) {
        cout << "*it = " << *it << '\n';
    }
    vector<int> myvector{ 5,7,3,9 };
    int inter[] = { 4,6,8 };
    //调用第二种语法格式，找到 myvector 容器中和 3、5、7 任一元素有 c2%c1=0 关系的第一个元素
    vector<int>::iterator iter = find_first_of(myvector.begin(), myvector.end(), inter, inter + 3, mycomp2());
    if (iter != myvector.end()) {
        cout << "*iter = " << *iter;
    }
    return 0;
}

程序执行结果为：
*it = t
*iter = 3

此程序给读者演示了 find_first_of() 函数 2 种语法格式的用法。其中第 20 行代码中 find_first_of() 函数发挥的功能是，
在 url 字符数组中逐个查找和 's'、't'、'l' 这 3 个字符相等的字符，显然 url 数组第 2 个字符 't' 就符合此规则。

在第 29 行代码中，find_first_of() 会逐个提取 myvector 容器中的每个元素（假设为 A），并尝试和 inter 数组中的每个元素
（假设为 B）一起带入 mycomp2(A, B) 函数对象中。显然，当将 myvector 容器中的元素 3 和 inter 数组中的元素 6 带入该函数时，
c2 % c1=0 表达式第一次成立。

C++ STL 标准库给出了 find_first_of() 函数底层实现的参考代码，感兴趣的读者可自行分析：
纯文本复制
template<class InputIt, class ForwardIt, class BinaryPredicate>
InputIt find_first_of(InputIt first, InputIt last,
                      ForwardIt s_first, ForwardIt s_last,
                      BinaryPredicate p)
{
    for (; first != last; ++first) {
        for (ForwardIt it = s_first; it != s_last; ++it) {
            //第二种语法格式换成 if (p(*first, *it))
            if (p(*first, *it)) {
                return first;
            }
        }
    }
    return last;
}

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV1 = {6, 8, 10, 2, 4, 6, 8, 10, 12, 1, 3, 6, 8, 10, 12};
    vector<int> test1 = {1, 3, 5};
    vector<int> test2 = {10, 9, 8};

    // find_first_of() will return the first matched element from test1, and it's OK if other elements in test1
    // are not same as myV1. This is different from find_end() where the test one should be exact same in myV1
    auto ret1 = find_first_of(myV1.begin(), myV1.end(), test1.begin(), test1.end());
    if (ret1 != myV1.end()) cout << "Returned from find_end() is " << *ret1 << ", index " << distance(myV1.begin(), ret1) << endl;

    // 8 happened in myV1 three times, find_first_of() will return the first element in myV1
    auto ret2 = find_first_of(myV1.begin(), myV1.end(), test2.begin(), test2.end());
    if (ret2 != myV1.end()) cout << "Returned from find_end() is " << *ret2 << ", index " << distance(myV1.begin(), ret2) << endl;

    // 2022.8.6
    // find_first_of() will try to find any matched element from test to myV1, and return the first matched
    // element iterator. This can be used to find any first matched string/character in string question

    return 0;
    // Returned from find_end() is 1, index 9
    // Returned from find_end() is 8, index 1
}
