### 解题思路
很典型的BFS。

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = [(i, j) for i in range(m) for j in range(n) if grid[i][j] == 2]
        s, time =[], 0
        while q:
            while q:
                i, j = q.pop(0)
                for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                    if 0 <= x< m and 0 <= y < n  and grid[x][y] == 1:
                        s.append((x, y))
                        grid[x][y] +=1
            if s:
                time +=1
            q, s = s, q
            
        return -1 if any([grid[i][j] == 1 for i in range(m) for j in range(n)]) else time
```