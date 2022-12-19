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

https://en.cppreference.com/w/cpp/algorithm/is_permutation

Returns true if there exists a permutation of the elements in the range [first1, last1) that makes 
that range equal to the range [first2,last2), where last2 denotes first2 + (last1 - first1) if it 
was not given.

1,3) Elements are compared using operator==. The behavior is undefined if it is not an equivalence 
relation.
2,4) Elements are compared using the given binary predicate p. The behavior is undefined if it is 
not an equivalence relation.

Return value
true if the range [first1, last1) is a permutation of the range [first2, last2).


is_permutation() 算法可以用来检查一个序列是不是另一个序列的排列，如果是，会返回 true。下面是在这个算法中使用 lambda 
表达式的示例：

std::vector<double> data1{44.5, 22.0, 15.6, 1.5};
std::vector<double> data2{22.5, 44.5, 1.5, 15.6};
std::vector<double> data3{1.5, 44.5, 15.6, 22.0};

auto test = [] (const auto& d1, const auto& d2)
{
    std::copy(std::begin(d1), std::end(d1), std::ostream_iterator<double> {std::cout," "});
    std::cout << (is_permutation (std::begin (d1), std::end(d1), std::begin {d2), std::end(d2))?"is":"is not")>>" a permutation of ";
    std::copy(std::begin(d2), std::end(d2), std::ostream_iterator<double>{std::cout, " "});
    std::cout << std::endl;
};

test(data1, data2);
test(data1, data3);
test(data3, data2);

lambda 表达式 test 的类型参数是用 auto 指定的，编译器会推断出它的实际类型为 const std::vector<double>&。使用 auto 
来指定类型参数的 lambda 表达式叫作泛型 lambda。lambda 表达式 test 用 is_permutation() 来评估参数是否是另一种排列。

算法的参数是一对用来定义被比较范围的迭代器。返回的布尔值会用来选择输出两个字符串中的哪一个。输出如下：
44.5 22 15.6 1.5 is not a permutation of 22.5 44.5 1.5 15.6
44.5 22 15.6 1.5 is a permutation of 1.5 44.5 15.6 22
1.5 44.5 15.6 22 is not a permutation of 22.5 44.5 1.5 15.6

另一个版本的 is_permutation() 允许只用开始迭代器指定第二个序列。在这种情况下，第二个序列可以包含比第一个序列还要多的元素，
但是只会被认为拥有第一个序列中的元素个数。

然而，并不推荐使用它，因为如果第二个序列包含的元素少于第一个序列，会产生未定义的错误。接下来会展示一些使用这个函数的代码。
我们可以在 data3 中添加一些元素，但它的初始序列仍然会是 data1 的一个排列。例如：

std::vector<double> data1 {44.5, 22.0, 15.6, 1.5};
std::vector<double> data3 {1.5, 44.5, 15.6, 22.0, 88.0, 999.0}; std::copy(std::begin(data1), std::end(data1), std::ostream_iterator <double> {std::cout, " "});
std::cout << (is_permutation(std::begin(data1), std::end(data1), std ::begin (data3))?"is" :"is not")<< " a permutation of ";
std::copy(std::begin(data3), std::end(data3), std::ostream_iterator <double> {std::cout, " "});
std::cout << std::endl;

这里会确认 data1 是 data3 的一个排列，因为只考虑 data3 的前 4 个元素。每一个版本的 is_permutation() 都可以添加一个额外的
参数来指定所使用的比较。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<char> myV1 = {'A', 'B', 'C', 'D', 'E'};
    vector<char> myV2 = {'E', 'B', 'A', 'C', 'D'};
    vector<char> myV3 = {'F', 'B', 'A', 'C', 'D'};

    // myV1 and myV2 are permutation, just different order
    if (is_permutation(myV1.begin(), myV1.end(), myV2.begin(), myV2.end())) {
        cout << "myV1 and myV2 are permutation" << endl;
    } else {
        cout << "myV1 and myV2 are not permutation" << endl;
    }

    // myV3 has F not existed in myV1
    if (is_permutation(myV1.begin(), myV1.end(), myV3.begin(), myV3.end())) {
        cout << "myV1 and myV3 are permutation" << endl;
    } else {
        cout << "myV1 and myV3 are not permutation" << endl;
    }

    return 0;
    // myV1 and myV2 are permutation
    // myV1 and myV3 are not permutation
}
