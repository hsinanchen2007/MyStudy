### 解题思路
沉岛，将访问过的岛设为海洋，免去了访问数组，节省了空间

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid):
        m = len(grid)
        n = len(grid[0])
        q = []
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i,j)) #入队
                    cnt = 1
                    while q:
                        i, j = q.pop(0) #出队
                        grid[i][j] = 0 #访问过置零
                        for x, y in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
 #四周是否为岛屿并且满足边界条件
                            if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                                cnt += 1 
                                q.append((x, y))
                                grid[x][y] = 0 #访问过置零
                    ans = max(ans, cnt)
        return ans
```