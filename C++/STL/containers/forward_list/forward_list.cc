// https://leetcode.com/problems/

// some often common headers and namespace
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

/*

forward_list 是 C++ 11 新添加的一类容器，其底层实现和 list 容器一样，采用的也是链表结构，只不过 forward_list 使用的是单链表，而 list 
使用的是双向链表（如图 1 所示）。

单链表和双向链表
图 1 单链表（ a) ）和双向链表（ b) ）
图 1 中，H 表示链表的表头。

通过图 1 不难看出，使用链表存储数据最大的特点在于，其并不会将数据进行集中存储（向数组那样），换句话说，链表中数据的存储位置是分散的、随机的，
整个链表中数据的线性关系通过指针来维持。

因此，forward_list 容器具有和 list 容器相同的特性，即擅长在序列的任何位置进行插入元素或删除元素的操作，但对于访问存储的元素，没有其它容器
（如 array、vector）的效率高。

另外，由于单链表没有双向链表那样灵活，因此相比 list 容器，forward_list 容器的功能受到了很多限制。比如，由于单链表只能从前向后遍历，而不支持
反向遍历，因此 forward_list 容器只提供前向迭代器，而不是双向迭代器。这意味着，forward_list 容器不具有 rbegin()、rend() 之类的成员函数。

有关迭代器的具体分类以及各种迭代器的具体功能，可以阅读《C++ STL迭代器》一节。


那么，既然 forward_list 容器具有和 list 容器相同的特性，list 容器还可以提供更多的功能函数，forward_list 容器有什么存在的必要呢？

当然有，forward_list 容器底层使用单链表，也不是一无是处。比如，存储相同个数的同类型元素，单链表耗用的内存空间更少，空间利用率更高，并且对于
实现某些操作单链表的执行效率也更高。效率高是选用 forward_list 而弃用 list 容器最主要的原因，换句话说，只要是 list 容器和 forward_list 
容器都能实现的操作，应优先选择 forward_list 容器。

forward_list容器的创建
由于 forward_list 容器以模板类 forward_list<T>（T 为存储元素的类型）的形式被包含在<forward_list>头文件中，并定义在 std 命名空间中。
因此，在使用该容器之前，代码中需包含下面两行代码：

#include <forward_list>
using namespace std;
std 命名空间也可以在使用 forward_list 容器时额外注明，两种方式都可以。

创建 forward_list 容器的方式，大致分为以下 5 种。

1) 创建一个没有任何元素的空 forward_list 容器：
std::forward_list<int> values;
由于 forward_list 容器在创建后也可以添加元素，因此这种创建方式很常见。

2) 创建一个包含 n 个元素的 forward_list 容器：
std::forward_list<int> values(10);
通过此方式创建 values 容器，其中包含 10 个元素，每个元素的值都为相应类型的默认值（int类型的默认值为 0）。

3) 创建一个包含 n 个元素的 forward_list 容器，并为每个元素指定初始值。例如：
std::forward_list<int> values(10, 5);
如此就创建了一个包含 10 个元素并且值都为 5 个 values 容器。

4) 在已有 forward_list 容器的情况下，通过拷贝该容器可以创建新的 forward_list 容器。例如：
std::forward_list<int> value1(10);
std::forward_list<int> value2(value1);
注意，采用此方式，必须保证新旧容器存储的元素类型一致。

5) 通过拷贝其他类型容器（或者普通数组）中指定区域内的元素，可以创建新的 forward_list 容器。例如：
//拷贝普通数组，创建forward_list容器
int a[] = { 1,2,3,4,5 };
std::forward_list<int> values(a, a+5);
//拷贝其它类型的容器，创建forward_list容器
std::array<int, 5>arr{ 11,12,13,14,15 };
std::forward_list<int>values(arr.begin()+2, arr.end());//拷贝arr容器中的{13,14,15}
forward_list容器支持的成员函数
表 2 中罗列出了 forward_list 模板类提供的所有成员函数以及各自的功能。

表 2 forward_list 容器可用的成员函数
成员函数	功能
before_begin()	返回一个前向迭代器，其指向容器中第一个元素之前的位置。
begin()	返回一个前向迭代器，其指向容器中第一个元素的位置。
end()	返回一个前向迭代器，其指向容器中最后一个元素之后的位置。
cbefore_begin()	和 before_begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
empty()	判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
max_size()	返回容器所能包含元素个数的最大值。这通常是一个很大的值，一般是 232-1，所以我们很少会用到这个函数。
front()	返回第一个元素的引用。
assign()	用新元素替换容器中原有内容。
push_front()	在容器头部插入一个元素。
emplace_front()	在容器头部生成一个元素。该函数和 push_front() 的功能相同，但效率更高。
pop_front()	删除容器头部的一个元素。
emplace_after()	在指定位置之后插入一个新元素，并返回一个指向新元素的迭代器。和 insert_after() 的功能相同，但效率更高。
insert_after()	在指定位置之后插入一个新元素，并返回一个指向新元素的迭代器。
erase_after()	删除容器中某个指定位置或区域内的所有元素。
swap()	交换两个容器中的元素，必须保证这两个容器中存储的元素类型是相同的。
resize()	调整容器的大小。
clear()	删除容器存储的所有元素。
splice_after()	将某个 forward_list 容器中指定位置或区域内的元素插入到另一个容器的指定位置之后。
remove(val)	删除容器中所有等于 val 的元素。
remove_if()	删除容器中满足条件的元素。
unique()	删除容器中相邻的重复元素，只保留一个。
merge()	合并两个事先已排好序的 forward_list 容器，并且合并之后的 forward_list 容器依然是有序的。
sort()	通过更改容器中元素的位置，将它们进行排序。
reverse()	反转容器中元素的顺序。
除此之外，C++ 11 标准库还新增加了 begin() 和 end() 这 2 个函数，和 forward_list 容器包含的 begin() 和 end() 成员函数不同，标准库提供的这
 2 个函数的操作对象，既可以是容器，还可以是普通数组。当操作对象是容器时，它和容器包含的 begin() 和 end() 成员函数的功能完全相同；如果操作对象
 是普通数组，则 begin() 函数返回的是指向数组第一个元素的指针，同样 end() 返回指向数组中最后一个元素之后一个位置的指针（注意不是最后一个元素）。

forward_list 容器还有一个std::swap(x , y)非成员函数（其中 x 和 y 是存储相同类型元素的 forward_list 容器），它和 swap() 成员函数的功能完全
相同，仅使用语法上有差异。

下面的样例演示了表 2 中部分成员函数的用法：

#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    std::forward_list<int> values{1,2,3};
    values.emplace_front(4);//{4,1,2,3}
    values.emplace_after(values.before_begin(), 5); //{5,4,1,2,3}
    values.reverse();//{3,2,1,4,5}
    for (auto it = values.begin(); it != values.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}
运行结果为：
3 2 1 4 5

表 2 中这些成员函数的具体用法，后续学习用到时会具体讲解，感兴趣的读者，也可以通过查阅 STL手册做详细了解。

和使用forward_list容器相关的函数
通过表 2 我们知道，forward_list 容器中是不提供 size() 函数的，但如果想要获取 forward_list 容器中存储元素的个数，可以使用头文件 <iterator>
中的 distance() 函数。举个例子：

#include <iostream>
#include <forward_list>
#include <iterator>
using namespace std;
int main()
{
    std::forward_list<int> my_words{1,2,3,4};
    int count = std::distance(std::begin(my_words), std::end(my_words));
    cout << count;
    return 0;
}
运行结果为：
4


并且，forward_list 容器迭代器的移动除了使用 ++ 运算符单步移动，还能使用 advance() 函数，比如：
#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    std::forward_list<int> values{1,2,3,4};
    auto it = values.begin();
    advance(it, 2);
    while (it!=values.end())
    {
        cout << *it << " ";
        ++it;
    }
    return 0;
}
运行结果为：
3 4

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+工作记录+
生活日常+编程资料。

*/

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

// solution
void myprint(double value) {
    cout << value << endl;
}

// main
int main() {
    forward_list<double> myForwardList = {1.1, 2.2, 3.3, 4.4, 5.5};
    forward_list<double> myOrgForwardList(myForwardList.begin(), myForwardList.end());

    // forward_list, we only know the head/begin, not tail/end, so most functions are same as list except:
    // 1. No size() as it didn't know the end. Everything needed to start from the beginning
    // 2. All add/remove/insert calls will start from the beginning, or before one specific iterator location
    // 3. No back() call

    // iterator, before_begin()/cbefore_begin(), as forward_list didn't have "back" direct access, but it allows
    // to access something before the begin(). Only forward_list has these two functions
    // STL: Returns an iterator to the element before the first element of the container. This element acts as a 
    // placeholder, attempting to access it results in undefined behavior. The only usage cases are in functions 
    // insert_after(), emplace_after(), erase_after(), splice_after() and the increment operator: incrementing the 
    // before-begin iterator gives exactly the same iterator as obtained from begin()/cbegin().
    cout << "Before inserting one element before begin()" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);
    auto beforeBegin = myForwardList.before_begin();
    myForwardList.insert_after(beforeBegin, 0.0);
    cout << "After inserting one element before begin()" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);

    // again, no back() or size() functions as it is forward list, so as it cannot access elements to the end directly,
    // no size() of back() call

    // insert_after()/emplace_after()/erase_after(), insert/create/erase one element after the specific iterator location
    cout << "Before inserting two new elements with same begin iterator" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);
    auto beginPtr = myForwardList.begin();
    myForwardList.insert_after(beginPtr, 0.5);
    myForwardList.emplace_after(beginPtr, 0.6);
    // 0.6 will be added before 0.5, as the beginPtr remains same
    cout << "After inserting two new elements with same begin iterator" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);
    myForwardList.erase_after(beginPtr);
    myForwardList.erase_after(beginPtr);
    cout << "After erasing two new elements with same begin iterator" << endl;
    for_each(myForwardList.begin(), myForwardList.end(), myprint);

    // clear()/push_front()/emplace_front()/pop_front()/resize()/swap() are all same functions as list

    // splice_after(), insert another list after the specific iterator location
    cout << "After inserting another list to after begin iterator" << endl;
    myForwardList.splice_after(beginPtr, myOrgForwardList);
    for_each(myForwardList.begin(), myForwardList.end(), myprint);

    return 0;
}
