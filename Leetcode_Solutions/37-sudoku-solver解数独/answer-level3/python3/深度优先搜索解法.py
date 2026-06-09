### 解题思路
我暂时想不出来太好的办法，只能选择暴力一点的深度优先搜索了，使用深度优先搜索的时候加上一些剪枝策略能够减少一些事件
需要用一些中间变量来存储当前运行的状态，我们可以根据三个表来对当前搜索进行简单的剪枝
### 代码

```python3
class Solution:
    def __init__(self):
        self._row = [[False for i in range(1, 10 + 1)] for y in range(9)]
        self._col = [[False for i in range(1, 10 + 1)] for x in range(9)]
        self._box = [[False for i in range(1, 10 + 1)] for box in range(9)]

    def solveSudoku(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        for row in range(9):
            for col in range(9):
                char = board[row][col]
                if char != ".":
                    n = int(char)
                    self._row[row][n] = True
                    self._col[col][n] = True
                    self._box[Solution.box_index(row, col)][n] = True
        
        self.fill(board, 0, 0)
    
    def fill(self, board, row, col):
        if row == 9:
            return True
        
        next_col = (col + 1) % 9
        next_row = row if next_col != 0 else row + 1
        if board[row][col] != '.':
            return self.fill(board, row=next_row, col=next_col)
        for n in range(1, 10):
            box_key = Solution.box_index(row=row, col=col)
            if not self._row[row][n] and not self._col[col][n] and not self._box[box_key][n]:
                self._row[row][n] = True
                self._col[col][n] = True
                self._box[box_key][n] = True
                board[row][col] = str(n)
                if self.fill(board, row=next_row, col=next_col):
                    return True
                board[row][col] = '.'
                self._row[row][n] = False
                self._col[col][n] = False
                self._box[box_key][n] = False
        return False

    @staticmethod
    def box_index(row, col):
        """
        row: row index
        col: colum index
        return: boxes index
        
        row          [0, 1, 2] [3, 4, 5] [6, 7, 8]
        col 0 1 2 ->  0         3         6
        col 3 4 5 ->  1         4         7
        col 6 7 8 ->  2         5         8
        so box index = (row // 3) * 3 + col // 3
        """
        return (row // 3) * 3 + col // 3

```