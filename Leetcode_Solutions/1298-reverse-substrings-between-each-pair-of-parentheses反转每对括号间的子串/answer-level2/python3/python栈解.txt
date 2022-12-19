时间击败75，空间击败100.

```
class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = ''
        i = 0
        while (i < len(s)):
            if s[i] == ')':
                j = -1
                while (stack[j] != '('):
                    j -= 1
                if j != -1:
                    stack = stack[:j] + stack[j+1:][::-1]
                else:
                    stack = stack[:-1]
                i += 1
            else:
                stack += s[i]
                i += 1
        return stack
```

