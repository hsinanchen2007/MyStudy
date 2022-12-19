思路源自[130.被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)
陆地若连边界则一定不是封闭岛屿，因此先把与边界相连的岛屿全部变成水域，此时剩下的岛屿均为封闭岛屿，dfs统计即可
```
class Solution(object):
    def closedIsland(self, grid):
        if not grid or not grid[0]:
            return grid
        
        row, col = len(grid), len(grid[0])

        def dfs(x, y):
            grid[x][y] = 1
            for dx, dy in [[1,0],[0,1],[-1,0],[0,-1]]:
                if 0<=x+dx<row and 0<=y+dy<col and grid[x+dx][y+dy] == 0:
                    dfs(x+dx, y+dy)

        for i in range(row):
            if grid[i][0] == 0: dfs(i, 0)
            if grid[i][col-1] == 0: dfs(i, col-1)
        for j in range(col):
            if grid[0][j] == 0: dfs(0, j)
            if grid[row-1][j] == 0: dfs(row-1, j)

        ans = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    ans += 1
                    dfs(i, j)
        return ans

```
