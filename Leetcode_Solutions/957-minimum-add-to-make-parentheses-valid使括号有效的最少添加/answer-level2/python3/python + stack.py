```python
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        # Time complexity: O(N)
        # Space complexity: O(N)
        stack = []
        for ch in S:
            if ch == ')':
                if stack and stack[-1] == '(':
                    stack.pop()
                else: stack.append(ch)
            else: stack.append(ch)
        return len(stack)
```