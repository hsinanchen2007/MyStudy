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

https://en.cppreference.com/w/cpp/algorithm/binary_search

Checks if an element equivalent to value appears within the range [first, last).

For std::binary_search to succeed, the range [first, last) must be at least partially 
ordered with respect to value, i.e. it must satisfy all of the following requirements:

partitioned with respect to element < value or comp(element, value) (that is, all 
elements for which the expression is true precede all elements for which the 
expression is false) partitioned with respect to !(value < element) or !comp(value, element)
for all elements, if element < value or comp(element, value) is true then !(value < element) 
or !comp(value, element) is also true

A fully-sorted range meets these criteria.

The first version uses operator< to compare the elements, the second version uses 
the given comparison function comp.

Return value
true if an element equal to value is found, false otherwise.


binary_search() 函数定义在<algorithm>头文件中，用于查找指定区域内是否包含某个目标元素。

该函数有 2 种语法格式，分别为：
//查找 [first, last) 区域内是否包含 val
bool binary_search (ForwardIterator first, ForwardIterator last,
                      const T& val);
//根据 comp 指定的规则，查找 [first, last) 区域内是否包含 val
bool binary_search (ForwardIterator first, ForwardIterator last,
                      const T& val, Compare comp);
其中，first 和 last 都为正向迭代器，[first, last) 用于指定该函数的作用范围；val 用于指定要查找的目标值；
comp 用于自定义查找规则，此参数可接收一个包含 2 个形参（第一个形参值为 val）且返回值为 bool 类型的函数，
可以是普通函数，也可以是函数对象。

同时，该函数会返回一个 bool 类型值，如果 binary_search() 函数在 [first, last) 区域内成功找到和 val 
相等的元素，则返回 true；反之则返回 false。

需要注意的是，由于 binary_search() 底层实现采用的是二分查找的方式，因此该函数仅适用于“已排好序”的序列。
所谓“已排好序”，并不是要求 [first, last) 区域内的数据严格按照某个排序规则进行升序或降序排序，只要满足“所有令 
element<val（或者 comp(val, element）成立的元素都位于不成立元素的前面（其中 element 为指定范围内的元素）”
即可。有关二分查找算法，读者可阅读《二分查找算法》一节。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search
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
    int a[7] = { 1,2,3,4,5,6,7 };
    //从 a 数组中查找元素 4
    bool haselem = binary_search(a, a + 9, 4);
    cout << "haselem：" << haselem << endl;
    vector<int>myvector{ 4,5,3,1,2 };
    //从 myvector 容器查找元素 3
    bool haselem2 = binary_search(myvector.begin(), myvector.end(), 3, mycomp2());
    cout << "haselem2：" << haselem2;
    return 0;
}

程序执行结果为：
haselem：1
haselem2：1

此程序中演示了 binary_search() 函数的 2 种适用场景，其中 a[7] 数组中存储的为升序序列；而 myvector 
容器中存储的序列虽然整体是乱序的，但对于目标元素 3 来说，所有符合 mycomp2(element, 3) 规则的元素都位于其左侧，
不符合的元素都位于其右侧，因此 binary_search() 函数仍可正常执行。

C++ STL标准库给出了 binary_search() 函数底层实现的参考代码（如下所示），感兴趣的读者可自行研究，这里不再赘述：

//第一种语法格式的实现
template <class ForwardIterator, class T>
bool binary_search (ForwardIterator first, ForwardIterator last, const T& val)
{
    first = std::lower_bound(first,last,val);
    return (first!=last && !(val<*first));
}

//第二种语法格式的底层实现
template<class ForwardIt, class T, class Compare>
bool binary_search(ForwardIt first, ForwardIt last, const T& val, Compare comp)
{
    first = std::lower_bound(first, last, val, comp);
    return (!(first == last) && !(comp(val, *first)));
}

有关 lower_bound() 函数的功能和用法，可阅读《C++ lower_bound()函数》一节；有关 upper_bound() 函数的功能
和用法，可阅读《C++ upper_bound()函数》一节。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV = {1, 3, 5, 7, 9, 10};

    // use binary_search() to see if the given target 5 existed or not
    bool ret1 = binary_search(myV.begin(), myV.end(), 5);
    if (ret1) {
        cout << "Target number 5 found" << endl;
    } else {
        cout << "Target number 5 not found" << endl;
    }

    // decreasing order and still use STL's binary_search()
    vector<int> myV2 = {10, 8, 6, 4, 2, 0};
    bool ret2 = binary_search(myV2.begin(), myV2.end(), 8, [](int v1, int v2){ return (v1 > v2) ? true : false; });
    if (ret2) {
	    cout << "Target number 8 found" << endl;
    } else {
        cout << "Target number 8 not found" << endl;
    }

    // decreasing, but use rbegin()/rend() without compare function
    bool ret3 = binary_search(myV2.rbegin(), myV2.rend(), 8);
    if (ret3) {
	    cout << "Target number 8 found" << endl;
    } else {
        cout << "Target number 8 not found" << endl;
    }

    // 2022.9.10
    // add decreasing order way by compare function or by rbegin()/rend()

    return 0;
    // Target number 5 found
}
