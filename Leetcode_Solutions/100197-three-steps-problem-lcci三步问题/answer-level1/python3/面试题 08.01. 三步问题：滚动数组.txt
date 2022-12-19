

```python []
class Solution:
    def waysToStep(self, n: int) -> int:
        a = [1, 1, 2]
        for i in range(3, n + 1):
            a[i % 3] = sum(a) % 1000000007
        return a[n % 3]
```