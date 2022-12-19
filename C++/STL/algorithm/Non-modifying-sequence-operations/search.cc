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

https://en.cppreference.com/w/cpp/algorithm/search

1-4) Searches for the first occurrence of the sequence of elements [s_first, s_last) 
in the range [first, last).
1) Elements are compared using operator==.
3) Elements are compared using the given binary predicate p.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate 
in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.
5) Searches the sequence [first, last) for the pattern specified in the constructor of searcher. 
Effectively executes return searcher(first, last).first;. Searcher need not be CopyConstructible.

The standard library provides the following searchers:

default_searcher
  
(C++17)
 
standard C++ library search algorithm implementation
(class template)
boyer_moore_searcher
  
(C++17)
 
Boyer-Moore search algorithm implementation
(class template)
boyer_moore_horspool_searcher
  
(C++17)
 
Boyer-Moore-Horspool search algorithm implementation
(class template)
(since C++17)

Return value
1-4) Iterator to the beginning of first occurrence of the sequence [s_first, s_last) in the 
range [first, last). If no such occurrence is found, last is returned.
If [s_first, s_last) is empty, first is returned. (since C++11)
5) Returns the result of searcher.operator(), that is, an iterator to the location at which 
the substring is found or a copy of last if it was not found.


通过《C++ find_end()函数》一节的讲解我们知道，find_end() 函数用于在序列 A 中查找序列 B 最后一次出现的位置。
那么，如果想知道序列 B 在序列 A 中第一次出现的位置，该如何实现呢？可以借助 search() 函数。

search() 函数定义在<algorithm>头文件中，其功能恰好和 find_end() 函数相反，用于在序列 A 中查找序列 B 第一次
出现的位置。

例如，仍以如下两个序列为例：
序列 A：1,2,3,4,5,1,2,3,4,5
序列 B：1,2,3

可以看到，序列 B 在序列 A 中出现了 2 次。借助 find_end() 函数，我们可以找到序列 A 中最后一个（也就是第 2 个）
{1,2,3}；而借助 search() 函数，我们可以找到序列 A 中第 1 个 {1,2,3}。

和 find_end() 相同，search() 函数也提供有以下 2 种语法格式：
//查找 [first1, last1) 范围内第一个 [first2, last2) 子序列
ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
                        ForwardIterator first2, ForwardIterator last2);
//查找 [first1, last1) 范围内，和 [first2, last2) 序列满足 pred 规则的第一个子序列
ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
                        ForwardIterator first2, ForwardIterator last2,
                        BinaryPredicate pred);
其中，各个参数的含义分别为：
first1、last1：都为正向迭代器，其组合 [first1, last1) 用于指定查找范围（也就是上面例子中的序列 A）；
first2、last2：都为正向迭代器，其组合 [first2, last2) 用于指定要查找的序列（也就是上面例子中的序列 B）；
pred：用于自定义查找规则。该规则实际上是一个包含 2 个参数且返回值类型为 bool 的函数（第一个参数接收 [first1, last1) 
范围内的元素，第二个参数接收 [first2, last2) 范围内的元素）。函数定义的形式可以是普通函数，也可以是函数对象。
实际上，第一种语法格式也可以看做是包含一个默认的 pred 参数，该参数指定的是一种相等规则，即在 [first1, last1) 范围内
查找和 [first2, last2) 中各个元素对应相等的子序列；而借助第二种语法格式，我们可以自定义一个当前场景需要的匹配规则。

同时，search() 函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向查找到的子序列中的第一个元素；反之，如果查找失败，
则该迭代器的指向和 last1 迭代器相同。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::search
#include <vector>       // std::vector

using namespace std;

//以普通函数的形式定义一个匹配规则
bool mycomp1(int i, int j) {
    return (i%j == 0);
}

//以函数对象的形式定义一个匹配规则
class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return (i%j == 0);
    }
};

int main() {
    vector<int> myvector{ 1,2,3,4,8,12,18,1,2,3 };
    int myarr[] = { 1,2,3 };
    //调用第一种语法格式
    vector<int>::iterator it = search(myvector.begin(), myvector.end(), myarr, myarr + 3);
    if (it != myvector.end()) {
        cout << "第一个{1,2,3}的起始位置为：" << it - myvector.begin() << ",*it = " << *it << endl;
    }
    int myarr2[] = { 2,4,6 };
    //调用第二种语法格式
    it = search(myvector.begin(), myvector.end(), myarr2, myarr2 + 3, mycomp2());
    if (it != myvector.end()) {
        cout << "第一个{2,3,4}的起始位置为：" << it - myvector.begin() << ",*it = " << *it;
    }
    return 0;
}

程序执行结果为：
第一个{1,2,3}的起始位置为：0,*it = 1
第一个{2,3,4}的起始位置为：3,*it = 4

通过程序的执行结果可以看到，第 22 行代码借助 search() 函数找到了 myvector 容器中第一个 {1,2,3}，并返回了一个
指向元素 1 的迭代器（其下标位置为 0）。

而在第 29 行中，search() 函数使用的是第 2 种格式，其自定义了 mycomp2 匹配规则，即在 myvector 容器中找到第一个
连续的 3 个元素，它们能分别被 2、4、6 整除。显然，myvector 容器中符合要求的子序列有 2 个，分别为 {4,8,12} 和 
{8,12,18}，但 search() 函数只会查找到第一个，并返回指向元素 4 的迭代器（其下标为 3）。
注意，search() 函数的第一种语法格式，其底层是借助 == 运算符实现的。这意味着，如果 [first1, last1] 和 
[first2, last2] 区域内的元素为自定义的类对象或结构体变量时，使用该函数之前需要对 == 运算符进行重载。

C++ STL标准库官方给出了 search() 函数底层实现的参考代码，感兴趣的读者可自行分析，这里不再做过多描述：
纯文本复制

template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
  ForwardIterator2 first2, ForwardIterator2 last2)
{
    if (first2 == last2) return first1;
    while (first1 != last1)
    {
        ForwardIterator1 it1 = first1;
        ForwardIterator2 it2 = first2;
        while (*it1 == *it2) {    // 或者 while (pred(*it1,*it2)) 对应第二种语法格式
            if (it2 == last2) return first1;
            if (it1 == last1) return last1;
            ++it1; ++it2;
        }
        ++first1;
    }
    return last1;
}

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，
坚持原创，专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

//以普通函数的形式定义一个匹配规则
bool mycomp1(int i, int j) {
    return (i%j == 0);
}

//以函数对象的形式定义一个匹配规则
class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return (i%j == 0);
    }
};

int main()
{
    // example from http://c.biancheng.net/view/7503.html with few addons 
    vector<int> myvector{ 1,2,3,4,8,12,18,1,2,3 };
    int myarr[] = { 1,2,3 };

    for_each(myvector.begin(), myvector.end(), [](int i) { cout << i << endl; });

    //调用第一种语法格式
    vector<int>::iterator it = search(myvector.begin(), myvector.end(), myarr, myarr + 3);
    if (it != myvector.end()) {
        cout << "第一个{1,2,3}的起始位置为：" << it - myvector.begin() << ",*it = " << *it << endl;
    }
    int myarr2[] = { 2,4,6 };

    //调用第二种语法格式
    it = search(myvector.begin(), myvector.end(), myarr2, myarr2 + 3, mycomp2());
    if (it != myvector.end()) {
        cout << "第一个{2,3,4}的起始位置为：" << it - myvector.begin() << ",*it = " << *it << endl;
    }

    vector<int> test{ 2,4,5 };
    auto ret = search(myvector.begin(), myvector.end(), test.begin(), test.end());
    if (ret == myvector.end()) {
        cout << "Cannot find eact match of {2, 4, 5} from input" << endl;
    }

    // this search() function is same as find_end(), which need to be 100% match
    vector<char> s1{'x','y','z','a','b','c','x','y','z'};
    vector<char> s2{'a','b'};
    auto find_keyword = search(s1.begin(), s1.end(), s2.begin(), s2.end());
    if (find_keyword != s1.end()) {
        cout << "Found keyword in s1" << endl;
    } else {
        cout << "Keyword is not found in s1" << endl;
    }

    // 2022.8.6
    // search() will return the iterator of first matched element with 100% match between 
    // input and keyword, similar to find_end()

    return 0;
    // 1
    // 2
    // 3
    // 4
    // 8
    // 12
    // 18
    // 1
    // 2
    // 3
    // 第一个{1,2,3}的起始位置为：0,*it = 1
    // 第一个{2,3,4}的起始位置为：3,*it = 4
    // Cannot find eact match of {2, 4, 5} from input
    // Found keyword in s1
}
