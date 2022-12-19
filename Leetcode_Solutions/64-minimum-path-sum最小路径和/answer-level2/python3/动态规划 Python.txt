### 分析
就利用输入数组`grid[i][k]`存储到达该位置最小数字和
对第一行，都只能沿向右的路径到达，所以`grid[0][j] = grid[0][j-1] + grid[0][j]`  
对第一列，都只能沿向下的路径到达，所以`grid[i][0] = grid[i-1][0] + grid[i][0]`  
对其余部分，到达当前位置最小和为当前位置数字+左侧和上侧的较小值：
`grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]`  

### 代码
```
class Solution:
    def minPathSum(self, grid):
        if not grid:
            return 0
        m = len(grid)
        n = len(grid[0])
        for j in range(1, n):
            grid[0][j] = grid[0][j] + grid[0][j-1]
        for i in range(1, m):
            grid[i][0] = grid[i][0] + grid[i-1][0]
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1])
        return grid[m-1][n-1]
```
