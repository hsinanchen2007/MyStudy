### 执行结果
![图片.png](https://pic.leetcode-cn.com/48c85c4ec0852be07b7c89fe80fd00c92215d99923a20431ff8ab7f595b2bc31-%E5%9B%BE%E7%89%87.png)
### 嵌套列表
可以认为是python中的列表list的简化版本
元素有两种类型：
- int
- list
所以形如"[[]]","[0,[],0]"都是有效的；

### 解题思路
讲道理可以用递归吧，但是做了一下发现很混乱，还是用扫描了；
让我想到的题目就是算带括号的整数计算表达式，如3*(2+1);
类似地，我们也可以使用一个栈，来记录列表嵌套的深度，每次遇到一个'['则认为进入一层嵌套；']'则是一层嵌套的结束。


#### 至于“324“这种情况，我们直接特殊处理了;
```cpp
// a single num
if (s[0] == '-' || (s[0] >= '0' && s[0] <= '9'))
{

    for (auto ch : s)
    {
        if (ch == '-')
        {
            sign = -1;
        }
        else
        {
            value = value * 10 + ch - '0';
        }
    }
    return sign * value;
}
```

#### 普通列表，即一般情况
**字符串只包含数字0-9, [, - ,, ]**
对每个字符的处理方式
- 数字: 类似 字符串转int的方法 sum = sum * 10 + ch - '0';
- 负号: 每次将数字存入NestedInteger时，需要使用
- '[': 一个列表的开始，出现'['，则创建一个NestedInteger，然后压入stack
- ']': 当前列表的结束，需要将当前的这个[...]加入到上一层的嵌套中，即`top = stack.top(); stack.pop(); stack.top().add(top);`
- ',': 出现的情况一般是"[1,3]"或者"[[],2]",前面的数字结束了，因为列表的结束我们通过']'已经知晓，所以如果前面是列表，则不做任何操作；而如果是数字，则加入到当前的嵌套;

### 完整代码

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
NestedInteger deserialize(string s)
{
    stack<NestedInteger> stk;
    int sign = 1;
    int value = 0;
    int isValueValid = false;
    // a single num
    if (s[0] == '-' || (s[0] >= '0' && s[0] <= '9'))
    {

        for (auto ch : s)
        {
            if (ch == '-')
            {
                sign = -1;
            }
            else
            {
                value = value * 10 + ch - '0';
            }
        }
        return sign * value;
    }
    for (auto ch : s)
    {
        if ('[' == ch)
        {
            auto ni = NestedInteger();
            stk.push(ni);
        }
        else if (ch == ']')
        {
            // 先把数组存入；
            auto &top = stk.top();
            if (isValueValid)
            {
                top.add(sign * value);
                isValueValid = false;
                value = 0;
                sign = 1;
            }
            if (stk.size() == 1)
            {
                break;
            }
            else
            {
                auto topCopy = top;
                stk.pop();
                stk.top().add(topCopy);
            }
        }
        // store & reset value
        else if (ch == ',')
        {
            if (isValueValid)
            {
                auto &top = stk.top();
                top.add(sign * value);
                isValueValid = false;
                value = 0;
                sign = 1;
            }
        }
        else if (ch == '-')
        {
            sign = -1;
            isValueValid = true;
        }
        else
        {
            isValueValid = true;
            value = value * 10 + ch - '0';
        }
    }
    return stk.top();
}

};
```