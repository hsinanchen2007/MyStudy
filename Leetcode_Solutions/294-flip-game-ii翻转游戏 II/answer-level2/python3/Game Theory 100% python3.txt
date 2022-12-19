### 解题思路
1. 计算长度为x的连续的+是否能够胜利，可以有grundy number 得出
2. 每一段+的grundy number的异或就是结果

### 代码

```python3

from functools import lru_cache

class Solution:
    def canWin(self, s: str) -> bool:

        def mex(vals):
            i = 0
            while i in vals:
                i += 1

            return i

        @lru_cache(maxsize=None)
        def dfs(x):
            if x < 2:
                return 0

            vals = set()
            for a in range(x-1):
                b = x-a-2
                vals.add(dfs(a) ^ dfs(b))

            return mex(vals)

        plus = []
        l, r = 0, 0
        while r < len(s):
            if s[r] == '-':
                d = r-l
                if d >= 2:
                    plus.append(d)
                l = r + 1
            r += 1
        d = len(s) - l
        if d >= 2:
            plus.append(d)

        v = 0
        for x in plus:
            v^= dfs(x)
            
        return v > 0
```