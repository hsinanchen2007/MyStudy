### 解题思路
先找出腐烂的橘子，放入队列，作为第 0 层的结点。
BFS遍历，上下左右四个方向，并且判断边界条件；记录新鲜橘子，以及在遍历过程中的轮数。

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        queue = []

        cnt = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    cnt += 1
                elif grid[r][c] == 2:
                    queue.append((r, c))
        
        round = 0
        while cnt > 0 and len(queue) > 0:
            round += 1
            nn = len(queue)
            for i in range(nn):
                r, c = queue.pop(0)
                if r - 1 >= 0 and grid[r - 1][c] == 1:
                    grid[r-1][c] = 2
                    cnt -= 1
                    queue.append((r-1, c))
                if r+1 < m and grid[r+1][c] == 1:
                    grid[r+1][c] = 2
                    cnt -= 1
                    queue.append((r+1, c))
                if c - 1 >= 0 and grid[r][c-1] == 1:
                    grid[r][c-1] = 2
                    cnt -= 1
                    queue.append((r, c - 1))
                if c + 1 < n and grid[r][c+1] == 1:
                    grid[r][c+1] = 2
                    cnt -= 1
                    queue.append((r, c+1))
        
        print(cnt)


        if cnt > 0:
            return -1
        else:
            return round

```