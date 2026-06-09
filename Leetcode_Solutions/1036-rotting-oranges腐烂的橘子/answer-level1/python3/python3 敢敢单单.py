```python
from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        self.m = len(grid)
        self.n = len(grid[0])
        good_count = 0
        q = deque()
        self.d = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        res = 0

        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == 1:
                    good_count += 1
                if grid[i][j] == 2:
                    q.append((i, j))

        while len(q):
            length = len(q)
            flag = False  # 本轮是否感染到了橘子的标志，很重要！
            for i in range(length):
                pop_elem = q.popleft()
                for _d in self.d:
                    new_x = pop_elem[0] + _d[0]
                    new_y = pop_elem[1] + _d[1]
                    if self._check_valid(new_x, new_y) and grid[new_x][new_y] == 1:
                        grid[new_x][new_y] = 2
                        good_count -= 1                        
                        q.append((new_x, new_y))
                        flag = True
            if flag:
                res += 1

        return -1 if good_count > 0 else res

    def _check_valid(self, i, j):
        return 0 <= i < self.m and 0 <= j < self.n
```