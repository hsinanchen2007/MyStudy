```python
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row, col = len(board), len(board[0])
        def calculate(i, j):
            if i < 0 or i >= row or j < 0 or j >= col: return 0 
            return board[i][j] > 0

        for i in range(row):
            for j in range(col):
                cnt = 0
                for x, y in [[i, j + 1],[i, j - 1],[i - 1, j],[i + 1, j],[i + 1, j -1],[i + 1, j + 1],[i -1, j - 1],[i - 1, j + 1]]:
                    cnt += calculate(x, y)
                if board[i][j] == 1:
                    if 2 <= cnt <= 3: board[i][j] = 3 # 仍然是活细胞
                    else: board[i][j] = 2 # 变成了死细胞
                else:
                    if cnt == 3: board[i][j] = 0 # 变成了活细胞
                    else: board[i][j] = -1 # 仍然是死细胞
        for i in range(row):
            for j in range(col):
                if board[i][j] == 3 or board[i][j] == 0: board[i][j] = 1
                else: board[i][j] = 0




```