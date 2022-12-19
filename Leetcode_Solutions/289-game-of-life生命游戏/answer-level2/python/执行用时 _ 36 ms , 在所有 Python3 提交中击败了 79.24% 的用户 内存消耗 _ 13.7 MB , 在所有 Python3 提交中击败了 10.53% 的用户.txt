### 解题思路
复制一个面板，实现同步更新


### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        b_rows = len(board)
        b_col = len(board[0])
        neighbors = [(-1,0), (-1,-1), (0,-1), (1,-1), (1,0), (1,1), (0,1), (-1,1)]
        #复制原面板
        copy_board = [[board[i][j] for j in range(b_col)] for i in range(b_rows)]
        #计算相邻活细胞数
        for row in range(b_rows):
            for col in range(b_col):
                live_cell = 0
                for neighbor in neighbors:
                    r = row + neighbor[0]
                    c = col + neighbor[1]
                    if (r<b_rows and r>=0) and (c<b_col and c>=0) and copy_board[r][c] == 1:
                        live_cell += 1
                if copy_board[row][col] == 1 and (live_cell < 2 or live_cell >3):
                    board[row][col] = 0
                if copy_board[row][col] == 0 and live_cell == 3:
                    board[row][col] = 1
```