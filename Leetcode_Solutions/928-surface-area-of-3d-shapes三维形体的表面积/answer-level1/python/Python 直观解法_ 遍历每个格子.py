对于每个格子, 如果里面有方块, 上表面积和下表面积都+1
然后判断他周围的4个位置是否有格子:
如果没有, 加上他格子的个数
如果有且比他高, 那么不加任何值
如果有且比他低, 那么加上他们数量的差值

```python
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        """
           前
        左u/d 右
           后
        """
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        res = 0
        for i in range(m):
            for j in range(n):
                # 上下两个面
                if grid[i][j]: res += 2
                # 前
                if i == 0:
                    res += grid[i][j]
                else:
                    tmp = grid[i][j] - grid[i - 1][j]
                    if tmp > 0: res += tmp
                # 后
                if i == m - 1:
                    res += grid[i][j]
                else:
                    tmp = grid[i][j] - grid[i + 1][j]
                    if tmp > 0: res += tmp
                # 左
                if j == 0:
                    res += grid[i][j]
                else:
                    tmp = grid[i][j] - grid[i][j - 1]
                    if tmp > 0: res += tmp
                # 右
                if j == n - 1:
                    res += grid[i][j]
                else:
                    tmp = grid[i][j] - grid[i][j + 1]
                    if tmp > 0: res += tmp
        return res
```