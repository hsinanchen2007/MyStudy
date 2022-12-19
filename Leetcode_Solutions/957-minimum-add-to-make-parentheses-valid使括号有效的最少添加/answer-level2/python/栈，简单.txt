### 解题思路
逐个判断，如果当前字符是右括号且栈中有左括号（s > stack[-1]）则组成一对儿，弹出。否则入栈。

最后看栈长度。

### 代码

```python3
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        stack = []
        
        for s in S:
            if stack and s > stack[-1]:
                stack.pop()
            else:
                stack.append(s)

        return len(stack)



```