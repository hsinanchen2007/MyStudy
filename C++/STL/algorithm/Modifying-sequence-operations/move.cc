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

https://en.cppreference.com/w/cpp/algorithm/move

1) Moves the elements in the range [first, last), to another range beginning at d_first, starting from 
first and proceeding to last - 1. After this operation the elements in the moved-from range will still 
contain valid values of the appropriate type, but not necessarily the same values as before the move.
2) Same as (1), but executed according to policy. This overload does not participate in overload resolution 
unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.


move() 算法会将它的前两个输入迭代器参数指定的序列移到第三个参数定义的目的序列的开始位置，第三个参数必须是输出迭代器。
这个算法返回的迭代器指向最后一个被移动到目的序列的元素的下一个位置。

这是一个移动操作，因此无法保证在进行这个操作之后，输入序列仍然保持不变；源元素仍然会存在，但它们的值可能不再相同了，
因此在移动之后，就不应该再使用它们。如果源序列可以被替换或破坏，就可以选择使用 move() 算法。如果不想扰乱源序列，可以使用 copy() 
算法。下面是一个展示如何使用它的示例：

std::vector<int> srce {1, 2, 3, 4};
std::deque<int> dest {5, 6, 7, 8};
std::move(std::begin(srce), std::end(srce), std::back_inserter(dest));

这里会将 data 的最后 6 个元素移到容器的开头。它能够正常工作是因为目的地址在源序列之外。在移动之后，无法保证最后两个元素的值。
这里它们虽然被移除了，但同样可以将它们重置为已知的值一一例如 0。

最后一行中的注释展示了输出结果。当然也可以用 rotate() 算法来代替 move() 移动元素，在这种情况下，我们肯定知道最后两个元素的值。

如果一个移动操作的目的地址位于源序列之内，move() 就无法正常工作，这意味着移动需要从序列的右边开始。原因是一些元素在移动之前会被重写，
但 move_backward() 可以正常工作。它的前两个参数指定了被移动的序列，第三个参数是目的地址的结束迭代器。例如：

std::vector<int> data {1, 2, 3, 4, 5, 6, 7, 8};
std::move(std::begin(data) + 2, std::end(data), std::begin(data));
data.erase(std::end(data) - 2, std::end(data)); // Erase moved elements
std::copy(std::begin (data), std::end(data), std::ostream_iterator<int> {std::cout, " "});
std::cout << std::endl;
// 3, 4, 5, 6, 7, 8

这里使用 deque 容器只是为了换个容器使用。将前 6 个元素向右移动两个位置。在移动操作后，值无法得到保证的元素会被重置为 0。最后一行
展示了这个操作的结果。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+
学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    std::vector<int> srce {1, 2, 3, 4};
    std::deque<int> dest {5, 6, 7, 8};

    cout << "source before move contains: " << endl;
    for_each(srce.begin(), srce.end(), [](int v){ cout << v << " "; });
    cout << endl;

    cout << "target before move contains: " << endl;
    for_each(dest.begin(), dest.end(), [](int v){ cout << v << " "; });
    cout << endl;

    // perform move tastk, from source to target
    // Note that based on C++ reference, the source may or may not contain same values after move, 
    // "After this operation the elements in the moved-from range will still contain valid values of the 
    // appropriate type, but not necessarily the same values as before the move."
    // 如果源序列可以被替换或破坏，就可以选择使用 move() 算法。如果不想扰乱源序列，可以使用 copy() 算法。
    cout << "move elements from source to target ......" << endl;
    std::move(srce.begin(), srce.end(), dest.begin());

    cout << "source after move contains: " << endl;
    for_each(srce.begin(), srce.end(), [](int v){ cout << v << " "; });
    cout << endl;

    cout << "target after move contains: " << endl;
    for_each(dest.begin(), dest.end(), [](int v){ cout << v << " "; });
    cout << endl;

    // clean up source
    srce.clear();
    for (int i = 0; i < 10; i++) {
        srce.push_back(i);
    }
    // resize target
    dest.resize(20);
    cout << "move new elements again from source to target ......" << endl;
    // specify the starting index location, where the index starts from 0 so this 4 index location is 5th
    std::move(srce.begin(), srce.end(), dest.begin() + 4);

    cout << "source after move contains: " << endl;
    for_each(srce.begin(), srce.end(), [](int v){ cout << v << " "; });
    cout << endl;

    cout << "target after move contains: " << endl;
    for_each(dest.begin(), dest.end(), [](int v){ cout << v << " "; });
    cout << endl;

    return 0;
    // source before move contains: 
    // 1 2 3 4 
    // target before move contains: 
    // 5 6 7 8 
    // move elements from source to target ......
    // source after move contains: 
    // 1 2 3 4 
    // target after move contains: 
    // 1 2 3 4 
    // move new elements again from source to target ......
    // source after move contains: 
    // 0 1 2 3 4 5 6 7 8 9 
    // target after move contains: 
    //1 2 3 4 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 
}
