### 解题思路
这题就是加规则的BFS问题，这里的6条路代表着下一步怎么走，换句话说就是当前在A种street的时候下一步是哪种street类型才合理，我的走路方向是上下左右，rule定义的规则也是如此。

### 代码

```python3
import numpy as np
import queue
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        path = np.zeros((m, n))
        rule = {
            1:[[], [], [1, 4, 6], [1, 3, 5]],
            2:[[2, 3, 4], [2, 5, 6], [], []],
            3:[[], [2, 5, 6], [1, 4, 6], []],
            4:[[], [2, 5, 6], [], [1, 3, 5]],
            5:[[2, 3, 4], [], [1, 4, 6], []],
            6:[[2, 3, 4], [], [], [1, 3, 5]]
        }
        move = [
            [-1, 1, 0, 0],
            [0, 0, -1, 1]
        ]
        q = queue.Queue()
        q.put([0,0])
        path[0][0] = 1
        while not q.empty():
            x, y = q.get()
            street = grid[x][y]
            if x == m-1 and y == n-1:
                return True
            for i in range(4):
                cur_x = x + move[0][i]
                cur_y = y + move[1][i]
                if cur_x >= 0 and cur_x <= m-1 and cur_y >= 0 and cur_y <= n-1 and path[cur_x][cur_y] != 1 and grid[cur_x][cur_y] in rule[street][i]:
                    # print([cur_x, cur_y], grid[cur_x][cur_y])
                    q.put([cur_x, cur_y])
                    path[cur_x][cur_y] = 1
        return False
```