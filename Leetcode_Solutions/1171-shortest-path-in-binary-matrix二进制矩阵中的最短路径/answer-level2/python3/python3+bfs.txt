### 解题思路
还可以状态压缩+原地标记优化一下

### 代码

```python3
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])
        visited = [[False for _ in range(C)] for _ in range(R)]
        dis = [[0 for _ in range(C)] for _ in range(R)]
        if grid[0][0] == 1:
            return -1
        if R == 1 and C == 1:
            return 1
        stack = []
        stack.append((0,0))
        visited[0][0] = True
        dis[0][0] = 1
        d = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]
        while stack:
            cur = stack.pop(0)
            x = cur[0]
            y = cur[1]
            for i, j in d:
                tmp_x = x + i
                tmp_y = y + j
                if 0 <= tmp_x < R and 0 <= tmp_y < C \
                    and not visited[tmp_x][tmp_y] and \
                    grid[tmp_x][tmp_y] == 0:
                    stack.append((tmp_x,tmp_y))
                    visited[tmp_x][tmp_y] = True
                    dis[tmp_x][tmp_y] = dis[x][y] + 1
                    if tmp_x == R - 1 and tmp_y == C - 1:
                        return dis[tmp_x][tmp_y]
        return -1
```