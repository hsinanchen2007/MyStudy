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

https://en.cppreference.com/w/cpp/algorithm/is_sorted

Checks if the elements in range [first, last) are sorted in non-descending order.

A sequence is sorted with respect to a comparator comp if for any iterator it pointing to the sequence and any non-negative 
integer n such that it + n is a valid iterator pointing to an element of the sequence, comp(*(it + n), *it) evaluates to false.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload resolution unless 
std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> 
(since C++20) is true.

Return value
true if the elements in the range are sorted in non-descending order.


我们知道，排序操作是比较耗费时间的，尤其当数据量很大的时候。因此在设计程序时，我们应该有意识的去避免执行一些不必要的排序操作。

那么，何谓不必要的排序操作呢？举个例子，有这样一组数据：
1 2 3 4 5

这本就是一组有序的数据，如果我们恰巧需要这样的升序序列，就没有必要再执行排序操作。

因此，当程序中涉及排序操作时，我们应该为其包裹一层判断语句，像如下这样：
//...
if(不是有序序列){
    //执行排序算法
}
//...
注意这里的“不是有序序列”，即只要该序列不符合我们指定的排序规则，就不是有序序列。

那么，怎样才能判断一个序列是否为有序序列呢？很简单，使用 is_sorted() 函数即可，此函数专门用于判断某个序列是否为有序序列。
C++ is_sorted()函数
和之前学习的其它排序函数（比如 sorted() 函数）一样，is_sorted() 函数本质上就是一个函数模板，定义在<algorithm>头文件中。因为，在使用该函数之前，
程序中必须先引入此头文件：

#include <algorithm>

is_sorted() 函数有 2 种语法格式，分别是：
//判断 [first, last) 区域内的数据是否符合 std::less<T> 排序规则，即是否为升序序列
bool is_sorted (ForwardIterator first, ForwardIterator last);
//判断 [first, last) 区域内的数据是否符合 comp 排序规则  
bool is_sorted (ForwardIterator first, ForwardIterator last, Compare comp);
其中，first 和 last 都为正向迭代器（这意味着该函数适用于大部分容器），[first, last) 用于指定要检测的序列；comp 用于指定自定义的排序规则。
注意，如果使用默认的升序排序规则，则 [first, last) 指定区域内的元素必须支持使用 < 小于运算符做比较；同样，如果指定排序规则为 comp，也要保证 
[first, last) 区域内的元素支持该规则内部使用的比较运算符。

另外，该函数会返回一个 bool 类型值，即如果 [first, last) 范围内的序列符合我们指定的排序规则，则返回 true；反之，函数返回 false。值得一提得是，
如果 [first, last) 指定范围内只有 1 个元素，则该函数始终返回 true。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::is_sorted
#include <vector>       // std::array
#include <list>         // std::list
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
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 1,2,3,4 };
    //调用第 2 种语法格式的 is_sorted() 函数，该判断语句会得到执行
    if (!is_sorted(myvector.begin(), myvector.end(),mycomp2())) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //调用第一种语法格式的 is_sorted() 函数，该判断语句得不到执行
    if (!is_sorted(mylist.begin(), mylist.end())) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }
    return 0;
}
程序执行结果为：
开始对 myvector 容器排序
4 3 2 1

结合输出结果可以看到，虽然 myvector 容器中的数据为降序序列，但我们需要的是升序序列。因此第 22 行代码中 is_sorted() 函数的返回值为 
false，而 !false 即 true，所以此 if 判断语句会得到执行。

同样在 33 行代码中，mylist 容器中存储的数据为升序序列，和 is_sorted() 函数的要求相符，因此该函数的返回值为 true，而 !true 即 
false，所以此 if 判断语句将无法得到执行。

C++标准库官方网站给出了 is_sorted() 函数底层实现的等效代码，感兴趣的读者可自行前往查看。

C++ is_sorted_until()函数
和 is_sorted() 函数相比，is_sorted_until() 函数不仅能检测出某个序列是否有序，还会返回一个正向迭代器，该迭代器指向的是当前序列中
第一个破坏有序状态的元素。

is_sorted_until() 函数的定义也位于<algorithm>头文件中。因为，在使用该函数之前，程序中必须先引入此头文件：
#include <algorithm>

is_sorted_until() 函数有以下 2 种语法格式：
//排序规则为默认的升序排序
ForwardIterator is_sorted_until (ForwardIterator first, ForwardIterator last);
//排序规则是自定义的 comp 规则
ForwardIterator is_sorted_until (ForwardIterator first,
                                 ForwardIterator last,
                                 Compare comp);
其中，first 和 last 都为正向迭代器（这意味着该函数适用于大部分容器），[first, last) 用于指定要检测的序列；comp 用于指定自定义的排序规则。
注意，如果使用默认的升序排序规则，则 [first, last) 指定区域内的元素必须支持使用 < 小于运算符做比较；同样，如果指定排序规则为 comp，也要保证 
[first, last) 区域内的元素支持该规则内部使用的比较运算符。

可以看到，该函数会返回一个正向迭代器。对于第一种语法格式来说，该函数返回的是指向序列中第一个破坏升序规则的元素；对于第二种语法格式来说，该函数
返回的是指向序列中第一个破坏 comp 排序规则的元素。注意，如果 [first, last) 指定的序列完全满足默认排序规则或者 comp 排序规则的要求，则该
函数将返回一个和 last 迭代器指向相同的正向迭代器。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::is_sorted_until
#include <vector>        // std::array
#include <list>            // std::list

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
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 1,2,3,4 };
    //如果返回值为 myvector.end()，则表明 myvector 容器中的序列符合 mycomp2() 规则
    if (is_sorted_until(myvector.begin(), myvector.end(),mycomp2()) != myvector.end()) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //该判断语句得不到执行
    if (is_sorted_until(mylist.begin(), mylist.end()) != mylist.end()) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }
    return 0;
}

程序执行结果为：
开始对 myvector 容器排序
4 3 2 1

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事
+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV = {1, 3, 5, 2, 4, 6};

    // use is_sorted() to see if this vector is sorted by non-descending order
    if (!is_sorted(myV.begin(), myV.end())) {
        cout << "Original vector is not sorted" << endl;
    } else {
        cout << "Original vector is sorted" << endl;
    }

    // perform sorting and reverse
    sort(myV.begin(), myV.end());
    reverse(myV.begin(), myV.end());
    for_each(myV.begin(), myV.end(), [](int v){ cout << v << endl;});

    // as the order now is sorted but descending, it will return not sorted
    if (!is_sorted(myV.begin(), myV.end())) {
        cout << "Now vector is not sorted" << endl;
    } else {
        cout << "Now vector is sorted" << endl;
    }

    // use rbegin()/rend(), it will return sorted
    if (!is_sorted(myV.rbegin(), myV.rend())) {
        cout << "Now vector is not sorted by rbegin()/rend()" << endl;
    } else {
        cout << "Now vector is sorted by rbegin()/rend()" << endl;
    }
    return 0;
    // Original vector is not sorted
    // 6
    // 5
    // 4
    // 3
    // 2
    // 1
    // Now vector is not sorted
    // Now vector is sorted by rbegin()/rend()
}