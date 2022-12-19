### 解题思路
依次遍历数组，先统计在该位置上有几个正方体，假设有n个，那么共重叠了2*(n-1)个面，然后再查看该位置的右方和下方有几个正方体，假如右方有k个，那么该位置的正方体与右方重叠了2*(min(n,k))个；下方也是如此。

### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        amount = 0
        t = 0  # t指最后需要减去的表面
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] != 0:
                    amount += grid[i][j]
                    t += grid[i][j] - 1
                    if j + 1 < len(grid):  # 右边
                        t += min(grid[i][j], grid[i][j + 1])
                    if i + 1 < len(grid):  # 下边
                        t += min(grid[i][j], grid[i + 1][j])
        return 6 * amount - 2 * t
```