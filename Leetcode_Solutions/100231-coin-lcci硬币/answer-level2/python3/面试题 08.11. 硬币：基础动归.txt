
```python []
class Solution:
    def waysToChange(self, n: int) -> int:
        d = [1] + [0] * n
        for c in (1, 5, 10, 25):
            for i in range(n - c + 1):
                d[i + c] += d[i]
        return d[n] % 1000000007
```