### 理解题意
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;本题要求设计出一个迭代器，这个迭代器的作用为遍历列表中所有嵌套列表进而遍历列表中所有整数。以`[[1,1],2,[1,1]]`为例，手动过一遍流程：
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;1.遍历到第一个元素，发现为嵌套的列表`[1,1]`(在这停顿！)，进入这个嵌套列表中；
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;2.列表中，遍历第一个元素为一个整数`1`，显然需要输出这个整数；
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;3.继续遍历这个嵌套的列表,遍历第二个元素为一个整数`2`，显然需要输出这个整数；
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;4.这个嵌套列表遍历完成，回到最开始的列表`[[1,1],2,[1,1]]`，此时继续遍历该列表的第二个元素`2`；
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;以此类推......
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;由上述过程可以很容易的发现这是一个递归的过程，由于递归和栈之间的紧密联系，我们可以很自然联想到这个是一个类似深度优先搜索的过程。实际上本题就是让我们借助栈的特点设计出深度优先搜索过程。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;接下来就是了解题目预先给的这三坨东西的作用。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;首先，第一个为预设的列表类`NestedInteger`(nested就是嵌套的意思)，下面三个方法都有英文解释。简单来说，`isInteger()`判断是否为单个整数元素；`getInteger()`获取单个整数元素；`getList()`获取嵌套列表。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;其次，要想更容易地理解`NestedIterator`的作用，就要先知道第三坨是干什么的。其实，第三坨就是告诉我们在测试中如何调用我们写的`NestedIterator`。即，实例化`NestedIterator`，利用`hasNext()`循环遍历对象，通过`next()`输出整数元素，这也照应了题目中的`通过重复调用 next 直到 hasNext 返回 false`。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;最后，来到我们要写的类`NestedIterator`。显然第一个方法为类的构造函数，我们要在这里有一些初始化的动作。第二个`next()`方法，由第三坨的流程我们大致可以知道它起码有两个动作：一个是利用`getInteger()`输出整数元素；另一个是推动循环进行下去，也就是平时我们用的`i++`，不过这里用到栈，所以这个动作可以替换成出栈`pop()`。第三个`hasNext()`方法当然就是实现深度搜索的核心步骤，根据第三坨的意思，当它遍历列表时，遇到整数就返回true以输出单个整数，直到因为某种原因返回false结束整个循环过程。

### 解题思路
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;进入正题。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;首先，我们的目的就是利用栈来实现深度搜索，也可以说是利用栈来模拟递归过程。这时，我们就是回到刚才手动过一遍的流程中去，我们发现：如果为递归的过程，那么这就是一个正向的、等待的、输出的过程(需要好好理解理解，最好动手画流程。其实就是人的思维过程)。这里需要我们有一种逆向思维，因为栈的特点是先进后出，所以要想模拟这个递归流程，那么势必需要我们逆向将列表中元素压入栈中，这样我们访问栈顶元素即可。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;其次，在`hasNext()`方法中，我们要获取栈顶元素，如果栈顶元素是单个整数元素，那么返回true；如果依然为嵌套列表，那么出栈的同时将出栈的嵌套列表中的各个元素继续逆向压入栈中。如此循环，知道栈中为空，返回false。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;最后，对于`next()`方法，当然是获取出栈元素，然后在出栈的同时返回要输出的单个整数元素。

### 代码

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> stack_NIger;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++)        //反向迭代器，逆序进栈
            stack_NIger.push(*iter);
    }

    int next() {
        auto p = stack_NIger.top();
        stack_NIger.pop();
        return p.getInteger();
    }

    bool hasNext() {
        while(!stack_NIger.empty()){
            auto p = stack_NIger.top();
            if(p.isInteger())
                return true;
            stack_NIger.pop();

            vector<NestedInteger> nested_List = p.getList();
            for(auto iter = nested_List.rbegin(); iter != nested_List.rend(); iter++)  //反向迭代器，逆序进栈
                stack_NIger.push(*iter);
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```
<br/>
>如果有错误或者不严谨的地方，请务必给予指正，十分感谢。
>本人blog：<https://zhengguanyu.github.io>