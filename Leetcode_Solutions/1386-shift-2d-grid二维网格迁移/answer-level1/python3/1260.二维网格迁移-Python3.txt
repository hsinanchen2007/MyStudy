### 解题思路
将二维数组转化为一维数组，向右移动 k%一维数组长度 个单位，最后将新的一维数组变成二维数组
### 代码

```python3
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        Grid = [i for j in grid for i in j]
        r = len(Grid)
        k = k % r
        Grid = Grid[r-k:] + Grid[:r-k]
        for m in range(len(grid)):
            for n in range(len(grid[0])):
                grid[m][n] = Grid[len(grid[0])*m+n]
        return grid
```