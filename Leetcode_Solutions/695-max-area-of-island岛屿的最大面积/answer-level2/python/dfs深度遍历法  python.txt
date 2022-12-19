### 解题思路
和leetcode200类似

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row,col = len(grid),len(grid[0])
        res = 0

        def dfs(x,y):
            if x < 0 or x >= row or y < 0 or y >= col:
                return 0
            if grid[x][y] == 0:
                return 0
            grid[x][y] = 0
            return dfs(x+1,y) + dfs(x-1,y) + dfs(x,y+1) + dfs(x,y-1) + 1
            
        for x in range(row):
            for y in range(col):
                if grid[x][y] == 1:
                    res = max(res,dfs(x,y))
        return res




```