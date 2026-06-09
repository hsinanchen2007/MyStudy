### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeDuplicates(self, S: str) -> str:
        stack = []
        for item in S:

            if stack and item == stack[-1]:
                stack.pop()

            else:
                stack.append(item)
        
        return ''.join(stack)
```