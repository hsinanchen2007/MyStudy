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

https://en.cppreference.com/w/cpp/algorithm/inplace_merge

Merges two consecutive sorted ranges [first, middle) and [middle, last) into one sorted range 
[first, last).

A sequence [first, last) is said to be sorted with respect to a comparator comp if for any 
iterator it pointing to the sequence and any non-negative integer n such that it + n is a valid 
iterator pointing to an element of the sequence, comp(*(it + n), *it) evaluates to false.

This merge is stable, which means that for equivalent elements in the original two ranges, 
the elements from the first range (preserving their original order) precede the elements from 
the second range (preserving their original order).

1) Elements are compared using operator< and the ranges must be sorted with respect to the same.
3) Elements are compared using the given binary comparison function comp and the ranges must be 
sorted with respect to the same.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
(none)


C++ inplace_merge()函数
事实上，当 2 个有序序列存储在同一个数组或容器中时，如果想将它们合并为 1 个有序序列，除了使用 merge() 函数，
更推荐使用 inplace_merge() 函数。

和 merge() 函数相比，inplace_merge() 函数的语法格式要简单很多：
//默认采用升序的排序规则
void inplace_merge (BidirectionalIterator first, BidirectionalIterator middle,
                    BidirectionalIterator last);
//采用自定义的 comp 排序规则
void inplace_merge (BidirectionalIterator first, BidirectionalIterator middle,
                    BidirectionalIterator last, Compare comp);
其中，first、middle 和 last 都为双向迭代器，[first, middle) 和 [middle, last) 各表示一个有序序列。

和 merge() 函数一样，inplace_merge() 函数也要求 [first, middle) 和 [middle, last) 指定的这 2 个序列
必须遵循相同的排序规则，且当采用第一种语法格式时，这 2 个序列中的元素必须支持 < 小于运算符；同样，当采用第二种
语法格式时，这 2 个序列中的元素必须支持 comp 排序规则内部的比较运算符。不同之处在于，merge() 函数会将最终合并
的有序序列存储在其它数组或容器中，而 inplace_merge() 函数则将最终合并的有序序列存储在 [first, last) 区域中。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::merge

using namespace std;

int main() {
    //该数组中存储有 2 个有序序列
    int first[] = { 5,10,15,20,25,7,17,27,37,47,57 };
    //将 [first,first+5) 和 [first+5,first+11) 合并为 1 个有序序列。
    inplace_merge(first, first + 5,first +11);
    for (int i = 0; i < 11; i++) {
        cout << first[i] << " ";
    }
    return 0;
}

程序执行结果为：
5 7 10 15 17 20 25 27 37 47 57

可以看到，first 数组中包含 2 个升序序列，借助 inplace_merge() 函数，实现了将这 2 个序列合并为 1 个升序序列，
且新序列仍存储在 first 数组中。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

template<class Iter>
void merge_sort(vector<int> myV, Iter first, Iter last)
{
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;

        // perform merge sorting from first to middle
        merge_sort(myV, first, middle);
        cout << "current [first middle] : ";
        for_each(myV.begin(), myV.end(), [](int v){ cout << v << " ";});
        cout << endl;

        // perform merge sorting from middle to end
        merge_sort(myV, middle, last);
        cout << "current [middle end] : ";
        for_each(myV.begin(), myV.end(), [](int v){ cout << v << " ";});
        cout << endl;

        // combine the sorting result back to one
        std::inplace_merge(first, middle, last);
    }
}

int main()
{
    std::vector<int> v{8, 2, -2, 0, 11, 11, 1, 7, 3};
    merge_sort(v, v.begin(), v.end());
    for(auto n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
    // current [first middle] : 8 2 -2 0 11 11 1 7 3 
    // current [middle end] : 8 2 -2 0 11 11 1 7 3 
    // current [first middle] : 8 2 -2 0 11 11 1 7 3 
    // current [first middle] : 8 2 -2 0 11 11 1 7 3 
    // current [middle end] : 8 2 -2 0 11 11 1 7 3 
    // current [middle end] : 8 2 -2 0 11 11 1 7 3 
    // current [first middle] : 8 2 -2 0 11 11 1 7 3 
    // current [first middle] : 8 2 -2 0 11 11 1 7 3 
    // current [middle end] : 8 2 -2 0 11 11 1 7 3 
    // current [first middle] : 8 2 -2 0 11 11 1 7 3 
    // current [first middle] : 8 2 -2 0 11 11 1 7 3 
    // current [first middle] : 8 2 -2 0 11 11 1 7 3 
    // current [middle end] : 8 2 -2 0 11 11 1 7 3 
    // current [middle end] : 8 2 -2 0 11 11 1 7 3 
    // current [middle end] : 8 2 -2 0 11 11 1 7 3 
    // current [middle end] : 8 2 -2 0 11 11 1 7 3 
    // -2 0 1 2 3 7 8 11 11 
}
