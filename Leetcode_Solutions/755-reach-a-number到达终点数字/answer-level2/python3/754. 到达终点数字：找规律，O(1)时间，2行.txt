打表找规律数学法，最难简单题之一。

```python []
class Solution:
    def reachNumber(self, target: int) -> int:
        n = math.ceil((-1 + (1 + 8 * abs(target)) ** 0.5) / 2)
        return [n, n + 1 + (n & 1)][(abs(target) - n * (n + 1) // 2) & 1]
```
