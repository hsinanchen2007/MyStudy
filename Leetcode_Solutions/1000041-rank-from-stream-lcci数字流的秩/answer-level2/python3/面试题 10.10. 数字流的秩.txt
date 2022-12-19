### 解题思路

二分插排

### 代码

```python []
class StreamRank:

    def __init__(self):
        self.arr = []

    def track(self, x: int) -> None:
        bisect.insort(self.arr, x)

    def getRankOfNumber(self, x: int) -> int:
        return bisect.bisect(self.arr, x)
```