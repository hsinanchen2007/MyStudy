```python
from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # 判断坐标是否合法
        def inArea(x, y):
            return x >= 0 and x < m and y >= 0 and y < n

        def backtrack(index, startx, starty):
            if index == len(word)-1:
                return board[startx][starty] == word[index]
            if board[startx][starty] == word[index]:
                # 标记该坐标已被访问
                used[startx][starty] = True
                # 在该坐标的上右下左四个方向依次寻找
                for k in range(4):
                    newx = startx + d[k][0]
                    newy = starty + d[k][1]
                    if inArea(newx, newy) and not used[newx][newy] and backtrack(index + 1, newx, newy):
                        return True
                used[startx][starty] = False

        m = len(board)
        n = len(board[0])
        d = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        used = [[False] * n for i in range(m)]
        for i in range(m):
            for j in range(n):
                if backtrack(0, i, j):
                    return True
        return False
```
