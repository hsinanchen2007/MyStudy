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

https://en.cppreference.com/w/cpp/algorithm/equal_range

Returns a range containing all elements equivalent to value in the range [first, last).

The range [first, last) must be at least partially ordered with respect to value, i.e. 
it must satisfy all of the following requirements:

partitioned with respect to element < value or comp(element, value) (that is, all elements 
for which the expression is true precedes all elements for which the expression is false)

partitioned with respect to !(value < element) or !comp(value, element)
for all elements, if element < value or comp(element, value) is true then !(value < element) 
or !comp(value, element) is also true

A fully-sorted range meets these criteria.

The returned range is defined by two iterators, one pointing to the first element that 
is not less than value and another pointing to the first element greater than value. 
The first iterator may be alternatively obtained with std::lower_bound(), the second - 
with std::upper_bound().

The first version uses operator< to compare the elements, the second version uses the 
given comparison function comp.

Return value
std::pair containing a pair of iterators defining the wanted range, the first pointing to the 
first element that is not less than value and the second pointing to the first element greater 
than value.

If there are no elements not less than value, last is returned as the first element. Similarly 
if there are no elements greater than value, last is returned as the second element


equel_range() 函数定义在<algorithm>头文件中，用于在指定范围内查找等于目标值的所有元素。

值得一提的是，当指定范围内的数据支持用 < 小于运算符直接做比较时，可以使用如下格式的 equel_range() 函数：
//找到 [first, last) 范围中所有等于 val 的元素
pair<ForwardIterator,ForwardIterator> equal_range (ForwardIterator first, ForwardIterator 
last, const T& val);
如果指定范围内的数据为自定义的类型（用结构体或类），就需要自定义比较规则，这种情况下可以使用如下格式的 
equel_range() 函数：

//找到 [first, last) 范围内所有等于 val 的元素
pair<ForwardIterator,ForwardIterator> equal_range (ForwardIterator first, ForwardIterator 
last, const T& val, Compare comp);
以上 2 种格式中，first 和 last 都为正向迭代器，[first, last) 用于指定该函数的作用范围；val 用于指定目标值；
comp 用于指定比较规则，此参数可接收一个包含 2 个形参（第二个形参值始终为 val）且返回值为 bool 类型的函数，
可以是普通函数，也可以是函数对象。

同时，该函数会返回一个 pair 类型值，其包含 2 个正向迭代器。当查找成功时：
第 1 个迭代器指向的是 [first, last) 区域中第一个等于 val 的元素；
第 2 个迭代器指向的是 [first, last) 区域中第一个大于 val 的元素。
反之如果查找失败，则这 2 个迭代器要么都指向大于 val 的第一个元素（如果有），要么都和 last 迭代器指向相同。

需要注意的是，由于 equel_range() 底层实现采用的是二分查找的方式，因此该函数仅适用于“已排好序”的序列。
所谓“已排好序”，并不是要求 [first, last) 区域内的数据严格按照某个排序规则进行升序或降序排序，只要满足“所有令 
element<val（或者 comp(element,val）成立的元素都位于不成立元素的前面（其中 element 为指定范围内的元素）”即可。
有关二分查找算法，读者可阅读《二分查找算法》一节。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::equal_range
#include <vector>       // std::vector

using namespace std;

//以普通函数的方式定义查找规则
bool mycomp(int i, int j) { return i > j; }

//以函数对象的形式定义查找规则
class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return i > j;
    }
};

int main() {
    int a[9] = { 1,2,3,4,4,4,5,6,7};
    //从 a 数组中找到所有的元素 4
    pair<int*, int*> range = equal_range(a, a + 9, 4);
    cout << "a[9]：";
    for (int *p = range.first; p < range.second; ++p) {
        cout << *p << " ";
    }
    vector<int>myvector{ 7,8,5,4,3,3,3,3,2,1 };
    pair<vector<int>::iterator, vector<int>::iterator> range2;
    //在 myvector 容器中找到所有的元素 3
    range2 = equal_range(myvector.begin(), myvector.end(), 3,mycomp2());
    cout << "\nmyvector：";
    for (auto it = range2.first; it != range2.second; ++it) {
        cout << *it << " ";
    }
    return 0;
}

程序执行结果为：
a[9]：4 4 4
myvector：3 3 3 3

此程序中演示了 equal_range() 函数的 2 种适用场景，其中 a[9] 数组中存储的为升序序列；而 myvector 容器中存储的
序列虽然整体是乱序的，但对于目标元素 3 来说，所有符合 mycomp2(element, 3) 规则的元素都位于其左侧，不符合的元素
都位于其右侧，因此 equal_range() 函数仍可正常执行。

实际上，equel_range() 函数的功能完全可以看做是 lower_bound() 和 upper_bound() 函数的合体。C++ STL标准库给
出了 equel_range() 函数底层实现的参考代码（如下所示），感兴趣的读者可自行研究，这里不再赘述：

//对应第一种语法格式
template <class ForwardIterator, class T>
pair<ForwardIterator,ForwardIterator> equal_range (ForwardIterator first, ForwardIterator last, 
const T& val)
{
    ForwardIterator it = std::lower_bound (first,last,val);
    return std::make_pair ( it, std::upper_bound(it,last,val) );
}

//对应第二种语法格式
template<class ForwardIterator, class T, class Compare>
std::pair<ForwardIt,ForwardIt> equal_range(ForwardIterator first, ForwardIterator last, const T& val, 
Compare comp)
{
    ForwardIterator it = std::lower_bound (first,last,val,comp);
    return std::make_pair ( it, std::upper_bound(it,last,val,comp) );
}

有关 lower_bound() 函数的功能和用法，可阅读《C++ lower_bound()函数》一节；有关 upper_bound() 函数的功能和用法，
可阅读《C++ upper_bound()函数》一节。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV = {1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8};
    auto ret = equal_range(myV.begin(), myV.end(), 3);

    // note that the ret is a pair that contains first is the first element we found, second is 
    // the last element we found in the given vector
    for (auto element = ret.first; element != ret.second; element++) {
        cout << "Element of 3 we found in vector is "<< *element << endl;
    }

    // 2022.8.3
    // again, the return of equal_range() is std::pair that contains first and last 
    // elements found, also the criteria to use this function is a fully sorted source

    return 0;
    // Element of 3 we found in vector is 3
    // Element of 3 we found in vector is 3
    // Element of 3 we found in vector is 3
    // Element of 3 we found in vector is 3
}
