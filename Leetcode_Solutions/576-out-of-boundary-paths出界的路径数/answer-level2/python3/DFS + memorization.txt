```python
from functools import lru_cache
class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        # N < 50
        mod = 1e9 + 7
        @lru_cache(None)
        def getPathNumber(i, j, steps):
            if i < 0 or j < 0 or i >= m or j >= n: return 1
            if steps == 0 : return 0
            pathNumber = 0
            for x, y in [(i - 1, j), (i, j - 1), (i + 1, j), (i, j + 1)]:
                pathNumber += getPathNumber(x, y, steps - 1)
            return int(pathNumber % mod)
        return getPathNumber(i, j, N)
```