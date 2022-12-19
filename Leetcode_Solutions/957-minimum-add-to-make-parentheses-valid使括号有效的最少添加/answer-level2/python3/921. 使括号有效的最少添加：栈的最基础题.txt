增删栈（列表）不如算坐标快，也不如replace()快，但是算是理解栈的一个基础题了，栈的解法是必须会的。

```py
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        stack = []
        for c in S:
            if stack and stack[-1] == '(' and c == ')':
                stack.pop()
            else:
                stack.append(c)
        return len(stack)
```
