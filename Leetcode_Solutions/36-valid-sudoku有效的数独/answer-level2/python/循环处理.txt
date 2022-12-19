首先提取行和列中的非空数字查重，然后分区域处理九宫格各区域（宫格），过程相同，提取非空数字-查重。

```
   class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(len(board)):
            row, col = [], []
            col_oral = []
            # 提出行中数字
            for char in board[i][:]:
                if char != '.':
                    row.append(char)
            row_only = set(row)
            # 提出列中数字
            for j in range(len(board)):
                col_oral.append(board[j][i])
                for char in board[j][i]:
                    if char != '.':
                        col.append(char)
            col_only = set(col)
            if len(row) != len(row_only) or len(col) != len(col_only):      # 查重
                return False
        # 方块中
        # square_oral = []
        square = []
        x, y = 0, 0
        while x < 3:
            while y < 3:        # （x，y）定位当前区域（宫格）位置
                for i in range(3):
                    for j in range(3):      # （i+x*3， j+y*3）定位当前单元格
                        # square_oral.append(board[x*3+i][y*3+j])
                        if board[x*3+i][y*3+j] != '.':
                            square.append(board[x*3+i][y*3+j])      # 获取当前区域（宫格）所有数字
                if len(square) != len(set(square)):     # 查重
                    return False
                y += 1  # 左移一个区域
                square, square_oral = [], []    # 清空存储空间，准备下一个区域（宫格）处理
            x += 1      # 处理下一行宫格，并清空y
            y = 0
        return True
```
