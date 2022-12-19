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

https://en.cppreference.com/w/cpp/algorithm/sort

Sorts the elements in the range [first, last) in non-descending order. The order of equal elements 
is not guaranteed to be preserved.

A sequence is sorted with respect to a comparator comp if for any iterator it pointing to the sequence 
and any non-negative integer n such that it + n is a valid iterator pointing to an element of the 
sequence, comp(*(it + n), *it) (or *(it + n) < *it) evaluates to false.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
(none)


C++ STL 标准库提供有很多实用的排序函数，如表 1 所示。通过调用它们，我们可以很轻松地实现对普通数组或者容器中指定范围内的
元素进行排序。

表 1 C++ STL 排序函数
函数名	用法

sort (first, last)	对容器或普通数组中 [first, last) 范围内的元素进行排序，默认进行升序排序。

stable_sort (first, last)	和 sort() 函数功能相似，不同之处在于，对于 [first, last) 范围内值相同的元素，该函数
不会改变它们的相对位置。

partial_sort (first, middle, last)	从 [first,last) 范围内，筛选出 muddle-first 个最小的元素并排序存放在 
[first，middle) 区间中。

partial_sort_copy (first, last, result_first, result_last)	从 [first, last) 范围内筛选出 result_last-result_first 
个元素排序并存储到 [result_first, result_last) 指定的范围中。

is_sorted (first, last)	检测 [first, last) 范围内是否已经排好序，默认检测是否按升序排序。

is_sorted_until (first, last)	和 is_sorted() 函数功能类似，唯一的区别在于，如果 [first, last) 范围的元素没有排好序，
则该函数会返回一个指向首个不遵循排序规则的元素的迭代器。

void nth_element (first, nth, last)	找到 [first, last) 范围内按照排序规则（默认按照升序排序）应该位于第 nth 个位置处
的元素，并将其放置到此位置。同时使该位置左侧的所有元素都比其存放的元素小，该位置右侧的所有元素都比其存放的元素大。

对于表 1 中罗列的这些函数，本教程会一一进行讲解，这里先介绍 sort() 函数。
C++ sort()排序函数
C++ STL 标准库中的 sort()  函数，本质就是一个模板函数。正如表 1 中描述的，该函数专门用来对容器或普通数组中指定范围内的元素进行排序，
排序规则默认以元素值的大小做升序排序，除此之外我们也可以选择标准库提供的其它排序规则（比如std::greater<T>降序排序规则），甚至还可以
自定义排序规则。sort() 函数是基于快速排序实现的，有关快速排序的具体实现过程，感兴趣的读者可阅读《快速排序（QSort，快排）算法》一文。

需要注意的是，sort() 函数受到底层实现方式的限制，它仅适用于普通数组和部分类型的容器。换句话说，只有普通数组和具备以下条件的容器，才能
使用 sort() 函数：
容器支持的迭代器类型必须为随机访问迭代器。这意味着，sort() 只对 array、vector、deque 这 3 个容器提供支持。
如果对容器中指定区域的元素做默认升序排序，则元素类型必须支持<小于运算符；同样，如果选用标准库提供的其它排序规则，元素类型也必须支持该
规则底层实现所用的比较运算符；
sort() 函数在实现排序时，需要交换容器中元素的存储位置。这种情况下，如果容器中存储的是自定义的类对象，则该类的内部必须提供移动构造函数
和移动赋值运算符。

另外还需要注意的一点是，对于指定区域内值相等的元素，sort() 函数无法保证它们的相对位置不发生改变。例如，有如下一组数据：
2 1 2 3 2

可以看到，该组数据中包含多个值为 2 的元素，此时如果使用 sort() 函数进行排序，则值为 2 的这 3 个元素的相对位置可能会发生改变，比如
排序结果为：
1 2 2 2 3

可以看到，原本红色的元素 2 位于绿色 2 和橙色 2 的左侧，但经过 sort() 函数排序之后，它们的相对位置发生了改变，即红色 2 移动到了绿色 
2 和橙色 2 的右侧。实际场景中，如果需要保证值相等元素的相对位置不发生改变，可以选用 stable_sort() 排序函数。有关该函数的具体用法，
后续章节会做详细讲解。


值得一提的是，sort() 函数位于<algorithm>头文件中，因此在使用该函数前，程序中应包含如下语句：
#include <algorithm>
sort() 函数有 2 种用法，其语法格式分别为：
//对 [first, last) 区域内的元素做默认的升序排序
void sort (RandomAccessIterator first, RandomAccessIterator last);
//按照指定的 comp 排序规则，对 [first, last) 区域内的元素进行排序
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
其中，first 和 last 都为随机访问迭代器，它们的组合 [first, last) 用来指定要排序的目标区域；另外在第 2 种格式中，comp 可以是 
C++ STL 标准库提供的排序规则（比如 std::greater<T>），也可以是自定义的排序规则。

关于如何自定义一个排序规则，除了《C++ STL关联式容器自定义排序规则》一节介绍的 2 种方式外，还可以直接定义一个具有 2 个参数并返回 
bool 类型值的函数作为排序规则。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

//以普通函数的方式实现自定义排序规则
bool mycomp(int i, int j) {
    return (i < j);
}

//以函数对象的方式实现自定义排序规则
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i < j);
    }
};

int main() {
    std::vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };
    //调用第一种语法格式，对 32、71、12、45 进行排序
    std::sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71) 26 80 53 33
    //调用第二种语法格式，利用STL标准库提供的其它比较规则（比如 greater<T>）进行排序
    std::sort(myvector.begin(), myvector.begin() + 4, std::greater<int>()); //(71 45 32 12) 26 80 53 33
   
    //调用第二种语法格式，通过自定义比较规则进行排序
    std::sort(myvector.begin(), myvector.end(), mycomp2());//12 26 32 33 45 53 71 80
    //输出 myvector 容器中的元素
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    return 0;
}
程序执行结果为：
12 26 32 33 45 53 71 80

可以看到，程序中分别以函数和函数对象的方式自定义了具有相同功能的 mycomp 和 mycomp2 升序排序规则。需要注意的是，和为关联式容器
设定排序规则不同，给 sort() 函数指定排序规则时，需要为其传入一个函数名（例如 mycomp ）或者函数对象（例如 std::greater<int>() 
或者 mycomp2()）。

那么，sort() 函数的效率怎么样吗？该函数实现排序的平均时间复杂度为N*log2N（其中 N 为指定区域 [first, last) 中 last 和 first 
的距离）。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV = {1, 3, 5, 7, 2, 4, 6, 8};
    for_each(myV.begin(), myV.end(), [](int v){ cout << v << " "; });
    cout << endl;

    sort(myV.begin(), myV.end());
    for_each(myV.begin(), myV.end(), [](int v){ cout << v << " "; });
    cout << endl;

    return 0;
    // 1 3 5 7 2 4 6 8 
    // 1 2 3 4 5 6 7 8 
}
