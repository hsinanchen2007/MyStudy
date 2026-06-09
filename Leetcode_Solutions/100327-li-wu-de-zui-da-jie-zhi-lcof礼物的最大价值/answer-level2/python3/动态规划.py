对于左侧一列，每个位置的最大值来自上一行的最大值+自身的值
对于上面一行，每个位置的最大值来自上一列的最大值+自身的值
其他位置的最大值来自左侧和上面中的最大值+自身的值

```
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0 and j == 0:
                    continue
                if i == 0:
                    grid[i][j] = grid[i][j-1] + grid[i][j]
                if j == 0:
                    grid[i][j] = grid[i-1][j] + grid[i][j]
                if i!=0 and j!=0:
                    grid[i][j] = max(grid[i][j-1], grid[i-1][j])+grid[i][j]
        return grid[-1][-1]

```
