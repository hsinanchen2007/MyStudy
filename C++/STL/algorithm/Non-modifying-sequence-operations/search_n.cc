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

https://en.cppreference.com/w/cpp/algorithm/search_n

Searches the range [first, last) for the first sequence of count identical elements, 
each equal to the given value.

1) Elements are compared using operator==.
3) Elements are compared using the given binary predicate p.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate 
in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.

Return value
Iterator to the beginning of the found sequence in the range [first, last). If no such 
sequence is found, last is returned. If count is zero or negative, first is returned.


《C++ search()函数》一节中，已经详细介绍了 search() 函数的功能和用法。在此基础上，本节再介绍一个功能类似
的函数，即 search_n() 函数。

和 search() 一样，search_n() 函数也定义在<algorithm>头文件中，用于在指定区域内查找第一个符合要求的子序列。
不同之处在于，前者查找的子序列中可包含多个不同的元素，而后者查找的只能是包含多个相同元素的子序列。

关于 search() 函数和 search_n() 函数的区别，给大家举个例子，下面有 3 个序列：
序列 A：1,2,3,4,4,4,1,2,3,4,4,4
序列 B：1,2,3
序列 C：4,4,4

如果想查找序列 B 在序列 A 中第一次出现的位置，就只能使用 search() 函数；而如果想查找序列 C 在序列 A 中第一次
出现的位置，既可以使用 search() 函数，也可以使用 search_n() 函数。

search_n() 函数的语法格式如下：
//在 [first, last] 中查找 count 个 val 第一次连续出现的位置
ForwardIterator search_n (ForwardIterator first, ForwardIterator last,
                          Size count, const T& val);
//在 [first, last] 中查找第一个序列，该序列和 count 个 val 满足 pred 匹配规则
ForwardIterator search_n ( ForwardIterator first, ForwardIterator last,
                           Size count, const T& val, BinaryPredicate pred );
其中，各个参数的含义分别为：
first、last：都为正向迭代器，其组合 [first, last) 用于指定查找范围（也就是上面例子中的序列 A）；
count、val：指定要查找的元素个数和元素值，以上面的序列 B 为例，该序列实际上就是 3 个元素 4，其中 count 为 3，
val 为 4；
pred：用于自定义查找规则。该规则实际上是一个包含 2 个参数且返回值类型为 bool 的函数（第一个参数接收[first, last) 
范围内的元素，第二个参数接收 val）。函数定义的形式可以是普通函数，也可以是函数对象。
实际上，第一种语法格式也可以看做是包含一个默认的 pred 参数，该参数指定的是一种相等规则，即在 [first, last) 
范围内查找和 count 个 val 相等的子序列；而借助第二种语法格式，我们可以自定义一个当前场景需要的匹配规则。

同时，search_n() 函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向查找到的子序列中的第一个元素；反之，
如果查找失败，则该迭代器的指向和 last 迭代器相同。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::search_n
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
    int a[] = { 1,2,3,4,4,4,1,2,3,4,4,4 };
    //调用第一种语法格式,查找 myvector 容器中第一个 {4,4,4}
    int * it = search_n(a, a+12, 3, 4);
    if (it != a+12) {
        cout << "one：" << it - a << ",*it = " << *it << endl;
    }
    vector<int> myvector{1,2,4,8,3,4,6,8};
    //调用第二种语法格式，以自定义的 mycomp2 作为匹配规则，查找 myvector 容器中和 {16,16,16} 满足 mycomp2 规则的序列
    vector<int>::iterator iter = search_n(myvector.begin(), myvector.end(), 3, 2, mycomp2());
    if (iter != myvector.end()) {
        cout << "two：" << iter - myvector.begin() << ",*iter = " << *iter;
    }
    return 0;
}

程序执行结果为：
one：3,*it = 4
two：1,*iter = 2

程序中先后调用了 2 种语法格式的 search_n() 函数，其中第 28 行代码中，search_n() 函数不再采用默认的相等匹配规则，
而是采用了自定义了 mycomp2 匹配规则。这意味着，该函数会去 myvector 容器中查找一个子序列，该序列中的 3 个元素都满足
和 2 有 (i%j == 0) 的关系。显然，myvector 容器中符合条件的子序列有 2 个，分别为 {2,4,8} 和 {4,6,8}，但 
search_n() 函数只会查找到 {2,4,8}。

注意，search_n() 函数的第一种语法格式，其底层是借助 == 运算符实现的。这意味着，如果 [first, last] 区域内的元素为自定义
的类对象或结构体变量时，使用此格式的 search_n() 函数之前，需要对 == 运算符进行重载。

C++ STL标准库官方给出了 search_n() 函数底层实现的参考代码，感兴趣的读者可自行分析，这里不再做过多描述：
template<class ForwardIterator, class Size, class T>
ForwardIterator search_n (ForwardIterator first, ForwardIterator last,
                            Size count, const T& val)
{
    ForwardIterator it, limit;
    Size i;
    limit=first; std::advance(limit,std::distance(first,last)-count);
    while (first!=limit)
    {
        it = first; i=0;
        while (*it==val)       // 或者 while (pred(*it,val))，对应第二种格式
        { ++it; if (++i==count) return first; }
        ++first;
    }
    return last;
}
关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    const char sequence[] = "100101010001010100001010101";

    // convert to string for input. can't use to_string() as it is used to convert numeric value
    cout << "Input : { " << string(sequence) << " }"<< endl;

    // find 0 from sequence
    auto ret1 = search_n(begin(sequence), end(sequence), 1 /* counter */, '0' /* value to check*/);
    cout << "Found 0 in the sequence from index " << distance(begin(sequence), ret1) << endl;

    // find 00 from sequence
    auto ret2 = search_n(begin(sequence), end(sequence), 2 /* counter */, '0' /* value to check*/);
    cout << "Found 00 in the sequence from index " << distance(begin(sequence), ret2) << endl;

    // find 000 from sequence
    auto ret3 = search_n(begin(sequence), end(sequence), 3 /* counter */, '0' /* value to check*/);
    cout << "Found 000 in the sequence from index " << distance(begin(sequence), ret3) << endl;

    // find 0000 from sequence
    auto ret4 = search_n(begin(sequence), end(sequence), 4 /* counter */, '0' /* value to check*/);
    cout << "Found 0000 in the sequence from index " << distance(begin(sequence), ret4) << endl;

    // 2022.8.6
    // this function will specify the target and number of times showing up in the given input
    // while find_first_of() will return the first target immediately once it is found

    return 0;
    // Input : { 100101010001010100001010101 }
    // Found 0 in the sequence from index 1
    // Found 00 in the sequence from index 1
    // Found 000 in the sequence from index 8
    // Found 0000 in the sequence from index 16
}
