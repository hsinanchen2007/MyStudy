![image.png](https://pic.leetcode-cn.com/d43ed5ddd6f79155af792e4116667f4f960356cce16d77409ccec5eb788cc85b-image.png)


```
'''
递归解析字符串
'''

from functools import lru_cache
class Solution:
    @lru_cache(typed=False)
    def solve(self, s: str):
        if s == 'f':
            return False
        elif s == 't':
            return True

        # 根据逗号拆解字符串为不同部分
        n = len(s)
        parts = []
        i = 2
        while i <= n-2:
            cnt = 0
            j = i
            while j <= n-2:
                if cnt == 0 and s[j] == ',':
                    break
                if s[j] == '(':
                    cnt += 1
                elif s[j] == ')':
                    cnt -= 1
                j += 1

            parts.append(s[i:j])
            i = j + 1

        if s[0] == '!':
            return not self.solve(parts[0])
        elif s[0] == '|':
            ans = False
            for part in parts:
                ans = ans or self.solve(part)
            return ans
        elif s[0] == '&':
            ans = True
            for part in parts:
                ans = ans and self.solve(part)
            return ans


    def parseBoolExpr(self, expression: str) -> bool:
        return self.solve(expression)
```
