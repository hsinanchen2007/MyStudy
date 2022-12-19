![image.png](https://pic.leetcode-cn.com/661ea4f75b9dde0ef04f8b93e4f06b5ea48a93b06712ef17461222ceaa2da01c-image.png)

遍历矩阵，遍历方向，如果碰到大于自己的邻元素就深搜扩展。

使用lru_cache装饰器可以略去额外的记忆化内存管理。

```python []
from functools import lru_cache
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0
        r, c, d = len(matrix), len(matrix[0]), ((0, 1), (0, -1), (1, 0), (-1, 0))
        @lru_cache(None)
        def f(i, j):
            t = 0
            for di, dj in d:
                x, y = i + di, j + dj
                if 0 <= x < r and 0 <= y < c and matrix[x][y] > matrix[i][j]:
                    t = max(t, f(x, y))
            return t + 1
        return max(f(i, j) for i, j in itertools.product(range(r), range(c)))
```
