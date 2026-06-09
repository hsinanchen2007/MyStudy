### 解题思路
深度优先搜索

### 代码

```python3
class Solution(object):
    def maxAreaOfIsland(self, grid):
        if grid == [[]]:
            return 0
        m = len(grid)
        n = len(grid[0])
        ret = []
        for x in range(m):
            for y in range(n):
                if grid[x][y] == 1:
                    count = 1
                    grid[x][y] = 0
                    res = [[x,y]]
                    while True:
                        l =len(res)
                        for x,y in res:
                            for dx,dy in [(-1,0),(1,0),(0,1),(0,-1)]:
                                xi = x + dx
                                yi = y + dy
                                if 0 <= xi < m and 0 <= yi < n:
                                    if grid[xi][yi] == 1:
                                        count += 1
                                        grid[xi][yi] = 0
                                        res.append([xi,yi])
                        if len(res)-l==0:
                            ret.append(count)
                            break
        return max(ret) if ret != [] else 0
```