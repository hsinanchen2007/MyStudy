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

https://en.cppreference.com/w/cpp/algorithm/fill

1) Assigns the given value to the elements in the range [first, last).
2) Same as (1), but executed according to policy. This overload does not participate in overload resolution 
unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

https://en.cppreference.com/w/cpp/algorithm/fill_n

1) Assigns the given value to the first count elements in the range beginning at first if count > 0. Does 
nothing otherwise.
2) Same as (1), but executed according to policy. This overload does not participate in overload resolution 
unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.


fill() 和 fill_n() 算法提供了一种为元素序列填入给定值的简单方式，fill() 会填充整个序列； fill_n() 则以给定的迭代器为起始位置，
为指定个数的元素设置值。下面展示了 fill() 的用法：

std::vector<string> data {12}; // Container has 12 elements
std::fill (std::begin (data), std::end (data), "none"); // Set all elements to "none"

fill 的前两个参数是定义序列的正向迭代器，第三个参数是赋给每个元素的值。当然这个序列并不一定要代表容器的全部元素。例如：

std::deque<int> values (13); //Container has 13 elements
int n{2};   // Initial element value
const int step {7}; // Element value increment
const size_t count{3};  // Number of elements with given value
auto iter = std::begin(values);
while(true)
{
    auto t0_end = std::distance(iter, std::end(values)); // Number of elements remaining
    if (to_end < count) //In case no. of elements not a multiple of count
    {
        std:: fill (iter, iter + to_end, n); // Just fill remaining elements and end the loop
        break;
    }
    else
    {
        std:: fill (iter, std:: end (values), n); // Fill next count elements
    }
    iter = std::next(iter, count); // Increment iter
    n += step;
}

上面创建了具有 13 个元素的 value 容器。在这种情况下，必须用圆括号将值传给构造函数；使用花括号会生成一个有单个元素的容器，单个元素的值为 13。
在循环中，fill() 算法会将 values 赋值给 count 个元素。以 iter 作为容器的开始迭代器，如果还有足够的元素剩下，每次遍历中，它会被加上 count，
因此它会指向下个序列的第一个元素。执行这段代码会将 values 中的元素设置为：
2 2 2 9 9 9 16 16 16 23 23 23 30

fill_n() 的参数分别是指向被修改序列的第一个元素的正向迭代器、被修改元素的个数以及要被设置的值。distance() 和 next() 函数定义在 iterator 
头文件中。前者必须使用输入迭代器，而后者需要使用正向迭代器。

关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事+学习历程+
工作记录+生活日常+编程资料。

*/

int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // fill -1 into all v vector
    std::fill(v.begin(), v.end(), -1); 

    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // fill 99 to first 5 elements into v vector
    std::fill_n(v.begin(), 5 /* size*/, 99 /* value */); 

    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // 2022.8.20
    // Note that 2nd parameter is size, and 3rd parameter is value to fill in fill_n() call

    return 0;
    // -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
    // 99 99 99 99 99 -1 -1 -1 -1 -1 
}
