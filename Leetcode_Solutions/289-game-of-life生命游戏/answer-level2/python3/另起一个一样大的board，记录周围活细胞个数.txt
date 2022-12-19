遍历两次，第一次记录所有细胞周围的活细胞数量，因为细胞的生死只由周围活细胞数量决定
第二次根据记录表，按照题意修改细胞状态即可

```python
from functools import lru_cache
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = len(board)
        col = len(board[0])
        @lru_cache(None)
        def get_nei(i, j):
            res = []
            for x in range(max(1, i)-1,  min(row, i+2)):
                for y in range(max(1, j)-1, min(col, j+2)):
                    if x == i and y == j:
                        continue
                    else:
                        res.append((x, y))
            return res


        tag_board = [[0] * col for _ in range(row)]

        for i in range(row):
            for j in range(col):
                for pos in get_nei(i, j):
                    if board[pos[0]][pos[1]] == 1:
                        tag_board[i][j] += 1

        for i in range(row):
            for j in range(col):
                if board[i][j] == 1:
                    if tag_board[i][j] < 2:
                        board[i][j] = 0
                    elif tag_board[i][j] <= 3:
                        board[i][j] = 1
                    elif tag_board[i][j] > 3:
                        board[i][j] = 0
                else:
                    if tag_board[i][j] == 3:
                        board[i][j] = 1

```

写的时候觉得get_nei用来获取合法格子的方法可能有重复调用，所以加了个缓存装饰器加速，现在看来好像没什么卵用。。。_(:з」∠)_