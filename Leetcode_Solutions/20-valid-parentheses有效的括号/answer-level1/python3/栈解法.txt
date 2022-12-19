
```python3
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        something = {'}': '{', ']': '[', ')': '('}
        for c in s:
            if c not in something:
                stack.append(c)
            elif not stack or something[c] != stack.pop():
                return False
        return not stack
```
![WX20191218-121158.png](https://pic.leetcode-cn.com/c9f84b77986b01d893d255865e21486636626c9cb1be9e526ed69ac33177011f-WX20191218-121158.png)
