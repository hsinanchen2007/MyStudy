### 解题思路
- 题目和普通的广搜区别在于引入了一个障碍物计数；那么用 `d[i,j,k]` 代表还剩`k`次障碍时到达 `(i,j)`点；
- 广搜第一个到达终点对应最短路；
- 注意`visited`应该在入队时候标记，否则可能造成重复入队；

### 代码
```python
from collections import deque
class Solution:
    def shortestPath(self, grid: "List[List[int]]", k: int) -> int:
        if len(grid) == 1 and len(grid[0]) == 1:
            return 0

        queue = deque([(0,0,k,0)])
        visited = set([(0,0,k)])

        while queue:
            row, col, eliminate, steps = queue.popleft()
            for new_row, new_col in [(row-1,col), (row,col+1), (row+1, col), (row, col-1)]:
                if (new_row >= 0 and
                    new_row < len(grid) and
                    new_col >= 0 and
                    new_col < len(grid[0])):
                    if grid[new_row][new_col] == 1 and eliminate > 0:
                        if (new_row, new_col, eliminate-1) not in visited:
                            visited.add((new_row, new_col, eliminate-1))
                            queue.append((new_row, new_col, eliminate-1, steps+1))
                    if grid[new_row][new_col] == 0 and (new_row, new_col, eliminate) not in visited:
                        if new_row == len(grid)-1 and new_col == len(grid[0])-1:
                            return steps+1
                        visited.add((new_row, new_col, eliminate))
                        queue.append((new_row, new_col, eliminate, steps+1))

        return -1
```