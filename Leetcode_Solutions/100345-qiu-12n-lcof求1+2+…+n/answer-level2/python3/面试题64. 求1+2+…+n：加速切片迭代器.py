
```python []
class Solution:
    def sumNums(self, n: int) -> int:
        return next(itertools.islice(itertools.accumulate(range(1, n + 1)), n - 1, n))
```