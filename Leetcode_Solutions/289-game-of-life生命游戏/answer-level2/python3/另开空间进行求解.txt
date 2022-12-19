```
from copy import deepcopy


class Solution:
    def gameOfLife(self, board: [[int]]) -> None:
        cp = deepcopy(board)
        row = len(board)
        col = len(board[0])
        cp.append([-1 for _ in range(col + 2)])
        cp.insert(0, [-1 for _ in range(col + 2)])
        for i in range(1, 1 + row):
            cp[i].append(-1)
            cp[i].insert(0, -1)
        for i in range(1, 1 + row):
            for j in range(1, 1 + col):
                live_count = [1 for m in range(i - 1, i + 2) for n in range(j - 1, j + 2) if cp[m][n] == 1]
                live_count = sum(live_count)
                if board[i - 1][j - 1] == 1:
                    if live_count < 3 or live_count > 4:
                        board[i - 1][j - 1] = 0
                else:
                    if live_count == 3:
                        board[i - 1][j - 1] = 1
```
