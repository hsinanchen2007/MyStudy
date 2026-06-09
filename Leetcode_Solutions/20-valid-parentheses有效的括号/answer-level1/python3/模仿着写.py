### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        m = {')':'(', '}':'{', ']':'['}
        stack = []
        for i in s:
            if i in m:
                top = stack.pop() if stack else '@'
                if top != m[i]:
                    return False
            else:
                stack.append(i)       
        return False if stack else True
```