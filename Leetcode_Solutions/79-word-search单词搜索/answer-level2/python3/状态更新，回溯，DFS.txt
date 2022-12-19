### 解题思路
找出起始点，然后四向搜索，记录状态，回溯状态退回。

### 代码

```python3
from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        row = len(board)
        col = len(board[0])
        status = [[False for _ in range(col)] for _ in range(row)]

        def dfs(x: int, y: int, index: int, target: str):

            if index == len(target) - 1:
                return board[x][y] == target[index]

            if target[index] == board[x][y]:
                status[x][y] = True

                if 0 <= x + 1 < row and 0 <= y < col and not status[x + 1][y] and dfs(x + 1, y, index + 1, target):
                    return True
                if 0 <= x - 1 < row and 0 <= y < col and not status[x - 1][y] and dfs(x - 1, y, index + 1, target):
                    return True

                if 0 <= x < row and 0 <= y - 1 < col and not status[x][y - 1] and dfs(x, y - 1, index + 1, target):
                    return True
                if 0 <= x < row and 0 <= y + 1 < col and not status[x][y + 1] and dfs(x, y + 1, index + 1, target):
                    return True
                status[x][y] = False

        if not board:
            return False

        start_point = []

        for i in range(row):
            for j in range(col):
                if board[i][j] == word[0]:
                    start_point.append([i, j])
        if not start_point:
            return False
        for point in start_point:
            x, y = point
            if dfs(x, y, 0, word) is True:
                return True
            status = [[False for _ in range(col)] for _ in range(row)]

        return False

```