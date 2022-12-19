### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        stack = []
        for char in S:
            if char == '(':
                stack.append(char)
            elif char == ')' and len(stack)>0 and stack[-1]=='(':
                stack.pop()
            else:
                stack.append(char)
        return len(stack)
```