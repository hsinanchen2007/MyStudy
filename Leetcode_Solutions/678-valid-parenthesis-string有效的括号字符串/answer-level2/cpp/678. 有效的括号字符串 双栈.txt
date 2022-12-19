### 解题思路
“（”必须在“”的左边
“）”必须在“”的右边

使用两个栈，left存左括号，star存“*”，存储的内容是字符在字符串中的下标。

1.遍历字符串的每一个字符
1)如果是“（”存储下标到left中；
2)如果是“*”存储下标到star中；
3)如果是“）”，先从left中获取“（”，并将栈顶元素出栈
4)如果left为空，则从star中获取“*”，将栈顶元素出栈，如果star也为空，则返回false；
2.按照1 2 3 遍历完字符串之后，遍历left，与“*”匹配；
1)如果left为空，返回true；
2)如果left不为空，遍历left，从star栈顶出栈一个“*”，如果star栈顶的下标小于left的“（”的下标，那么返回false；如果大于，则left栈顶出栈，star栈顶出栈，进行下一轮比较；
如果最后left还有值，star为空，返回false；如果left为空，star有值，返回true。

**为什么可以先弹出'(',而不管‘*’的顺序？**
**因为*可以等价‘(’,因此，即使先弹出‘(’没有问题；而且left和star需要保序**

注意点：遍历完成后，如果star和left都不为空时，则star只能替换成')',此时则必须按序匹配


### 代码

```cpp
class Solution {
public:
    bool checkValidString(string s)
    {
        deque<int> leftbuff;
        deque<int> starbuff;
        for (int i = 0; i < s.size(); i++) {
            if (leftbuff.empty() && starbuff.empty() && s[i] == ')') {
                return false;
            }

            if (!leftbuff.empty() && s[i] == ')') {
                leftbuff.pop_front();
                continue;
            }

            if (!starbuff.empty() && s[i] == ')') {
                starbuff.pop_front();
                continue;
            }

            if (s[i] == '(') {
                leftbuff.push_front(i);
            }
            if (s[i] == '*') {
                starbuff.push_front(i);
            }
        }

        while(!leftbuff.empty()){
            if(starbuff.empty() || (!starbuff.empty()&&starbuff.front()<leftbuff.front())){
                return false;
            }
            leftbuff.pop_front();
            starbuff.pop_front();
        }

        return true;
    }
};
```