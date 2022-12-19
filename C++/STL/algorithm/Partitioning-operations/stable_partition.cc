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

https://en.cppreference.com/w/cpp/algorithm/stable_partition

1) Reorders the elements in the range [first, last) in such a way that all elements for which the 
predicate p returns true precede the elements for which predicate p returns false. Relative order 
of the elements is preserved.
2) Same as (1), but executed according to policy. This overload does not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
Iterator to the first element of the second group

partition 可直译为“分组”，partition() 函数可根据用户自定义的筛选规则，重新排列指定区域内存储的数据，使其分为 2 组，
第一组为符合筛选条件的数据，另一组为不符合筛选条件的数据。

举个例子，假设有一个数组 a[9]，其存储数据如下：
1 2 3 4 5 6 7 8 9

在此基础上，如果设定筛选规则为 i%2=0（其中 i 即代指数组 a 中的各个元素），则借助 partition() 函数，a[9] 数组中存储
数据的顺序可能变为：
1 9 3 7 5 6 4 8 2

其中 {1,9,3,7,5} 为第一组，{6,4,8,2} 为第二组。显然前者中的各个元素都符合筛选条件，而后者则都不符合。由此还可看出，
partition() 函数只会根据筛选条件将数据进行分组，并不关心分组后各个元素具体的存储位置。
如果想在分组之后仍不改变各元素之间的相对位置，可以选用 stable_partition() 函数。有关此函数的功能和用法，本节后续会做
详细讲解。

值得一提得是，partition() 函数定义于<algorithm>头文件中，因此在使用该函数之前，程序中应先引入此头文件：
#include <algorithm>
如下为 partition() 函数的语法格式：
ForwardIterator partition (ForwardIterator first,
                           ForwardIterator last,
                           UnaryPredicate pred);
其中，first 和 last 都为正向迭代器，其组合 [first, last) 用于指定该函数的作用范围；pred 用于指定筛选规则。
所谓筛选规则，其本质就是一个可接收 1 个参数且返回值类型为 bool 的函数，可以是普通函数，也可以是一个函数对象。

同时，partition() 函数还会返回一个正向迭代器，其指向的是两部分数据的分界位置，更确切地说，指向的是第二组数据中的第 1 
个元素。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::partition
#include <vector>       // std::vector

using namespace std;

//以普通函数的方式定义partition()函数的筛选规则
bool mycomp(int i) { return (i % 2) == 0; }

//以函数对象的形式定义筛选规则
class mycomp2 {
public:
    bool operator()(const int& i) {
        return (i%2 == 0);
    }
};

int main() {
    std::vector<int> myvector{1,2,3,4,5,6,7,8,9};
    std::vector<int>::iterator bound;
    //以 mycomp2 规则，对 myvector 容器中的数据进行分组
    bound = std::partition(myvector.begin(), myvector.end(), mycomp2());
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\nbound = " << *bound;
    return 0;
}
程序执行结果为：
8 2 6 4 5 3 7 1 9
bound = 5

可以看到，程序中借助 partition() 对 myvector 容器中的数据进行了再加工，基于 mycomp2() 筛选规则，能够被 2 整除
的元素位于第 1 组，不能被 2 整除的元素位于第 2 组。

同时，parition() 函数会返回一个迭代器，通过观察程序的执行结果可以看到，该迭代器指向的是元素 5，同时也是第 2 组数据
中的第 1 个元素。值得一提的是，C++ STL partition()函数官方给出了该函数底层实现的参考代码，感兴趣的读者可自行前往
分析，这里不再做过多描述。

C++ stable_partition()函数
前面提到，partition() 函数只负责对指定区域内的数据进行分组，并不保证各组中元素的相对位置不发生改变。而如果想在分组的
同时保证不改变各组中元素的相对位置，可以使用 stable_partition() 函数。

也就是说，stable_partition() 函数可以保证对指定区域内数据完成分组的同时，不改变各组内元素的相对位置。

仍以数组 a[9] 举例，其存储的数据如下：
1 2 3 4 5 6 7 8 9

假定筛选规则为 i%2=0（其中 i 即代指数组 a 中的各个元素），则借助 stable_partition() 函数，a[9] 数组中存储数据的
顺序为：
2 4 6 8 1 3 5 7 9

其中 {2,4,6,8} 为一组，{1,3,5,7,9} 为另一组。通过和先前的 a[9] 对比不难看出，各个组中元素的相对位置没有发生改变。
所谓元素的相对位置不发生改变，以 {2,4,6,8} 中的元素 4 为例，在原 a[9] 数组中，该元素位于 2 的右侧，6 和 8 的左侧；
在经过 stable_partition() 函数处理后的 a[9] 数组中，元素 4 仍位于 2 的右侧，6 和 8 的左侧。因此，该元素的相对位置
确实没有发生改变。

stable_partition() 函数定义在<algorithm>头文件中，其语法格式如下：
BidirectionalIterator stable_partition (BidirectionalIterator first,
                                        BidirectionalIterator last,
                                        UnaryPredicate pred);
其中，first 和 last 都为双向迭代器，其组合 [first, last) 用于指定该函数的作用范围；pred 用于指定筛选规则。

同时，stable_partition() 函数还会返回一个双向迭代器，其指向的是两部分数据的分界位置，更确切地说，指向的是第二组数据
中的第 1 个元素。

举个例子：
#include <iostream>     // std::cout
#include <algorithm>    // std::stable_partition
#include <vector>       // std::vector

using namespace std;

//以普通函数的方式定义partition()函数的筛选规则
bool mycomp(int i) { return (i % 2) == 1; }

//以函数对象的形式定义筛选规则
class mycomp2 {
public:
    bool operator()(const int& i) {
        return (i%2 == 1);
    }
};

int main() {
    std::vector<int> myvector{1,2,3,4,5,6,7,8,9};
    std::vector<int>::iterator bound;
    //以 mycomp2 规则，对 myvector 容器中的数据进行分组
    bound = std::stable_partition(myvector.begin(), myvector.end(), mycomp);
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\nbound = " << *bound;
    return 0;
}
程序执行结果为：
1 3 5 7 9 2 4 6 8
bound = 2

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，
专注于分享创业故事+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    std::vector<int> v{0, 0, 3, -1, 2, 4, 5, 0, 7};

    // it will keep original order and partition the given vector
    std::stable_partition(v.begin(), v.end(), [](int n){return n>0;});
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
    // 3 2 4 5 7 0 0 -1 0 
}
