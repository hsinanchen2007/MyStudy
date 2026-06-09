```python []
class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        from functools import lru_cache
        @lru_cache(None)
        def D(n):
            if n < 0:
                return (0, 0, 0, 0, 0, 0)
            if n == 0:
                return (0, 0, 0, 0, 0, 0, 1)
            S = sum(D(n - 1))
            return tuple(S - sum(D(n - 1 - rollMax[r])) + D(n - 1 - rollMax[r])[r] for r in range(6))
        return sum(D(n)) % 1000000007
```
