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

https://en.cppreference.com/w/cpp/algorithm/partial_sort

Rearranges elements such that the range [first, middle) contains the sorted middle − first smallest 
elements in the range [first, last).

The order of equal elements is not guaranteed to be preserved. The order of the remaining elements 
in the range [middle, last) is unspecified.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.


假设这样一种情境，有一个存有 100 万个元素的容器，但我们只想从中提取出值最小的 10 个元素，该如何实现呢？

通过前面的学习，读者可能会想到使用 sort() 或者 stable_sort() 排序函数，即通过对容器中存储的 100 万个元素进行排序，
就可以成功筛选出最小的 10 个元素。但仅仅为了提取 10 个元素，却要先对 100 万个元素进行排序，可想而知这种实现方式的效率
是非常低的。

对于解决类似的问题，C++ STL 标准库提供了更高效的解决方案，即使用 partial_sort() 或者 partial_sort_copy() 函数，
本节就对这 2 个排序函数的功能和用法做详细的讲解。

首先需要说明的是，partial_sort() 和 partial_sort_copy() 函数都位于 <algorithm> 头文件中，因此在使用这 2 个函数
之前，程序中应引入此头文件：

#include <algorithm>
C++ partial_sort()排序函数
要知道，一个函数的功能往往可以从它的函数名中体现出来，以 partial_sort() 函数为例，partial sort 可直译为“部分排序”。
partial_sort() 函数的功能确是如此，即该函数可以从指定区域中提取出部分数据，并对它们进行排序。

但“部分排序”仅仅是对 partial_sort() 函数功能的一个概括，如果想彻底搞清楚它的功能，需要结合该函数的语法格式。
partial_sort() 函数有 2 种用法，其语法格式分别为：

//按照默认的升序排序规则，对 [first, last) 范围的数据进行筛选并排序
void partial_sort (RandomAccessIterator first,
                   RandomAccessIterator middle,
                   RandomAccessIterator last);
//按照 comp 排序规则，对 [first, last) 范围的数据进行筛选并排序
void partial_sort (RandomAccessIterator first,
                   RandomAccessIterator middle,
                   RandomAccessIterator last,
                   Compare comp);
其中，first、middle 和 last 都是随机访问迭代器，comp 参数用于自定义排序规则。

partial_sort() 函数会以交换元素存储位置的方式实现部分排序的。具体来说，partial_sort() 会将 [first, last) 范围内最小
（或最大）的 middle-first 个元素移动到 [first, middle) 区域中，并对这部分元素做升序（或降序）排序。

需要注意的是，partial_sort() 函数受到底层实现方式的限制，它仅适用于普通数组和部分类型的容器。换句话说，只有普通数组和具备
以下条件的容器，才能使用 partial_sort() 函数：

容器支持的迭代器类型必须为随机访问迭代器。这意味着，partial_sort() 函数只适用于 array、vector、deque 这 3 个容器。
当选用默认的升序排序规则时，容器中存储的元素类型必须支持 <小于运算符；同样，如果选用标准库提供的其它排序规则，元素类型也必须
支持该规则底层实现所用的比较运算符；

partial_sort() 函数在实现过程中，需要交换某些元素的存储位置。因此，如果容器中存储的是自定义的类对象，则该类的内部必须提供
移动构造函数和移动赋值运算符。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::partial_sort
#include <vector>       // std::vector

using namespace std;

//以普通函数的方式自定义排序规则
bool mycomp1(int i, int j) {
    return (i > j);
}

//以函数对象的方式自定义排序规则
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i > j);
    }
};

int main() {
    std::vector<int> myvector{ 3,2,5,4,1,6,9,7};
    //以默认的升序排序作为排序规则，将 myvector 中最小的 4 个元素移动到开头位置并排好序
    std::partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end());
    cout << "第一次排序:\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << *it << ' ';
    cout << "\n第二次排序:\n";
    // 以指定的 mycomp2 作为排序规则，将 myvector 中最大的 4 个元素移动到开头位置并排好序
    std::partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end(), mycomp2());
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << *it << ' ';
    return 0;
}

程序执行结果为：
第一次排序:
1 2 3 4 5 6 9 7
第二次排序:
9 7 6 5 1 2 3 4

值得一提的是，partial_sort() 函数实现排序的平均时间复杂度为N*log(M)，其中 N 指的是 [first, last) 
范围的长度，M 指的是 [first, middle) 范围的长度。

C++ partial_sort_copy()排序函数
partial_sort_copy() 函数的功能和 partial_sort() 类似，唯一的区别在于，前者不会对原有数据做任何变动，
而是先将选定的部分元素拷贝到另外指定的数组或容器中，然后再对这部分元素进行排序。

partial_sort_copy() 函数也有 2 种语法格式，分别为：
//默认以升序规则进行部分排序
RandomAccessIterator partial_sort_copy (
                       InputIterator first,
                       InputIterator last,
                       RandomAccessIterator result_first,
                       RandomAccessIterator result_last);
//以 comp 规则进行部分排序
RandomAccessIterator partial_sort_copy (
                       InputIterator first,
                       InputIterator last,
                       RandomAccessIterator result_first,
                       RandomAccessIterator result_last,
                       Compare comp);
其中，first 和 last 为输入迭代器；result_first 和 result_last 为随机访问迭代器；comp 用于自定义排序规则。

partial_sort_copy() 函数会将 [first, last) 范围内最小（或最大）的 result_last-result_first 个元素复制到 
[result_first, result_last) 区域中，并对该区域的元素做升序（或降序）排序。

值得一提的是，[first, last] 中的这 2 个迭代器类型仅限定为输入迭代器，这意味着相比 partial_sort() 函数，
partial_sort_copy() 函数放宽了对存储原有数据的容器类型的限制。换句话说，partial_sort_copy() 函数还支持对 
list 容器或者 forward_list 容器中存储的元素进行“部分排序”，而 partial_sort() 函数不行。

但是，介于 result_first 和 result_last 仍为随机访问迭代器，因此 [result_first, result_last) 指定的区域仍
仅限于普通数组和部分类型的容器，这和 partial_sort() 函数对容器的要求是一样的。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::partial_sort_copy
#include <list>       // std::list

using namespace std;

bool mycomp1(int i, int j) {
    return (i > j);
}

class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i > j);
    }
};

int main() {
    int myints[5] = { 0 };
    std::list<int> mylist{ 3,2,5,4,1,6,9,7 };
    //按照默认的排序规则进行部分排序
    std::partial_sort_copy(mylist.begin(), mylist.end(), myints, myints + 5);
    cout << "第一次排序：\n";
    for (int i = 0; i < 5; i++) {
        cout << myints[i] << " ";
    }
    //以自定义的 mycomp2 作为排序规则，进行部分排序
    std::partial_sort_copy(mylist.begin(), mylist.end(), myints, myints + 5, mycomp2());
    cout << "\n第二次排序：\n";
    for (int i = 0; i < 5; i++) {
        cout << myints[i] << " ";
    }
    return 0;
}
程序执行结果为：
第一次排序：
1 2 3 4 5
第二次排序：
9 7 6 5 4

可以看到，程序中调用了 2 次 partial_sort_copy() 函数，其作用分别是：
第 20 行：采用默认的升序排序规则，在 mylist 容器中筛选出最小的 5 个元素，然后将它们复制到 myints[5] 数组中，
并对这部分元素进行升序排序；
第 27 行：采用自定义的 mycomp2 降序排序规则，从 mylist 容器筛选出最大的 5 个元素，同样将它们复制到 myints[5] 
数组中，并对这部分元素进行降序排序；

值得一提的是，partial_sort_copy() 函数实现排序的平均时间复杂度为N*log(min(N,M))，其中 N 指的是 [first, last) 
范围的长度，M 指的是 [result_first, result_last) 范围的长度。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

auto print = [](auto const& s, int middle) {
    for (int a : s) { std::cout << a << ' '; }
    std::cout << '\n';
    if (middle > 0) {
        while (middle-->0) { std::cout << "──"; }
        std::cout << '^';
    } else if (middle < 0) {
        for (auto i = s.size() + middle; --i; std::cout << "  ");
        for (std::cout << '^'; middle++ < 0; std::cout << "──");
    }
    std::cout << '\n';  
};

int main()
{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
    print(s, 0);

    // sort first 3 elements within all 10 elements
    std::partial_sort(s.begin(), s.begin() + 3, s.end());
    print(s, 3);

    // sort last 4 elements
    std::partial_sort(s.rbegin(), s.rbegin() + 4, s.rend());
    print(s, -4);

    // sort last 5 elements, but by descending order
    std::partial_sort(s.rbegin(), s.rbegin() + 5, s.rend(), std::greater{});
    print(s, -5);

    // partial_sort() is useful when we only need few elements sorted in a given container
    // while its syntax is (begin, middle, end)
    // this code example compiled with "g++ --std=c++17 -g partial_sort.cc"
    return 0;
    // 5 7 4 2 8 6 1 9 0 3 
    // 
    // 0 1 2 7 8 6 5 9 4 3 
    // ──────^
    // 4 5 6 7 8 9 3 2 1 0 
    //           ^────────
    // 4 3 2 1 0 5 6 7 8 9 
    //         ^──────────
}
