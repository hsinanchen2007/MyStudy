7行代码:
```
from functools import lru_cache
class Solution:
    @lru_cache(None)
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        if i < 0 or i >= m or j < 0 or j >= n: return 1
        if not N: return 0
        return sum(self.findPaths(m, n, N - 1, i + dx, j + dy) for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0))) % (10 ** 9 + 7)
```

上面的7行代码由下面正常一些的代码修改而来:
```
from functools import lru_cache
class Solution:
    @lru_cache(None)
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        if i < 0 or i >= m or j < 0 or j >= n:
            return 1
        if not N:
            return 0
        MOD = 10 ** 9 + 7
        cnt = 0
        for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
            cnt += self.findPaths(m, n, N - 1, i + dx, j + dy)
        return cnt % MOD
```
