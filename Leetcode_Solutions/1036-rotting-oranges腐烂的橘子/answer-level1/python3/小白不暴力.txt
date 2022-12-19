### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        good = {(i,j) for i in range(row) for j in range(col) if grid[i][j]==1}
        rot = {(i,j) for i in range(row) for j in range(col) if grid[i][j]==2}
        time = 0
        while good:
            if not rot:return -1;
            rot = {(i + di, j + dj) for i, j in rot for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)] if (i + di,j + dj) in good}
            good-=rot
            time+=1
        return time
```