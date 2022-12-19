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

https://en.cppreference.com/w/cpp/algorithm/find_end

Searches for the last occurrence of the sequence [s_first, s_last) in the range 
[first, last).

1) Elements are compared using operator==.
3) Elements are compared using the given binary predicate p.
2,4) Same as (1,3), but executed according to policy. These overloads do not 
participate in overload resolution unless 
std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.

Return value
Iterator to the beginning of last occurrence of the sequence [s_first, s_last) 
in range [first, last).

If no such sequence is found, last is returned. (until C++11)
If [s_first, s_last) is empty or if no such sequence is found, last is returned.
(since C++11)


find_end() 函数定义在<algorithm>头文件中，常用于在序列 A 中查找序列 B 最后一次出现的位置。
例如，有如下 2 个序列：
序列 A：1,2,3,4,5,1,2,3,4,5
序列 B：1,2,3

通过观察不难发现，序列 B 在序列 A 中出现了 2 次，而借助 find_end() 函数，可以轻松的得到序列 
A 中最后一个（也就是第 2 个） {1,2,3}。

find_end() 函数的语法格式有 2 种：
//查找序列 [first1, last1) 中最后一个子序列 [first2, last2)
ForwardIterator find_end (ForwardIterator first1, ForwardIterator last1,
                          ForwardIterator first2, ForwardIterator last2);
//查找序列 [first2, last2) 中，和 [first2, last2) 序列满足 pred 规则的最后一个子序列
ForwardIterator find_end (ForwardIterator first1, ForwardIterator last1,
                          ForwardIterator first2, ForwardIterator last2,
                          BinaryPredicate pred);
其中，各个参数的含义如下：
first1、last1：都为正向迭代器，其组合 [first1, last1) 用于指定查找范围（也就是上面例子中的序列 A）；
first2、last2：都为正向迭代器，其组合 [first2, last2) 用于指定要查找的序列（也就是上面例子中的序列 B）；
pred：用于自定义查找规则。该规则实际上是一个包含 2 个参数且返回值类型为 bool 的函数（第一个参数接收 
[first1, last1) 范围内的元素，第二个参数接收 [first2, last2) 范围内的元素）。函数定义的形式可以是
普通函数，也可以是函数对象。

实际上，第一种语法格式也可以看做是包含一个默认的 pred 参数，该参数指定的是一种相等规则，即在 
[first1, last1) 范围内查找和 [first2, last2) 中各个元素对应相等的子序列；而借助第二种语法格式，
我们可以自定义一个当前场景需要的匹配规则。

同时，find_end() 函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向查找到的子序列中的第一个元素；
反之，如果查找失败，则该迭代器的指向和 last1 迭代器相同。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::find_end
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
    vector<int>::iterator it = find_end(myvector.begin(), myvector.end(), myarr, myarr + 3);
    if (it != myvector.end()) {
        cout << "最后一个{1,2,3}的起始位置为：" << it - myvector.begin() << ",*it = " << *it << endl;
    }
    int myarr2[] = { 2,4,6 };
    //调用第二种语法格式
    it = find_end(myvector.begin(), myvector.end(), myarr2, myarr2 + 3, mycomp2());
    if (it != myvector.end()) {
        cout << "最后一个{2,3,4}的起始位置为：" << it - myvector.begin() << ",*it = " << *it;
    }
    return 0;
}

程序执行结果为：
匹配{1,2,3}的起始位置为：7,*it = 1
匹配{2,3,4}的起始位置为：4,*it = 8

上面程序中共调用了 2 次 find_end() 函数：
第 22 行代码：调用了第一种语法格式的 find_end() 函数，其功能是在 myvector 容器中查找和 {1,2,3} 
相等的最后一个子序列，显然最后一个 {1,2,3} 中元素 1 的位置下标为 7（myvector 容器下标从 0 开始）；
第 29 行代码：调用了第二种格式的 find_end() 函数，其匹配规则为 mycomp2，即在 myvector 容器中找到
最后一个子序列，该序列中的元素能分别被 {2、4、6} 中的元素整除。显然，myvector 容器中 {4,8,12} 和 
{8,12,18} 都符合，该函数会找到后者并返回一个指向元素 8 的迭代器。

注意，find_end() 函数的第一种语法格式，其底层是借助 == 运算符实现的。这意味着，如果 [first1, last1] 
和 [first2, last2] 区域内的元素为自定义的类对象或结构体变量时，使用该函数之前需要对 == 运算符进行重载。

C++ STL标准库官方给出了 find_end() 函数底层实现的参考代码，感兴趣的读者可自行分析，这里不再做过多描述：
纯文本复制
template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
  ForwardIterator2 first2, ForwardIterator2 last2)
{
    if (first2 == last2) return last1;  // specified in C++11
    ForwardIterator1 ret = last1;
    while (first1 != last1)
    {
        ForwardIterator1 it1 = first1;
        ForwardIterator2 it2 = first2;
        while (*it1 == *it2) {    // or: while (pred(*it1,*it2)) for version (2)
            ++it1; ++it2;
            if (it2 == last2) { ret = first1; break; }
            if (it1 == last1) return ret;
        }
        ++first1;
    }
    return ret;
}

另外，C++ STL 标准库还提供了和 find_end() 函数功能恰恰相反的 search() 函数，有关该函数的用法，
可阅读《C++ search() 函数》一节。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，
坚持原创，专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV1 = {6, 8, 10, 2, 4, 6, 8, 10, 12, 1, 3, 6, 8, 10, 12};
    vector<int> myV2 = {6, 8, 10};

    // {6, 8, 10} shows in myV1 three times, find_end() will return the last one starting from 6, 8, 10 in this order
    auto ret1 = find_end(myV1.begin(), myV1.end(), myV2.begin(), myV2.end());
    if (ret1 != myV1.end()) cout << "Returned from find_end() is " << *ret1 << ", index " << distance(myV1.begin(), ret1) << endl;

    // won't return in below example as no such {6, 8, 12} existed in myV1
    vector<int> myV3 = {6, 8, 12};
    auto ret2 = find_end(myV1.begin(), myV1.end(), myV3.begin(), myV3.end());
    if (ret2 != myV1.end()) cout << "Returned from find_end() is " << *ret2 << ", index " << distance(myV1.begin(), ret2) << endl;

    // 2022.8.5
    // note that the check from myV2 is strict, that means it needed to find exact match in myV1
    // if it is not 100% match, end iterator will return
    // this may be useful for string question to find last happened substring from a given string

    return 0;
    // Returned from find_end() is 6, index 11
}
