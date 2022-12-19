```
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        s = list(s)
        if len(s) <= 1:
            return 0
        stack = []
        count = -1
        while s:
            if not stack:
                stack.append(s.pop(0))
                count += 1
            if stack[-1] != s[0]:
                stack.pop()
                s.pop(0)
            else:
                stack.append(s.pop(0))
        if not stack:
            count += 1
        return count
```
