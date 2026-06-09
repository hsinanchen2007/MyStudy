### 解题思路
先不管其他位置，按照grid[i][j]*4 + 2计算当前位置面积和（注意grid[i][j]为0时面积为0）。
接下来判断该位置左边和上边是否有立方体，如果有就减去重合部分，注意0行0列的处理

### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                res += grid[i][j]*4 + 2 if grid[i][j] > 0 else 0
                # 第0行
                if i == 0 and j != 0:
                    res -= 2*min(grid[i][j-1], grid[i][j])
                # 第0列
                if j == 0 and i != 0:
                    res -= 2*min(grid[i-1][j], grid[i][j])
                # 其他行列
                if i !=0 and j != 0:
                    res = res - 2*min(grid[i][j-1], grid[i][j]) - 2*min(grid[i-1][j], grid[i][j])
        return res
```