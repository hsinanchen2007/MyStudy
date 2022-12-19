### 解题思路
代码如下，欢迎交流～

### 代码

```python3
import numpy as np
def count_living_around(l):
    m, n = len(l), len(l[0])
    edge0 = np.pad(np.array(l), pad_width=1, mode='constant', constant_values=0)
    livelist = np.zeros((m, n), dtype=int)
    for row in range(m):
        for col in range(n):
            livelist[row, col] = np.sum(edge0[row:row+3, col:col+3]) - edge0[row+1, col+1]
    return livelist.tolist()

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        livelist = count_living_around(board)
        m, n = len(board), len(board[0])
        for row in range(m):
            for col in range(n):
                if board[row][col] == 0:
                    if livelist[row][col] == 3:
                        board[row][col] = 1
                else:
                    if livelist[row][col] < 2 or livelist[row][col] > 3:
                        board[row][col] = 0
        return

```