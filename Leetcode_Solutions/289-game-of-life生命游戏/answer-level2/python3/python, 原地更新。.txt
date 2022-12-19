### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m = len(board)
        n = len(board[0])
        around = [(0, -1), (0, 1), (1, 0), (1, -1), (1, 1), (-1, 0), (-1, -1), (-1, 1)]
        for i, row in enumerate(board):
            for j, value in enumerate(row):
                live = 0
                for x, y in around:
                    t0, t1 = i+x, j+y
                    if 0 <= t0 < m and 0 <= t1 < n:
                    #周围不一定有八个元素 所以不能记录死细胞的数量。
                        isLive = board[t0][t1] 
                        if isLive == 1 or isLive == -1: 
                            live += 1
                if live < 2 or live > 3:
                    if value == 1:
                        board[i][j] = -1  # live -> death
                elif live == 3:
                    if value == 0:
                        board[i][j] = -2 # death -> live
        for i, row in enumerate(board):
            for j, value in enumerate(row):
                if value == -1:
                    board[i][j] = 0
                elif value == -2:
                    board[i][j] = 1
        return board
        

```