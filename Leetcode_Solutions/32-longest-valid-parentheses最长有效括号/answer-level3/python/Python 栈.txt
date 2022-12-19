### 解题思路
此处撰写解题思路
1特判，若sss为空，返回000

2初试化栈stack=[−1]stack=[-1]stack=[−1]，和结果res=0res=0res=0。栈中元素表示上一不匹配位置索引。

3遍历sss：

    若s[i]=="("s[i]=="("s[i]=="("，将当前位置索引加入stackstackstack。表示将当前左括号需要匹配，为不匹配索引。
    若s[i]==")"s[i]==")"s[i]==")"：
        出栈，stack.pop()stack.pop()stack.pop()。表示将对应左括号索引出栈，或者当栈中只有)))时，将上一)))索引出栈。
        若栈为空，表示之前的所有的(((匹配成功，上一步出栈的是栈底的−1-1−1或者是前一个不匹配的)))。则更新栈底为当前)))的索引，表示不匹配的位置。
        否则，说明和栈中的(((匹配上了，此时更新最长序列res=max(res,i−stack[−1])res=max(res,i-stack[-1])res=max(res,i−stack[−1])。表示当前位置索引减去上一不匹配位置索引 和之前resresres中的较大值。

4更新resresres



```python
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        res = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == "(":
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    res = max(res,i - stack[-1])
        return res

```