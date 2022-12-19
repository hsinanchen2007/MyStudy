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

https://en.cppreference.com/w/cpp/algorithm/lower_bound

Returns an iterator pointing to the first element in the range [first, last) that does not 
satisfy element < value (or comp(element, value)), (i.e. greater or equal to), or last if 
no such element is found.

The range [first, last) must be partitioned with respect to the expression element < value 
(or comp(element, value)), i.e., all elements for which the expression is true must precede 
all elements for which the expression is false. A fully-sorted range meets this criterion.

The first version uses operator< to compare the elements, the second version uses the given 
comparison function comp.

Return value
Iterator pointing to the first element in the range [first, last) such that element < value 
(or comp(element, value)) is false, or last if no such element is found.


https://en.cppreference.com/w/cpp/algorithm/upper_bound

Returns an iterator pointing to the first element in the range [first, last) such that 
value < element (or comp(value, element)) is true (i.e. strictly greater), or last if no 
such element is found.

The range [first, last) must be partitioned with respect to the expression !(value < element) 
or !comp(value, element), i.e., all elements for which the expression is true must precede 
all elements for which the expression is false. A fully-sorted range meets this criterion.

The first version uses operator< to compare the elements, the second version uses the given 
comparison function comp.

Return value
Iterator pointing to the first element in the range [first, last) such that value < element 
(or comp(value, element)) is true, or last if no such element is found.


前面章节中，已经给大家系统地介绍了几个查找函数，如 find()、find_if()、search() 等。值得一提的是，
这些函数的底层实现都采用的是顺序查找（逐个遍历）的方式，在某些场景中的执行效率并不高。例如，当指定区域内的数据处
于有序状态时，如果想查找某个目标元素，更推荐使用二分查找的方法（相比顺序查找，二分查找的执行效率更高）。

幸运的是，除了前面讲过的几个函数外，C++ STL标准库中还提供有 lower_bound()、upper_bound()、equal_range() 
以及 binary_search() 这 4 个查找函数，它们的底层实现采用的都是二分查找的方式。

从本节开始，将给大家系统地讲解这 4 个二分查找函数的功能和用法，这里先从 lower_bound() 函数开始讲起。
有关二分查找算法的实现原理，感兴趣的读者可阅读《二分查找（折半查找）》一节做详细了解。

C++ lower_bound()函数
lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。也就是说，使用该函数在指定范围内查找某个目标值时，
最终查找到的不一定是和目标值相等的元素，还可能是比目标值大的元素。

lower_bound() 函数定义在<algorithm>头文件中，其语法格式有 2 种，分别为：
//在 [first, last) 区域内查找不小于 val 的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                             const T& val);
//在 [first, last) 区域内查找第一个不符合 comp 规则的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                             const T& val, Compare comp);

其中，first 和 last 都为正向迭代器，[first, last) 用于指定函数的作用范围；val 用于指定目标元素；comp 用于自定
义比较规则，此参数可以接收一个包含 2 个形参（第二个形参值始终为 val）且返回值为 bool 类型的函数，可以是普通函数，
也可以是函数对象。

实际上，第一种语法格式也设定有比较规则，只不过此规则无法改变，即使用 < 小于号比较 [first, last) 区域内某些元素和 
val 的大小，直至找到一个不小于 val 的元素。这也意味着，如果使用第一种语法格式，则 [first,last) 范围的元素类型必须
支持 < 运算符。

此外，该函数还会返回一个正向迭代器，当查找成功时，迭代器指向找到的元素；反之，如果查找失败，迭代器的指向和 last 
迭代器相同。

再次强调，该函数仅适用于已排好序的序列。所谓“已排好序”，指的是 [first, last) 区域内所有令 element<val
（或者 comp(element,val)，其中 element 为指定范围内的元素）成立的元素都位于不成立元素的前面。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound
#include <vector>       // std::vector

using namespace std;

//以普通函数的方式定义查找规则
bool mycomp(int i,int j) { return i>j; }

//以函数对象的形式定义查找规则
class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return i>j;
    }
};

int main() {
    int a[5] = { 1,2,3,4,5 };
    //从 a 数组中找到第一个不小于 3 的元素
    int *p = lower_bound(a, a + 5, 3);
    cout << "*p = " << *p << endl;
    vector<int> myvector{ 4,5,3,1,2 };
    //根据 mycomp2 规则，从 myvector 容器中找到第一个违背 mycomp2 规则的元素
    vector<int>::iterator iter = lower_bound(myvector.begin(), myvector.end(),3,mycomp2());
    cout << "*iter = " << *iter;
    return 0;
}

程序执行结果为：
*p = 3
*iter = 3

注意，myvector 容器中存储的元素看似是乱序的，但对于元素 3 来说，大于 3 的所有元素都位于其左侧，小于 3 的所有元素
都位于其右侧，且查找规则选用的是 mycomp2()，其查找的就是第一个不大于 3 的元素，因此 lower_bound() 函数是可以
成功运行的。

C++ STL标准库给出了 lower_bound() 函数底层实现的参考代码（如下所示），感兴趣的读者可自行研究，这里不再赘述：
template <class ForwardIterator, class T>
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
    ForwardIterator it;
    iterator_traits<ForwardIterator>::difference_type count, step;
    count = distance(first,last);
    while (count>0)
    {
        it = first; step=count/2; advance (it,step);
        if (*it<val) {  //或者 if (comp(*it,val))，对应第 2 种语法格式
            first=++it;
            count-=step+1;
        }
        else count=step;
    }
    return first;
}

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV = {1, 3, 4, 5, 5, 5, 5, 5, 7, 9};

    // lower_bound() returns the iterator that is first one >= target
    auto ret1 = lower_bound(myV.begin(), myV.end(), 5);
    if (ret1 != myV.end()) cout << "lower_bound returns " << *ret1 << " at index " << distance(myV.begin(), ret1) << endl;

    // upper_bound returns the iterator that is first one > target
    auto ret2 = upper_bound(myV.begin(), myV.end(), 5);
    if (ret2 != myV.end()) cout << "upper_bound returns " << *ret2 << " at index " << distance(myV.begin(), ret2) << endl;

    // when there is no exact target existed in the given vector, lower_bound() returns the first >= iterator of value
    vector<int> myV2 = {1, 3, 5, 7, 9, 11};
    auto ret3 = lower_bound(myV2.begin(), myV2.end(), 6);
    if (ret3 != myV2.end()) cout << "lower_bound returns " << *ret3 << " at index " << distance(myV2.begin(), ret3) << endl;

    // when there is no exact target existed in the given vector, upper_bound() returns the first > iterator of value
    auto ret4 = upper_bound(myV2.begin(), myV2.end(), 6);
    if (ret4 != myV2.end()) cout << "upper_bound returns " << *ret4 << " at index " << distance(myV2.begin(), ret4) << endl;

    // 2022.8.2
    // Note, that means when lower_bound and upper_bound returns one iterator and same, that doesn't 
    // mean the given target value existed based on above example. It may return the next one that 
    // is >= or > target value

    return 0;
    // lower_bound returns 5 at index 3
    // upper_bound returns 7 at index 8
    // lower_bound returns 7 at index 3
    // upper_bound returns 7 at index 3
}
