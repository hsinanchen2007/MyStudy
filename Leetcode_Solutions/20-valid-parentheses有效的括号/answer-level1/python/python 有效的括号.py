```python []
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')': '(', '}': '{', ']': '['}
        for i in s:
            if i in mapping.values():
                stack.append(i)
            elif mapping[i] in stack and mapping[i] == stack[-1]:
                stack.pop()
            else:
                return False
        return not stack
```


