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

https://en.cppreference.com/w/cpp/algorithm/nth_element

nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:

The element pointed at by nth is changed to whatever element would occur in that position if 
[first, last) were sorted. All of the elements before this new nth element are less than or equal 
to the elements after the new nth element. More formally, nth_element partially sorts the range 
[first, last) in ascending order so that the condition !(*j < *i) (for (1-2), or comp(*j, *i) == 
false for (3-4)) is met for any i in the range [first, nth) and for any j in the range [nth, last). 
The element placed in the nth position is exactly the element that would occur in this position 
if the range was fully sorted.

nth may be the end iterator, in this case the function has no effect.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
(none)


前面章节中，已经给大家介绍了 sort()、stable_sort()、partial_sort() 这些函数的功能和用法，本节再介绍一个排序函数，
即 nth_element() 函数。

不过，在系统讲解 nth_element() 函数之前，我们先形成一个共识，即在有序序列中，我们可以称第 n 个元素为整个序列中“第 n 
大”的元素。比如，下面是一个升序序列：

2 4 6 8 10

在这个序列中，我们可以称元素 6 为整个序列中“第 3 小”的元素，并位于第 3 的位置处；同样，元素 8 为整个序列中“第 4 小”
的元素，并位于第 4 的位置处。

简单的理解 nth_element() 函数的功能，当采用默认的升序排序规则（std::less<T>）时，该函数可以从某个序列中找到第 n 
小的元素 K，并将 K 移动到序列中第 n 的位置处。不仅如此，整个序列经过 nth_element() 函数处理后，所有位于 K 之前的
元素都比 K 小，所有位于 K 之后的元素都比 K 大。

当然，我们也可以将 nth_element() 函数的排序规则自定义为降序排序，此时该函数会找到第 n 大的元素 K 并将其移动到第 n 
的位置处，同时所有位于 K 之前的元素都比 K 大，所有位于 K 之后的元素都比 K 小。

以下面这个序列为例：
3 4 1 2 5

假设按照升序排序，并通过 nth_element() 函数查找此序列中第 3 小的元素，则最终得到的序列可能为：
2 1 3 4 5

显然，nth_element() 函数找到了第 3 小的元素 3 并将其位于第 3 的位置，同时元素 3 之前的所有元素都比该元素小，元素 3 
之后的所有元素都比该元素大。

要知道，nth_element() 本质也是一个函数模板，定义在<algorithm>头文件中。因此，如果程序中想使用该函数，就需要提前引入
这个头文件：

#include <algorithm>

nth_element() 函数有以下 2 种语法格式：

//排序规则采用默认的升序排序
void nth_element (RandomAccessIterator first,
                  RandomAccessIterator nth,
                  RandomAccessIterator last);

//排序规则为自定义的 comp 排序规则
void nth_element (RandomAccessIterator first,
                  RandomAccessIterator nth,
                  RandomAccessIterator last,
                  Compare comp);
其中，各个参数的含义如下：
first 和 last：都是随机访问迭代器，[first, last) 用于指定该函数的作用范围（即要处理哪些数据）；
nth：也是随机访问迭代器，其功能是令函数查找“第 nth 大”的元素，并将其移动到 nth 指向的位置；
comp：用于自定义排序规则。

注意，鉴于 nth_element() 函数中各个参数的类型，其只能对普通数组或者部分容器进行排序。换句话说，只有普通数组和符合以下全部
条件的容器，才能使用使用 nth_element() 函数：

容器支持的迭代器类型必须为随机访问迭代器。这意味着，nth_element() 函数只适用于 array、vector、deque 这 3 个容器。
当选用默认的升序排序规则时，容器中存储的元素类型必须支持 <小于运算符；同样，如果选用标准库提供的其它排序规则，元素类型也必须
支持该规则底层实现所用的比较运算符；

nth_element() 函数在实现过程中，需要交换某些元素的存储位置。因此，如果容器中存储的是自定义的类对象，则该类的内部必须提供
移动构造函数和移动赋值运算符。

举个例子：
#include <iostream>
#include <algorithm>    // std::nth_element
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
    std::vector<int> myvector{3,1,2,5,4};
    //默认的升序排序作为排序规则
    std::nth_element(myvector.begin(), myvector.begin()+2, myvector.end());
    cout << "第一次nth_element排序：\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    //自定义的 mycomp2() 或者 mycomp1 降序排序作为排序规则
    std::nth_element(myvector.begin(), myvector.begin() + 3, myvector.end(),mycomp1);
    cout << "\n第二次nth_element排序：\n";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    return 0;
}
程序执行结果可能为（不唯一）：
第一次nth_element排序：
1 2 3 4 5
第二次nth_element排序：
5 4 3 2 1

上面程序中，共调用了 2 次 nth_elelment() 函数：

第 20 行：nth_element() 函数采用的是默认的升序排序，nth 参数设置为 myvector.begin()+2，即指向的是 
myvector 容器中第 3 个元素所在的位置。因此，nth_element() 函数会查找“第 3 小”的元素 3，并将其移动到 
nth 指向的位置，同时使 nth 之前的所有元素都比 3 小，使 nth 之后的所有元素都比 3 大。

第 26 行：nth_element() 函数采用的是默认的降序排序，nth 参数设置为 myvector.begin()+3，即指向的是 
myvector 容器中第 4 个元素所在的位置。因此，nth_element() 函数会查找“第 4 大”的元素 2，并将其移动到 
nth 指向的位置，同时使 nth 之前的所有元素都比 2 大，使 nth 之后的所有元素都比 2 小。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

void printVec(const std::vector<int> &vec)
{
    std::cout << "v= {";
    for (int i : vec)
        std::cout << i << ", ";
    std::cout << "}\n";
}

int main()
{
    std::vector<int> v{5, 10, 6, 4, 3, 2, 6, 7, 9, 3};
    printVec(v);
 
    auto m = v.begin() + v.size()/2;

    // the synyax is similar to partial_sort() parameters
    std::nth_element(v.begin(), m, v.end());
    std::cout << "\nThe median is " << v[v.size()/2] << '\n';

    // The consequence of the inequality of elements before/after the Nth one:
    assert(std::accumulate(v.begin(), m, 0) < std::accumulate(m, v.end(), 0));
    printVec(v);
 
    // Note: comp function changed
    std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater{});

    std::cout << "\nThe second largest element is " << v[1] << '\n';
    std::cout << "The largest element is " << v[0] << '\n';
    printVec(v);

    return 0;
}
