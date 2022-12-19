### 解题思路
使用dfs进行搜索。

遍历grid，i表示行index，j表示列index，当grid[i][j] == 1时， 对（i，j）进行一次dfs搜索：
1. 当grid[i][j] == 1 时，当前面积 + 1
2. 同时将grid[i][j] 设为0，避免重复访问
3. 对(i,j)上下左右的位置进行dfs搜索
4. 返回的边界条件为：i,j越界，或当前访问位置为0

比较本次搜索得到的面积和之前的最大面积， 如果本次搜索的面积更大， 则更新最大面积的值

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid or len(grid)<1 or len(grid[0])<1:
            return 0
        m = len(grid)
        n = len(grid[0])
        max_area = 0
        for i in range(m):
            for j in range(n):
                self.area = 0
                if grid[i][j] == 1:
                    self.dfs(grid, i, j, m, n)
                max_area = max(max_area, self.area)
        return max_area


    def dfs(self, grid, i, j, m, n):
        if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
            return
        elif grid[i][j] == 1:
            self.area += 1
        grid[i][j] = 0
        self.dfs(grid, i-1, j, m, n)
        self.dfs(grid, i+1, j, m, n)
        self.dfs(grid, i, j-1, m, n)
        self.dfs(grid, i, j+1, m, n)
    
```