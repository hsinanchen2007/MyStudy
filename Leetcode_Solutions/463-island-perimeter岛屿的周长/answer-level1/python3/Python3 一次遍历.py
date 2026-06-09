一次遍历，如果当前格的四周（超出边界 or 是水），那么周长+1
```
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if i-1<0 or grid[i-1][j] == 0:
                        ans+=1
                    if i+1>=m or grid[i+1][j] == 0:
                        ans+=1
                    if j-1<0 or grid[i][j-1] == 0:
                        ans+=1
                    if j+1>=n or grid[i][j+1] == 0:
                        ans+=1
        return ans
```
