```python
class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        # double x = x * 2
        # decrement: x = x - 1
        return 1 + self.brokenCalc(X, (Y + 1)// 2) + int(Y % 2 == 1) if X < Y else X - Y
```