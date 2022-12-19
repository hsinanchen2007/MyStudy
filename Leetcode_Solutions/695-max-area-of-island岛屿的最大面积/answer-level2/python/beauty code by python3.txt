### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def bfs(position, matrix, row, clum):
            n = 0
            queque = [position]
            while queque:
                x, y = queque.pop(0)
                n += 1
                around = [(x-1, y), (x+1,y), (x, y-1), (x, y+1)]
                for i, j in around:
                    if 0 <= i < row  and 0 <= j < clum and matrix[i][j] == 1:
                        queque.append((i, j))
                        matrix[i][j] = 0
            return n
        
        area = 0
        for i, row in enumerate(grid):
            for j, elment in enumerate(row):
                if elment == 1:
                    grid[i][j] = 0 # initialization
                    area = max(area, bfs((i, j), grid, len(grid), len(grid[0])))
        return area

```