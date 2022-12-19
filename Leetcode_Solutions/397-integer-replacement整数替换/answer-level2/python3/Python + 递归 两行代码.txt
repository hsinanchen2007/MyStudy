```python
class Solution:
    def integerReplacement(self, n: int) -> int:
        if n == 1: return 0
        return min(self.integerReplacement(n + 1), self.integerReplacement(n - 1)) + 1 if n & 1 else self.integerReplacement(n // 2) + 1
```