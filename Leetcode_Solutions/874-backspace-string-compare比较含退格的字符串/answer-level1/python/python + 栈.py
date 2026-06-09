### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        stack_s = []
        for i in S:
            if i == "#":
                if stack_s:
                    stack_s.pop()
            else:
                stack_s.append(i)
        stack_t = []
        for i in T:
            if i == "#":
                if stack_t:
                    stack_t.pop()
            else:
                stack_t.append(i)
        return stack_s==stack_t
```