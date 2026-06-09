```python
from functools import lru_cache
class Solution:
    @lru_cache(None)
    def minSteps(self, n: int) -> int:
        if n == 1: return 0
        res = n
        for j in range(2, n + 1):
            if n % j == 0 and j != n:
                res = min(res, self.minSteps(j) + (n // j))
        return res
```