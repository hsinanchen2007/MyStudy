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

https://en.cppreference.com/w/cpp/algorithm/partition_point

Examines the partitioned (as if by std::partition) range [first, last) and locates the end of 
the first partition, that is, the first element that does not satisfy p or last if all elements 
satisfy p.

在前面章节中，我们系统学习了 partition()、stable_partition() 和 partition_copy() 这 3 个函数，它们的功能
本质上都是根据某个筛选规则对指定范围内的数据进行分组（即符合条件的为一组，不符合条件的为另一组），并且反馈给我们两组
数据之间的分界位置。

事实上，有些数据本身就已经是按照某个筛选规则分好组的，例如：
1,2,3,4,5,6,7      <-- 根据规则 i<4，{1,2,3} 为一组，{4,5,6,7} 为另一组
2,4,6,8,1,3,5,7,9  <-- 根据规则 i%2=0，{2,4,6,8} 为一组，{1,3,5,7,9} 为另一组

类似上面这样已经“分好组”的数据，在使用时会有一个问题，即不知道两组数据之间的分界在什么位置。有读者可能想到，再调用
一次 partition()、stale_partition() 或者 partition_copy() 不就可以了吗？这种方法确实可行，但对已经分好组的
数据再进行一次分组，是没有任何必要的。

实际上，对于如何在已分好组的数据中找到分界位置，C++ 11标准库提供了专门解决此问题的函数，即 partition_point() 函数。

partition_point() 函数定义在<algorithm>头文件中，其语法格式为：
ForwardIterator partition_point (ForwardIterator first, ForwardIterator last,
                                 UnaryPredicate pred);
其中，first 和 last 为正向迭代器，[first, last) 用于指定该函数的作用范围；pred 用于指定数据的筛选规则。
所谓筛选规则，其实就是包含 1 个参数且返回值类型为 bool 的函数，此函数可以是一个普通函数，也可以是一个函数对象。

同时，该函数会返回一个正向迭代器，该迭代器指向的是 [first, last] 范围内第一个不符合 pred 筛选规则的元素。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::partition_point
#include <vector>       // std::vector

using namespace std;

//以普通函数的方式定义筛选规则
bool mycomp(int i) { return (i % 2) == 0; }

//以函数对象的形式定义筛选规则
class mycomp2 {
public:
    bool operator()(const int& i) {
        return (i % 2 == 0);
    }
};

int main() {
    vector<int> myvector{ 2,4,6,8,1,3,5,7,9 };
    //根据 mycomp 规则，为 myvector 容器中的数据找出分界
    vector<int>::iterator iter = partition_point(myvector.begin(), myvector.end(),mycomp);
    //输出第一组的数据
    for (auto it = myvector.begin(); it != iter; ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    //输出第二组的数据
    for (auto it = iter; it != myvector.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n*iter = " << *iter;
    return 0;
}
程序执行结果为：
2 4 6 8
1 3 5 7 9
*iter = 1

通过分析程序并结合输出结果可以看到，partition_point() 返回了一个指向元素 1 的迭代器，而该元素为 myvector 
容器中第一个不符合 mycomp 规则的元素，同时其也可以第二组数据中第一个元素。

值得一提的是，C++ 11标准库中给出了 partition_point() 函数底层实现的参考代码（如下所示），感兴趣的读者可自行
分析，这里不再进行赘述：
纯文本复制
template <class ForwardIterator, class UnaryPredicate>
ForwardIterator partition_point (ForwardIterator first, ForwardIterator last,
                                   UnaryPredicate pred)
{
    auto n = distance(first,last);
    while (n>0)
    {
        ForwardIterator it = first;
        auto step = n/2;
        std::advance (it,step);
        if (pred(*it)) { first=++it; n-=step+1; }
        else n=step;
    }
    return first;
}

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

auto print_seq = [](auto rem, auto first, auto last) {
    for (std::cout << rem; first != last; std::cout << *first++ << ' ') {}
    std::cout << '\n';
};

int main()
{
    std::array<int, 9> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
 
    auto is_even = [](int i){ return i % 2 == 0; };
 
    // do a stable partition which will keep original order of vector
    std::stable_partition(v.begin(), v.end(), is_even);
    print_seq("After partitioning, v: ", v.cbegin(), v.cend());
 
    // after partition, locate the iterator of first part
    const auto pp = std::partition_point(v.cbegin(), v.cend(), is_even);
    const auto i = std::distance(v.cbegin(), pp);
    std::cout << "Partition point is at " << i << "; v[" << i << "] = " << *pp << '\n';
 
    print_seq("First partition (all even elements): ", v.cbegin(), pp);
    print_seq("Second partition (all odd elements): ", pp, v.cend());

    return 0;
    // After partitioning, v: 2 4 6 8 1 3 5 7 9 
    // Partition point is at 4; v[4] = 1
    // First partition (all even elements): 2 4 6 8 
    // Second partition (all odd elements): 1 3 5 7 9 
}
