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

https://en.cppreference.com/w/cpp/algorithm/replace

Replaces all elements satisfying specific criteria with new_value in the range [first, last).

1) Replaces all elements that are equal to old_value.
3) Replaces all elements for which predicate p returns true.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate in overload 
resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> (until C++20) 
std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.

Return value
(none)


replace() 算法会用新的值来替换和给定值相匹配的元素。它的前两个参数是被处理序列的正向迭代器，第 3 个参数是被替换的值，
第 4 个参数是新的值。下面展示了它的用法:

std::deque<int> data {10, -5, 12, -6, 10, 8, -7, 10, 11};
std::replace(std::begin(data), std::end(data), 10, 99);
// Result: 99 -5 12 -6 99 8 -7 99 11
这里，data 容器中和 10 匹配的全部元素都会被 99 替代。

replace_if() 会将使谓词返回 true 的元素替换为新的值。它的第 3 个参数是一个谓词，第 4 个参数是新的值。参数的类型一般是
元素类型的 const 引用；const 不是强制性的，但谓词不应该改变元素。下面是一个使用 replace_if() 的示例：

string password { "This is a good choice !"};
std::replace_if(std::begin(password), std::end(password),[](char ch){return std::isspace(ch);}, '_');
//Result:This_is_a_good_choice!
这个谓词会为任何是空格字符的元素返回 true，因此这里的空格都会被下划线代替。

replace_copy() 算法和 replace() 做的事是一样的，但它的结果会被保存到另一个序列中，而不会改变原始序列。它的前两个参数是
输入序列的正向迭代器，第 3 个参数是输入序列的开始迭代器，最后两个参数分别是要被替换的值和替换值。例如：

std::vector<string> words { "one","none", "two", "three", "none", "four"};
std::vector<string> new_words;
std::replace_copy (std::begin (words), std::end(words), std::back_inserter (new_words), string{"none"}, string{"0"});
// Result:"one", "0", "two","three","0","four"
在执行这段代码后，new_words 会包含注释中的 string 元素。

可以在序列中有选择地替换元素的最后一个算法是 replace_copy_if()，它和 replace_if() 算法是相同的，但它的结果会被保存到
另一个序列中。它的前两个参数是输入序列的迭代器，第 3 个参数是输出序列的开始迭代器，最后两个参数分别是谓词和替换值。例如：
std::deque<int> data {10, -5, 12, -6, 10, 8, -7, 10，11}; std::vector<int> data_copy;
std::replace_copy_if(std::begin(data), std::end(data),std::back_inserter(data_copy),[](int value) {return value == 10;}, 99);
// Result:99 -5 12 -6 99 8 -7 99 11

data_copy 是一个 vector 容器，这里使用它只是为了说明输出容器可以和输入容器不同。这段代码执行后，它会包含注释中所示的元素。
关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事
+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
    // replace all 8 to 88 in the given array
    std::replace(s.begin(), s.end(), 8, 88);
 
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';
 
    // similar to above, replace numbers less than 5 to 55, by std::bind(). The function template bind generates a forwarding 
    // call wrapper for f. Calling this wrapper is equivalent to invoking f with some of its arguments bound to args.
    // Parameters
    // f	-	Callable object (function object, pointer to function, reference to function, pointer to member function, or 
    //          pointer to data member) that will be bound to some arguments
    // args	-	list of arguments to bind, with the unbound arguments replaced by the placeholders _1, _2, _3... of namespace 
    //          std::placeholders
    std::replace_if(s.begin(), s.end(), 
                    std::bind(std::less<int>(), std::placeholders::_1, 5), 55);
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';

    // remove space by checking isspace(char) with "_" char
    string password { "This is a good choice !"};
    std::replace_if(std::begin(password), std::end(password),[](char ch){return std::isspace(ch);}, '_');
    cout << password << endl;

    return 0;
    // 5 7 4 2 88 6 1 9 0 3 
    // 5 7 55 55 88 6 55 9 55 55 
    // This_is_a_good_choice_!
}

