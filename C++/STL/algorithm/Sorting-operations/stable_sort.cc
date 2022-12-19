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

https://en.cppreference.com/w/cpp/algorithm/stable_sort

Sorts the elements in the range [first, last) in non-descending order. The order of equivalent 
elements is guaranteed to be preserved.

A sequence is sorted with respect to a comparator comp if for any iterator it pointing to the 
sequence and any non-negative integer n such that it + n is a valid iterator pointing to an 
element of the sequence, comp(*(it + n), *it) (or *(it + n) < *it) evaluates to false.

1) Elements are compared using operator<.
3) Elements are compared using the given comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in 
overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
(none)


通过阅读《C++ sort()排序函数》一节，读者已经了解了 sort() 函数的功能和用法。值得一提的是，当指定范围内包含多个相等
的元素时，sort() 排序函数无法保证不改变它们的相对位置。那么，如果既要完成排序又要保证相等元素的相对位置，该怎么办呢？
可以使用 stable_sort() 函数。有些场景是需要保证相等元素的相对位置的。例如对于一个保存某种事务（比如银行账户）的容器，
在处理这些事务之前，为了能够有序更新这些账户，需要按照账号对它们进行排序。而这时就很有可能出现相等的账号（即同一账号在
某段时间做多次的存取钱操作），它们的相对顺序意味着添加到容器的时间顺序，此顺序不能修改，否则很可能出现账户透支的情况。

值得一提的是，stable_sort() 函数完全可以看作是 sort() 函数在功能方面的升级版。换句话说，stable_sort() 和 sort() 
具有相同的使用场景，就连语法格式也是相同的（后续会讲），只不过前者在功能上除了可以实现排序，还可以保证不改变相等元素的
相对位置。注意，关于 stable_sort() 函数的使用场景，《C++ sort() 排序函数》一节已经做了详细的介绍，这里不再赘述。
另外，stable_sort() 函数是基于归并排序实现的，关于此排序算法的具体实现过程，感兴趣的读者可阅读《归并排序算法》一文。

和 sort() 函数一样，实现 stable_sort() 的函数模板也位于<algorithm>头文件中，因此在使用该函数前，程序也应包含如下
语句：

#include <algorithm>
并且，stable_sort() 函数的用法也有 2 种，其语法格式和 sort() 函数完全相同（仅函数名不同）：
//对 [first, last) 区域内的元素做默认的升序排序
void stable_sort ( RandomAccessIterator first, RandomAccessIterator last );
//按照指定的 comp 排序规则，对 [first, last) 区域内的元素进行排序
void stable_sort ( RandomAccessIterator first, RandomAccessIterator last, Compare comp );
其中，first 和 last 都为随机访问迭代器，它们的组合 [first, last) 用来指定要排序的目标区域；另外在第 2 种格式中，
comp 可以是 C++ STL 标准库提供的排序规则（比如 std::greater<T>），也可以是自定义的排序规则。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::stable_sort
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
    std::stable_sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71) 26 80 53 33
    //调用第二种语法格式，利用STL标准库提供的其它比较规则（比如 greater<T>）进行排序
    std::stable_sort(myvector.begin(), myvector.begin() + 4, std::greater<int>()); //(71 45 32 12) 26 80 53 33
    //调用第二种语法格式，通过自定义比较规则进行排序,这里也可以换成 mycomp2()
    std::stable_sort(myvector.begin(), myvector.end(), mycomp);//12 26 32 33 45 53 71 80
    //输出 myvector 容器中的元素
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << ' ';
    }
    return 0;
}
程序执行结果为：
12 26 32 33 45 53 71 80

那么，stable_sort() 函数的效率怎么样呢？当可用空间足够的情况下，该函数的时间复杂度可达到O(N*log2(N))；反之，
时间复杂度为O(N*log2(N)2)，其中 N 为指定区域 [first, last) 中 last 和 first 的距离。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

struct Employee
{
    int age;
    std::string name;  // Does not participate in comparisons
};
 
bool operator<(const Employee & lhs, const Employee & rhs)
{
    return lhs.age < rhs.age;
}
 
int main()
{
    std::vector<Employee> v =
    { 
        {108, "Zaphod"},
        {32, "Arthur"},
        {108, "Ford"},
    };  
 
    std::stable_sort(v.begin(), v.end());
 
    for (const Employee & e : v)
        std::cout << e.age << ", " << e.name << '\n';

    return 0;
    // 32, Arthur
    // 108, Zaphod
    // 108, Ford
}
