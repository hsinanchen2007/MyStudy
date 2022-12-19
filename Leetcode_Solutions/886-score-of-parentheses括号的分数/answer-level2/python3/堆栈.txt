```
class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        stack = []
        res = 0
        for i in S:
            if i=="(":
                stack.append(res)
                res = 0
            elif i==")":
                p = stack.pop()
                res = p + 1 if res == 0 else p + 2 * res
            else:
                res += int(i)
        return res
```
