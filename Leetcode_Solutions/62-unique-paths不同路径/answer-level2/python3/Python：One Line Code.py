利用排列组合的思路来做，仅需要一行return 语句）内存占用 14M 击败6%,速度32ms击败66%
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return 1 if n == 1 or m == 1 else int(reduce(lambda x, y: x * y, list(range(m, m + n - 1))) / reduce(lambda x, y: x * y, list(range(1, n))))
```