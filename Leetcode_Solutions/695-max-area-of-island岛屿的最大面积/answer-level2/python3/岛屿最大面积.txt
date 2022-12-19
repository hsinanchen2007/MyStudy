### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        length = len(grid[0])
        high = len(grid)
        ans  = 0
        for i in range(high):
            for j in range(length):
                if grid[i][j]!=0:
                    ans = max(ans, self.dfs(i,j,grid))
        return ans

    def dfs(self, i, j, grid):
        if  i<0 or i>=len(grid) or j<0 or j>=len(grid[0]) or grid[i][j]!=1:
            return 0

        grid[i][j] = 2

        num = 1

        op = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        for dx, dy in op:
            num+=self.dfs(i+dx, j+dy, grid)
        # num+=self.dfs(i, j-1, grid)
        # num+=self.dfs(i-1, j, grid)
        # num+=self.dfs(i+1, j, grid)

        return num
        
```