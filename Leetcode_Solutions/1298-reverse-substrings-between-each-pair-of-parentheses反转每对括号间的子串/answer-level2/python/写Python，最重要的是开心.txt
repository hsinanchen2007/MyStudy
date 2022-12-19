使用栈记录括号的索引位置，左括号位置入栈，右括号带着栈顶出栈，同时记录这个翻转区间
根据区间，翻转索引之间的内容即可

```python
class Solution:
    def reverseParentheses(self, s: str) -> str:
        intervals = []
        stack = []
        for i,c in enumerate(s):
            if c == "(":
                stack.append(i)
            elif c == ")":
                left = stack.pop() + 1
                right = i
                intervals.append([left, right])
        s = list(s)
        for interval in intervals:
            s[interval[0]:interval[1]] = s[interval[0]:interval[1]][::-1]
        s = filter(lambda x: x != "(" and x !=")", s)
        return "".join(s)
```