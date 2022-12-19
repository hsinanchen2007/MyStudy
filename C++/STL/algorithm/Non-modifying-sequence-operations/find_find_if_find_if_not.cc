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

https://en.cppreference.com/w/cpp/algorithm

Returns an iterator to the first element in the range [first, last) that satisfies specific 
criteria:

1) find searches for an element equal to value
3) find_if searches for an element for which predicate p returns true
5) find_if_not searches for an element for which predicate q returns false
2,4,6) Same as (1,3,5), but executed according to policy. These overloads do not participate 
in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) 
is true.

Return value
Iterator to the first element satisfying the condition or last if no such element is found.


find() 函数本质上是一个模板函数，用于在指定范围内查找和目标元素值相等的第一个元素。

如下为 find() 函数的语法格式：
InputIterator find (InputIterator first, InputIterator last, const T& val);

其中，first 和 last 为输入迭代器，[first, last) 用于指定该函数的查找范围；val 为要查找的目标元素。
正因为 first 和 last 的类型为输入迭代器，因此该函数适用于所有的序列式容器。

另外，该函数会返回一个输入迭代器，当 find() 函数查找成功时，其指向的是在 [first, last) 区域内查找到的
第一个目标元素；如果查找失败，则该迭代器的指向和 last 相同。

值得一提的是，find() 函数的底层实现，其实就是用==运算符将 val 和 [first, last) 区域内的元素逐个进行
比对。这也就意味着，[first, last) 区域内的元素必须支持==运算符。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

using namespace std;

int main() {
    //find() 函数作用于普通数组
    char stl[] ="http://c.biancheng.net/stl/";
    //调用 find() 查找第一个字符 'c'
    char * p = find(stl, stl + strlen(stl), 'c');
    //判断是否查找成功
    if (p != stl + strlen(stl)) {
        cout << p << endl;
    }
    //find() 函数作用于容器
    std::vector<int> myvector{ 10,20,30,40,50 };
    std::vector<int>::iterator it;
    it = find(myvector.begin(), myvector.end(), 30);
    if (it != myvector.end())
        cout << "查找成功：" << *it;
    else
        cout << "查找失败";
    return 0;
}

程序执行结果为：
c.biancheng.net/stl/
查找成功：30

可以看到，find() 函数除了可以作用于序列式容器，还可以作用于普通数组。

对于 find() 函数的底层实现，C++ 标准库中给出了参数代码，感兴趣的读者可自行研究：
template<class InputIterator, class T>
InputIterator find (InputIterator first, InputIterator last, const T& val)
{
    while (first!=last) {
        if (*first==val) return first;
        ++first;
    }
    return last;
}
关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，
坚持原创，专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。


继《C++ find()函数》一节后，本节再讲解 2 个和 find() 功能类似的函数，分别为 find_if() 函数和 
find_if_not() 函数。

值得一提的是，find_if() 和 find_if_not() 函数都定义在<algorithm>头文件中。因此在使用它们之前，
程序中要先引入此头文件：

#include <algorithm>
C++ find_if()函数
和 find() 函数相同，find_if() 函数也用于在指定区域内执行查找操作。不同的是，前者需要明确指定要
查找的元素的值，而后者则允许自定义查找规则。

所谓自定义查找规则，实际上指的是有一个形参且返回值类型为 bool 的函数。值得一提的是，该函数可以是
一个普通函数（又称为一元谓词函数），比如：

bool mycomp(int i) {
  return ((i%2)==1);
}
上面的 mycomp() 就是一个一元谓词函数，其可用来判断一个整数是奇数还是偶数。
如果读者想更深层次地了解 C++ 谓词函数，可阅读《C++谓词函数》一节。

也可以是一个函数对象，比如：
//以函数对象的形式定义一个 find_if() 函数的查找规则
class mycomp2 {
public:
    bool operator()(const int& i) {
        return ((i % 2) == 1);
    }
};
此函数对象的功能和 mycomp() 函数一样。

确切地说，find_if() 函数会根据指定的查找规则，在指定区域内查找第一个符合该函数要求（使函数返回 
true）的元素。

find_if() 函数的语法格式如下：
InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred);

其中，first 和 last 都为输入迭代器，其组合 [first, last) 用于指定要查找的区域；pred 用于自定义
查找规则。值得一提的是，由于 first 和 last 都为输入迭代器，意味着该函数适用于所有的序列式容器。甚至
当采用适当的谓词函数时，该函数还适用于所有的关联式容器（包括哈希容器）。

同时，该函数会返回一个输入迭代器，当查找成功时，该迭代器指向的是第一个符合查找规则的元素；反之，如果 
find_if() 函数查找失败，则该迭代器的指向和 last 迭代器相同。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

using namespace std;

//自定义一元谓词函数
bool mycomp(int i) {
    return ((i % 2) == 1);
}

//以函数对象的形式定义一个 find_if() 函数的查找规则
class mycomp2 {
public:
    bool operator()(const int& i) {
        return ((i % 2) == 1);
    }
};

int main() {
    vector<int> myvector{ 4,2,3,1,5 };
    //调用 find_if() 函数，并以 IsOdd() 一元谓词函数作为查找规则
    vector<int>::iterator it = find_if(myvector.begin(), myvector.end(), mycomp2());
    cout << "*it = " << *it;
    return 0;
}

程序执行结果为：
*it = 3

结合程序执行结果不难看出，对于 myvector 容器中的元素 4 和 2 来说，它们都无法使 (i%2)==1 这个表达式
成立，因此 mycomp2() 返回 false；而对于元素 3 来说，它可以使 mycomp2() 函数返回 true，因此，
find_if() 函数找到的第一个元素就是元素 3。

值得一提的是，C++ STL find_if()官网给出了 find_if() 函数底层实现的参考代码（如下所示），感兴趣的读者
可自行分析，这里不做过多描述：

template<class InputIterator, class UnaryPredicate>
InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred)
{
    while (first!=last) {
        if (pred(*first)) return first;
        ++first;
    }
    return last;
}
C++ find_if_not()函数
find_if_not() 函数和 find_if() 函数的功能恰好相反，通过上面的学习我们知道，find_if() 函数用于查找符合
谓词函数规则的第一个元素，而 find_if_not() 函数则用于查找第一个不符合谓词函数规则的元素。

find_if_not() 函数的语法规则如下所示：
InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred);

其中，first 和 last 都为输入迭代器，[first, last) 用于指定查找范围；pred 用于自定义查找规则。
和 find_if() 函数一样，find_if_not() 函数也适用于所有的容器，包括所有序列式容器和关联式容器。

同样，该函数也会返回一个输入迭代器，当 find_if_not() 函数查找成功时，该迭代器指向的是查找到的那个元素；反之，
如果查找失败，该迭代器的指向和 last 迭代器相同。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if_not
#include <vector>       // std::vector

using namespace std;

//自定义一元谓词函数
bool mycomp(int i) {
    return ((i % 2) == 1);
}

int main() {
    vector<int> myvector{4,2,3,1,5};
    //调用 find_if() 函数，并以 mycomp() 一元谓词函数作为查找规则
    vector<int>::iterator it = find_if_not(myvector.begin(), myvector.end(), mycomp);
    cout << "*it = " << *it;
    return 0;
}

程序执行结果为：
*it = 4

可以看到，由于第一个元素 4 就不符合 (i%2)==1，因此 find_if_not() 成功找到符合条件的元素，并返回一个指向
该元素的迭代器。

find_if_not() 函数的底层实现和 find_if() 函数非常类似，C++ STL find_if_not()官网给出了该函数底层实现
的参考代码，感兴趣的读者可自行分析，这里不做过多描述：

template<class InputIterator, class UnaryPredicate>
InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred)
{
    while (first!=last) {
        if (!pred(*first)) return first;
        ++first;
    }
    return last;
}

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV1 = {1, 3, 5, 7, 9, 10};
    vector<int> myV2 = {1, 3, 5, 6, 4, 2};

    // use find() to check and return iterator
    auto ret1 = find(myV1.begin(), myV1.end(), 7);
    if (ret1 != myV1.end()) cout << "Found " << *ret1 << endl;

    // use find() to check and return iterator, and this given vector is NOT sorted
    auto ret2 = find(myV2.begin(), myV2.end(), 4);
    if (ret2 != myV2.end()) cout << "Found " << *ret2 << endl;

    // find_if() with condition, can be lambdas or unary predicate which returns true
    // note that we are looing for something that the condition returns true
    auto is_even = [](int i){ return i%2 == 0; };
    auto ret3 = find_if(myV1.begin(), myV1.end(), is_even);
    if (ret3 != myV1.end()) cout << "Found first even number " << *ret3 << endl;

    auto ret4 = find_if(myV1.begin(), myV1.end(), [](int v){ return ( v % 2 != 0);});
    if (ret4 != myV1.end()) cout << "Found first odd number " << *ret4 << endl;

    // find_if_not() with condition, can be lambdas or unary predicate which returns false
    // note that now we are looking for NOT condition, so the one returned is NOT v % 2 == 1
    // so we are actually looking for even number here
    auto ret5 = find_if_not(myV1.begin(), myV1.end(), [](int v){ return ( v % 2 == 1);});
    if (ret5 != myV1.end()) cout << "Found first even number " << *ret5 << endl;

    // 2022.8.5
    // need to ensure find_if() is looking for true condition, while
    // find_if_not() is looking for false condition
    // Starting from C++ 23, there are few new functions like:
    // find_last(), find_last_if(), find_last_if_not()

    return 0;
    // Found 7
    // Found 4
    // Found first even number 10
    // Found first odd number 1
    // Found first even number 10
}
