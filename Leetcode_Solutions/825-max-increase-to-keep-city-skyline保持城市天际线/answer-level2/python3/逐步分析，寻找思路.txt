### 解题思路
 1. 首先理解题意：城市天际线指的是每一排、每一列楼的最高层高度，即二维数组每一列、每一行的最大值；
 2. 接着，将每一行、列最大值储存在2个的数组中；
 3. 坐标`(i, j)`的楼房最大高度是其所在行、列最高楼房高度中较小的值，即`min([SkyLineRow[i],skyLineRow[j]])`;
 4. 最后，作差求和。

### 代码

```python3
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        SkyLineRow = [max([grid[i][j] for j in range(n)]) for i in range(n)]
        skyLineCol = [max([grid[i][j] for i in range(n)]) for j in range(n)]
        return sum([min([SkyLineRow[i],skyLineCol[j]]) - grid[i][j] for i in range(n) for j in range(n)])
```