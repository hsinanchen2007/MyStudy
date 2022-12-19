```Python
class Solution:
    def removeInvalidParentheses(self, s):
        def isvalid(string):  # 判断括号串是否合法
            l_minus_r = 0
            for c in string:
                if c == '(':
                    l_minus_r += 1
                elif c == ')':
                    l_minus_r -= 1
                    if l_minus_r < 0:
                        return False
            return l_minus_r == 0

        level = {s}
        while True:  # BFS
            valid = list(filter(isvalid, level))
            if valid:
                return valid
            level = {s[:i] + s[i + 1:] for s in level for i in range(len(s)) if s[i] in '()'}
```
