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

https://en.cppreference.com/w/cpp/algorithm/adjacent_find

Searches the range [first, last) for two consecutive equal elements.

1) Elements are compared using operator==.
3) Elements are compared using the given binary predicate p.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate 
in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.

Return value
an iterator to the first of the first pair of identical elements, that is, the first iterator 
it such that *it == *(it+1) for the first version or p(*it, *(it + 1)) != false for the second 
version. If no such elements are found, last is returned


adjacent_find() 函数用于在指定范围内查找 2 个连续相等的元素。该函数的语法格式为：
//查找 2 个连续相等的元素
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last);
//查找 2 个连续满足 pred 规则的元素
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last,
                               BinaryPredicate pred);
其中，first 和 last 都为正向迭代器，其组合 [first, last) 用于指定该函数的查找范围；pred 用于接收一个包含 
2 个参数且返回值类型为 bool 的函数，以实现自定义查找规则。值得一提的是，pred 参数接收的函数既可以定义为普通函数，
也可以用函数对象的形式定义。有关谓词函数，读者可阅读《C++谓词函数》一节详细了解。

另外，该函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向的是连续相等元素的第 1 个元素；而如果查找失败，
该迭代器的指向和 last 迭代器相同。

值得一提的是，adjacent_find() 函数定义于<algorithm>头文件中，因此使用该函数之前，程序中要先引入此头文件：

#include <algorithm>
举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::adjacent_find
#include <vector>       // std::vector

using namespace std;

//以创建普通函数的形式定义一个查找规则
bool mycomp1(int i, int j) {
    return (i == j);
}

//以函数对象的形式定义一个查找规则
class mycomp2{
public:
    bool operator()(const int& _Left, const int& _Right){
        return (_Left == _Right);
    }
};

int main() {
    std::vector<int> myvector{ 5,20,5,30,30,20,10,10,20 };
    //调用第一种语法格式
    std::vector<int>::iterator it = adjacent_find(myvector.begin(), myvector.end());
    if (it != myvector.end()) {
        cout << "one : " << *it << '\n';
    }
    //调用第二种格式，也可以使用 mycomp1
    it = adjacent_find(++it, myvector.end(), mycomp2());
    if (it != myvector.end()) {
        cout << "two : " << *it;
    }
    return 0;
}

程序执行结果为：
one : 30
two : 10

可以看到，程序中调用了 2 次 adjacent_find() 函数：
第 19 行：使用该函数的第一种语法格式，查找整个 myvector 容器中首个连续 2 个相等的元素，显然最先找到的是 30；
第 25 行：使用该函数的第二种语法格式，查找 {30,20,10,10,20} 部分中是否有连续 2 个符合 mycomp2 规则的元素。
不过，程序中自定义的 mycomp1 或 mycomp2 查找规则也是查找 2 个连续相等的元素，因此最先找到的是元素 10。
注意，对于第一种语法格式的 adjacent_find() 函数，其底层使用的是 == 运算符来判断连续 2 个元素是否相等。
这意味着，如果指定区域内的元素类型为自定义的类对象或者结构体变量时，需要先对 == 运算符进行重载，然后才能使用此函数。

C++ STL标准库官方给出了 adjacent_find() 函数底层实现的参考代码，感兴趣的读者可自行分析，这里不再做过多描述：
template <class ForwardIterator>
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last)
{
    if (first != last)
    {
        ForwardIterator next=first; ++next;
        while (next != last) {
            if (*first == *next)     // 或者 if (pred(*first,*next)), 对应第二种语法格式
                return first;
        ++first; ++next;
        }
    }
    return last;
}
关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV1 = {1, 3, 5, 7, 2, 4, 6, 6, 6, 6, 8, 10, 10};

    // there are two adjacent elements, 6 and 10, and this function will return the first
    // adjacent element
    auto ret1 = adjacent_find(myV1.begin(), myV1.end());
    if (ret1 != myV1.end()) {
        cout << "The first adjacent matched element is " << *ret1 << " at index " << distance(myV1.begin(), ret1) << endl;
    }

    // if we want to search the last adjacent elements, we can use below way
    // note that the corresponding check or function will need to use same rbegin()/rend()
    auto ret2 = adjacent_find(myV1.rbegin(), myV1.rend());
    if (ret2 != myV1.rend()) {
        cout << "The first reverse adjacent matched element is " << *ret2 << " at index " << distance(myV1.rbegin(), ret2) << endl;
    }

    // 2022.8.6
    // this function doesn't require a sorted input

    return 0;
    // The first adjacent matched element is 6 at index 6
    // The first reverse adjacent matched element is 10 at index 0
}
