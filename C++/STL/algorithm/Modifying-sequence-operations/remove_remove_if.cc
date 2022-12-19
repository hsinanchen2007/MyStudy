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
#include <cctype>
#include <iomanip>
#include <iostream>

using namespace std;

/*

https://en.cppreference.com/w/cpp/algorithm/remove

Removes all elements satisfying specific criteria from the range [first, last) and returns 
a past-the-end iterator for the new end of the range.

1) Removes all elements that are equal to value, using operator== to compare them.
3) Removes all elements for which predicate p returns true.
2,4) Same as (1,3), but executed according to policy. These overloads do not participate 

in overload resolution unless std::is_execution_policy_v<std::decay_t<ExecutionPolicy>> 
(until C++20) std::is_execution_policy_v<std::remove_cvref_t<ExecutionPolicy>> (since C++20) is true.
Removing is done by shifting (by means of copy assignment (until C++11)move assignment 
(since C++11)) the elements in the range in such a way that the elements that are not to be 
removed appear in the beginning of the range. Relative order of the elements that remain is 
preserved and the physical size of the container is unchanged. Iterators pointing to an 
element between the new logical end and the physical end of the range are still dereferenceable, 
but the elements themselves have unspecified values (as per MoveAssignable post-condition).

Return value
Past-the-end iterator for the new range of values (if this is not end, then it points to an 
unspecified value, and so do iterators to any values between this iterator and end).


如果不知道具体的场景，即元素保存在什么样的容器中，是不能从序列中移除元素的。因此，“移除元素的”算法也无法做到这一点，
它们只会重写被选择的元素或者忽略复制的元素。移除操作不会改变被“移除”元素的序列的元素个数。

有 4 种移除算法：
remove() 可以从它的前两个正向迭代器参数指定的序列中移除和第三个参数相等的对象。基本上每个元素都是通过用它后面的元素
覆盖它来实现移除的。它会返回一个指向新的最后一个元素之后的位置的迭代器。

remove_copy() 可以将前两个正向迭代器参数指定的序列中的元素复制到第三个参数指定的目的序列中，并忽略和第 4 个参数相等
的元素。它返回一个指向最后一个被复制到目的序列的元素的后一个位置的迭代器。序列不能是重叠的。

remove_if() 可以从前两个正向迭代器指定的序列中移除能够使作为第三个参数的谓词返回 true 的元素。

remove_copy_if() 可以将前两个正向迭代器参数指定的序列中，能够使作为第 4 个参数的谓词返回 true 的元素，复制到第三个
参数指定的目的序列中。它返回一个指向最后一个被复制到目的序列的元素的后一个位置的迭代器。序列不能是重叠的。

可以按如下方式使用 remove():
std::deque<double> samples {1.5, 2.6, 0.0, 3.1, 0.0, 0.0, 4.1, 0.0, 6.7, 0.0};
samples.erase(std::remove(std::begin(samples), std::end(samples), 0.0), std::end(samples));
std::copy(std::begin(samples),std::end(samples), std::ostream iterator <double> {std::cout," "});
std::cout << std::endl;
// 1.5 2.6 3.1 4.1 6.7
sample 中不应包含为 0 的物理测量值。remove() 算法会通过左移其他元素来覆盖它们，通过这种方式就可以消除杂乱分布的 0。
remove() 返回的迭代器指向通过这个操作得到的新序列的尾部，所以可以用它作为被删除序列的开始迭代器来调用 samples 的成员函数 
erase()。注释说明容器中的元素没有被改变。

如果想保留原始序列，并生成一个移除选定元素之后的副本，可以使用 remove_copy()。 例如：
std::deque<double> samples {1.5, 2.6, 0.0, 3.1, 0.0, 0.0, 4.1, 0.0, 6.7, 0.0}; std::vector<double> 
edited_samples;

std::remove_copy(std::begin(samples), std::end(samples), std::back_inserter(edited_samples), 0.0);
samples 容器中的非零元素会被复制到 edited_samples 容器中，edited_samples 正好是一个 vector 容器。通过 
back_insert_iterator 对象将这些元素添加到 edited_samples，因此这个容器只包含从 sample 中复制的元素。

remove_if() 提供了更强大的能力，它能够从序列中移除和给定值匹配的元素。谓词会决定一个元素是否被移除；它接受序列中的一个
元素为参数，并返回一个布尔值。例如：

using Name = std::pair<string, string>； // First and second name
std::set<Name> blacklist {Name {"Al", "Bedo"}, Name {"Ann", "Ounce"}, Name {"Jo","King"}};
std::deque<Name> candidates {Name{"Stan", "Down"}, Name {"Al", "Bedo"}, Name {"Dan", "Druff"},Name 
{"Di", "Gress"}, Name {"Ann", "Ounce"}, Name {"Bea", "Gone"}}; candidates.erase(std::remove_if(std::begin(candidates), 
std::end(candidates),[&blacklist](const Name& name) { return blacklist.count(name); }), std::end(candidates)); 
std::for_each(std::begin(candidates), std::end(candidates), [] (const Name& name){std::cout << '"' 
<< name.first << " " << name.second << "\" ";});
std::cout << std::endl;  // "Stan Down" "Dan Druff" "Di Gress" "Bea Gone"

这段代码用来模拟候选人申请成为倶乐部会员。那些众所周知的不安分人士的姓名被保存在 blacklist 中，它是一个集合。当前申请成为会员
的候选人被保存在 candidates 容器中，它是一个 deque 容器。用 remove_if() 算法来保证不会有 blacklist 中的姓名通过甄选过程。
这里的谓词是一个以引用的方式捕获 blacklist 容器的 lambda 表达式。当参数在容器中存在时，set 容器的成员函数 count() 会返回 1。
谓词返回的值会被隐式转换为布尔值，因此对于每一个出现在 blacklist 中的候选人，谓词都会返回 true，然后会将它们从 candidates 
中移除。注释中显示了通过甄选的候选人。

remove_copy_if() 之于 remove_copy()，就像 remove_if() 之于 remove。下面展示它是如何工作的：
std::set<Name> blacklist {Name {"Al", "Bedo"}, Name {"Ann", "Ounce"}, Name {"Jo", ,"King" } };
std::deque<Name> candidates {Name {"Stan", "Down"}, Name { "Al", "Bedo"},Name {"Dan", "Druff"}, Name 
{"Di", "Gress"}, Name {"Ann", "Ounce"},Name {"Bea", "Gone"}};
std::deque<Name> validated;
std::remove_copy_if(std::begin(candidates) , std::end(candidates), std::back inserter(validated), 
[&blacklist] (const Name& name) { return blacklist.count(name); });

这段代码实现了和前一段代码同样的功能，除了结果被保存在 validated 容器中和没有修改 candidates 容器之外。
关注公众号「站长严长生」，在手机上阅读所有教程，随时随地都能学习。本公众号由站长亲自运营，长期更新，坚持原创，专注于分享创业故事
+学习历程+工作记录+生活日常+编程资料。

*/

int main()
{
    vector<int> myV1 = {1, 2, 3, 2, 3, 2, 3, 2, 4, 5, 9, 8, 7, 6, 2, 1, 10, 10};

    // the ret from std::remove() is the last iterator, so in for_each(), we treat this red as new end of myV1
    auto ret = remove(myV1.begin(), myV1.end(), 2);
    for_each(myV1.begin(), ret, [](int v) { cout << v << endl; });
    cout << "Size of myV1 is " << myV1.size() << endl;

    // same content, if we really want to remove the elements of target, add erase() of original vector at the beginning
    vector<int> myV2 = {1, 2, 3, 2, 3, 2, 3, 2, 4, 5, 9, 8, 7, 6, 2, 1, 10, 10};
    myV2.erase(remove(myV2.begin(), myV2.end(), 2), myV2.end());
    for_each(myV2.begin(), myV2.end(), [](int v) { cout << v << endl; });
    cout << "Size of myV2 is " << myV2.size() << endl;

    // remove_if() based on given condition, if condition is true, perform the task to remove it
    vector<int> myV3 = {1, 2, 3, 2, 3, 2, 3, 2, 4, 5, 9, 8, 7, 6, 2, 1, 10, 10};
    myV3.erase(remove_if(myV3.begin(), myV3.end(), [](int v){ return ((v % 2 != 0) ? true : false); }), myV3.end());
    for_each(myV3.begin(), myV3.end(), [](int v) { cout << v << endl; });
    cout << "Size of myV3 is " << myV3.size() << endl;

    return 0;
    // 1
    // 3
    // 3
    // 3
    // 4
    // 5
    // 9
    // 8
    // 7
    // 6
    // 1
    // 10
    // 10
    // Size of myV1 is 18
    // 1
    // 3
    // 3
    // 3
    // 4
    // 5
    // 9
    // 8
    // 7
    // 6
    // 1
    // 10
    // 10
    // Size of myV2 is 13
    // 2
    // 2
    // 2
    // 2
    // 4
    // 8
    // 6
    // 2
    // 10
    // 10
    // Size of myV3 is 10
}
