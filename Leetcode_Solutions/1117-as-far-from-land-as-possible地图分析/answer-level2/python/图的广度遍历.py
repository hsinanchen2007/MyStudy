### 解题思路
广度遍历的一般思路和题解

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        l = len(grid)

        queue = []
        for i in range(l):
            for j in range(l):
                if grid[i][j] == 1:
                    queue.append((i, j))
        
        # 全是海洋 or 全是陆地
        if len(queue) == 0 or len(queue) == l * l:
            return -1 

        depth = 0
        while queue:
            depth += 1
            size = len(queue)
            for i in range(size):
                x, y = queue.pop(0)
                if x - 1 >= 0 and grid[x-1][y] == 0:
                    grid[x-1][y] = 2
                    queue.append((x-1, y))
                if x + 1 < l and grid[x+1][y] == 0:
                    grid[x+1][y] = 2
                    queue.append((x+1, y))      
                if y - 1 >= 0 and grid[x][y-1] == 0:
                    grid[x][y-1] = 2
                    queue.append((x, y-1))
                if y + 1 < l and grid[x][y+1] == 0:
                    grid[x][y+1] = 2
                    queue.append((x, y+1))
        
        return depth - 1
```