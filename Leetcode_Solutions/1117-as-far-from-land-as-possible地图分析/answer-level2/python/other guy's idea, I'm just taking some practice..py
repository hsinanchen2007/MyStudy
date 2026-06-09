### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        def bfs(q, n):            
            while q:
                x, y = q.popleft() #last pop out (x, y) is the longest ocean position
                for i, j in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    z, k = x+i, y+j
                    if 0 <= z < n and 0 <= k < n and grid[z][k] == 0:
                        q.append((z, k)) 
                        grid[z][k] = grid[x][y] + 1
            return grid[x][y] - 1
            #distance from land here is 1+(1, 2, 3 ...) actually is 0+(1, 2, 3 ...)

        q = collections.deque()
        for i, row in enumerate(grid):
            for j, value in enumerate(row):
                if value == 1:
                    q.append((i, j))
        n = len(grid)
        if not q or len(q) == n*n: return -1     
        return bfs(q, n)
```