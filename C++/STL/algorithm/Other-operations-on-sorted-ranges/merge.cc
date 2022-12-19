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
#include <random>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/merge

Merges two sorted ranges [first1, last1) and [first2, last2) into one sorted range beginning at d_first.

A sequence is said to be sorted with respect to a comparator comp if for any iterator it pointing to the 
sequence and any non-negative integer n such that it + n is a valid iterator pointing to an element of 
the sequence, comp(*(it + n), *it) evaluates to false.

1) Elements are compared using operator<.
3) Elements are compared using the given binary comparison function comp.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.
This merge function is stable, which means that for equivalent elements in the original two ranges, 
the elements from the first range (preserving their original order) precede the elements from the second 
range (preserving their original order).

The behavior is undefined if the destination range overlaps either of the input ranges (the input ranges 
may overlap each other).

Return value
An output iterator to element past the last element copied.


有些场景中，我们需要将 2 个有序序列合并为 1 个有序序列，这时就可以借助 merge() 或者 inplace_merge() 函数实现。

值得一提的是，merge() 和 inplace_merge() 函数都定义在<algorithm>头文件中，因此在使用它们之前，程序中必须提前引入该头文件：
#include <algorithm>
C++ merge()函数
merge() 函数用于将 2 个有序序列合并为 1 个有序序列，前提是这 2 个有序序列的排序规则相同（要么都是升序，要么都是降序）。
并且最终借助该函数获得的新有序序列，其排序规则也和这 2 个有序序列相同。

举个例子，假设有 2 个序列，分别为5,10,15,20,25和7,14,21,28,35,42，显然它们不仅有序，而且都是升序序列。因此借助 merge() 
函数，我们就可以轻松获得如下这个有序序列：
5 7 10 15 17 20 25 27 37 47 57

可以看到，该序列不仅包含以上 2 个序列中所有的元素，并且其本身也是一个升序序列。

值得一提的是，C++ STL 标准库的开发人员考虑到用户可能需要自定义排序规则，因此为 merge() 函数设计了以下 2 种语法格式：
//以默认的升序排序作为排序规则
OutputIterator merge (InputIterator1 first1, InputIterator1 last1,
                      InputIterator2 first2, InputIterator2 last2,
                      OutputIterator result);
//以自定义的 comp 规则作为排序规则
OutputIterator merge (InputIterator1 first1, InputIterator1 last1,
                      InputIterator2 first2, InputIterator2 last2,
                      OutputIterator result, Compare comp);
可以看到，first1、last1、first2 以及 last2 都为输入迭代器，[first1, last1) 和 [first2, last2) 各用来指定一个有序序列；
result 为输出迭代器，用于为最终生成的新有序序列指定存储位置；comp 用于自定义排序规则。同时，该函数会返回一个输出迭代器，其指向
的是新有序序列中最后一个元素之后的位置。

注意，当采用第一种语法格式时，[first1, last1) 和 [first2, last2) 指定区域内的元素必须支持 < 小于运算符；同样当采用第二种
语法格式时，[first1, last1) 和 [first2, last2) 指定区域内的元素必须支持 comp 排序规则内的比较运算符。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::merge
#include <vector>       // std::vector

using namespace std;

int main() {
    //first 和 second 数组中各存有 1 个有序序列
    int first[] = { 5,10,15,20,25 };
    int second[] = { 7,17,27,37,47,57 };
    //用于存储新的有序序列
    vector<int> myvector(11);
    //将 [first,first+5) 和 [second,second+6) 合并为 1 个有序序列，并存储到 myvector 容器中。
    merge(first, first + 5, second, second + 6, myvector.begin());
    //输出 myvector 容器中存储的元素
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << ' ';
    }   
    return 0;
}

程序执行结果为：
5 7 10 15 17 20 25 27 37 47 57

可以看到，first 数组和 second 数组中各存有 1 个升序序列，通过借助 merge() 函数，我们成功地将它们合并成了一个有序序列，并存储到 
myvector 容器中。
注意，merge() 函数底层是通过拷贝的方式实现合并操作的。换句话说，上面程序在采用 merge() 函数实现合并操作的同时，并不会对 first 
和 second 数组有任何影响。有关该函数的具体实现过程，可查看 C++ STL merge() 官网。

实际上，对于 2 个有序序列是各自存储（像 first 和 second 这样）还是存储到一起，merge() 函数并不关心，只需要给它传入恰当的迭代器
（或指针），该函数就可以正常工作。因此，我们还可以将上面程序改写为：

//该数组中存储有 2 个有序序列
int first[] = { 5,10,15,20,25,7,17,27,37,47,57 };

//用于存储新的有序序列
vector<int> myvector(11);

//将 [first,first+5) 和 [first+5,first+11) 合并为 1 个有序序列，并存储到 myvector 容器中。
merge(first, first + 5,  first + 5, first +11 , myvector.begin());

可以看到，2 个有序序列全部存储到了 first 数组中，但只要给 merge() 函数传入正确的指针，仍可以将它们合并为 1 个有序序列。
感兴趣的读者，可自行验证这段程序，其最终会得到和上面程序相同的 myvector 容器。

C++ inplace_merge()函数
事实上，当 2 个有序序列存储在同一个数组或容器中时，如果想将它们合并为 1 个有序序列，除了使用 merge() 函数，更推荐使用 
inplace_merge() 函数。

和 merge() 函数相比，inplace_merge() 函数的语法格式要简单很多：
//默认采用升序的排序规则
void inplace_merge (BidirectionalIterator first, BidirectionalIterator middle,
                    BidirectionalIterator last);
//采用自定义的 comp 排序规则
void inplace_merge (BidirectionalIterator first, BidirectionalIterator middle,
                    BidirectionalIterator last, Compare comp);
其中，first、middle 和 last 都为双向迭代器，[first, middle) 和 [middle, last) 各表示一个有序序列。

和 merge() 函数一样，inplace_merge() 函数也要求 [first, middle) 和 [middle, last) 指定的这 2 个序列必须遵循相同
的排序规则，且当采用第一种语法格式时，这 2 个序列中的元素必须支持 < 小于运算符；同样，当采用第二种语法格式时，这 2 个序列
中的元素必须支持 comp 排序规则内部的比较运算符。不同之处在于，merge() 函数会将最终合并的有序序列存储在其它数组或容器中，
而 inplace_merge() 函数则将最终合并的有序序列存储在 [first, last) 区域中。

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

可以看到，first 数组中包含 2 个升序序列，借助 inplace_merge() 函数，实现了将这 2 个序列合并为 1 个升序序列，且新序列仍
存储在 first 数组中。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事
+学习历程+工作记录+生活日常+编程资料。

*/

auto print = [](auto const rem, auto const& v)
{
    std::cout << rem;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
};

int main()
{
    // fill the vectors with random numbers
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, 9);
 
    std::vector<int> v1(10), v2(10);
    std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
    std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));
 
    print("Originally:\nv1: ", v1);
    print("v2: ", v2);
 
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
 
    print("After sorting:\nv1: ", v1);
    print("v2: ", v2);
 
    // merge, note that it required two sorted ranges before such merge, and merge them
    // into one sorted range as well. Also, the merge() is a stable merge where their
    // corresponding order of original ranges will remain same
    std::vector<int> dst;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));
 
    print("After merging:\ndst: ", dst);

    return 0;
    // Originally:
    // v1: 1 8 3 5 9 0 1 2 7 7 
    // v2: 8 4 7 7 4 0 3 7 9 6 
    // After sorting:
    // v1: 0 1 1 2 3 5 7 7 8 9 
    // v2: 0 3 4 4 6 7 7 7 8 9 
    // After merging:
    // dst: 0 0 1 1 2 3 3 4 4 5 6 7 7 7 7 7 8 8 9 9 
}
