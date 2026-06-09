### 解题思路
引入字典，存储左右括号对应关系。用右括号做键的好处是方便与stack中弹出的左括号作比较

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        c = {')':'(',']':'[','}':'{'}
        for ch in s:
            if ch not in c:
                stack.append(ch)
            elif not stack or c[ch] != stack.pop():
                return False
        return not stack
```