### 解题思路
rt
### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        temp = []
        s = list(s)
        for i in s:
            if i == '(' or i == '[' or i == '{':
                temp.append(i)
            elif i == ')' or i == ']' or i == '}':
                if not temp:
                    return False
                left = temp.pop()
                if left == '(' and i == ')':
                    continue
                elif left == '[' and i == ']':
                    continue
                elif left == '{' and i == '}':
                    continue
                else:
                    return False
        if temp:
            return False
        else:
            return True
```