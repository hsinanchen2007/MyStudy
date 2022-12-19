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

https://en.cppreference.com/w/cpp/algorithm/copy_n

1) Copies exactly count values from the range beginning at first to the range beginning at result. 
Formally, for each integer 0 ≤ i < count, performs *(result + i) = *(first + i). Overlap of ranges 
is formally permitted, but leads to unpredictable ordering of the results.
2) Same as (1), but executed according to policy. This overload does not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.


copy_n() 算法可以从源容器复制指定个数的元素到目的容器中。第一个参数是指向第一个源元素的输入迭代器，第二个参数是需要复制
的元素的个数，第三个参数是指向目的容器的第一个位置的迭代器。这个算法会返回一个指向最后一个被复制元素的后一个位置的迭代器，
或者只是第三个参数——输出迭代器——如果第二个参数为 0。下面是一个使用它的示例：

std::vector<string> names {"A1","Beth", "Carol", "Dan", "Eve","Fred","George" ,"Harry", "Iain", "Joe"};
std::unordered_set<string> more_names {"Janet", "John"};
std::copy_n(std:rbegin(names)+1, 3, std::inserter(more_names, std::begin(more_names)));

这个 copy_n() 操作会从 names 的第二个元素开始复制 3 个元素到关联容器 more_names 中。目的容器是由一个 unordered_set 
容器的 insert_iterator 对象指定的，它是由 inserter() 函数模板生成的。insert_iterator 对象会调用容器的成员函数 
insert() 来向容器中添加元素。

当然，copy_n() 的目的地址也可是以流迭代器：
std::copy_n(std::begin(more_names), more_names.size()-1,std::ostream_iterator<string> {std::cout, " "});

这样会输出 more_names 中除了最后一个元素之外的全部元素。注意，如果被复制元素的个数超过了实际元素的个数，程序会因此崩溃。
如果元素的个数为 0 或负数，copy_n() 算法什么也不做。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事
+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    std::vector<int> from_vector(10);
    std::vector<int> to_vector;

    // iota() will increase 1 based on given range
    std::iota(from_vector.begin(), from_vector.end(), 0);

    // only copy specified items into to_vector, to back side
    std::copy_n(from_vector.begin(), 7, std::back_inserter(to_vector));

    // only copy reverse specified items into to_vector, to back side
    // Note: can NOT use front_inserter() here, as vector didn't have front inserter operation
    std::copy_n(from_vector.rbegin(), 3, std::back_inserter(to_vector));
    for_each(to_vector.begin(), to_vector.end(), [](int v) { cout << v << " ";});
    cout << endl;

    // now as we use deque, the modification operation can be from front or back, so we can use
    // front_inserter() to insert new items from front side
    std::deque<int> to_deque;
    std::copy_n(from_vector.begin(), 7, std::back_inserter(to_deque));
    std::copy_n(from_vector.rbegin(), 3, std::front_inserter(to_deque));
    for_each(to_deque.begin(), to_deque.end(), [](int v) { cout << v << " ";});
    cout << endl;

    return 0;
    // 0 1 2 3 4 5 6 9 8 7 
    // 7 8 9 0 1 2 3 4 5 6 
}
