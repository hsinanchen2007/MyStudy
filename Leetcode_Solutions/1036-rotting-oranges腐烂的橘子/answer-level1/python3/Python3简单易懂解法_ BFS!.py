### 解题思路
把已腐烂的先找出来, 然后放入Q, 进行BFS
最后比较一下, 如果新腐烂的好果子数目 < 原本总的好果子数, 那么有存在从没感染的好果子, 返回-1. 否则就返回用来计算距离的time.
注意一般处理grid, matrix这种矩阵的, 不用x, y坐标, 而用row, col更直观.
### 代码

```python3
# bfs
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        max_row = len(grid) - 1
        max_col = len(grid[0]) - 1
        time = 0
        good_total = 0
        Q = []
        for row in range(max_row + 1):
            for col in range(max_col + 1):
                if grid[row][col] == 2:
                    Q.append((row, col, 0))
                if grid[row][col] == 1:
                    good_total += 1
        rotten_count = 0
        while len(Q) > 0:
            node = Q.pop(0)
            row, col, time = node[0], node[1], node[2]
            if col + 1 <= max_col and grid[row][col + 1] == 1:
                Q.append((row, col + 1, time + 1))
                grid[row][col + 1] = 2
                rotten_count += 1
            if row + 1 <= max_row and grid[row + 1][col] == 1:
                Q.append((row + 1, col, time + 1))
                grid[row + 1][col] = 2
                rotten_count += 1
            if row - 1 >= 0 and grid[row - 1][col] == 1:
                Q.append((row - 1, col, time + 1))
                grid[row - 1][col] = 2
                rotten_count += 1
            if col - 1 >= 0 and grid[row][col - 1] == 1:
                Q.append((row, col - 1, time + 1))
                grid[row][col - 1] = 2
                rotten_count += 1
            
        if rotten_count < good_total:  # 有好橘子没被腐烂病菌感染
            return -1
        return time

```