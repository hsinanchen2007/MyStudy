```
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        stack1 = []
        stack2 = []
        for ch in S:
            if ch != '#':
                stack1.append(ch)
            elif stack1:
                del stack1[-1]
        for ch in T:
            if ch != '#':
                stack2.append(ch)
            elif stack2:
                del stack2[-1]
        return stack1 == stack2
```
