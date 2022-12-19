### 解题思路
直接套用回溯法模板
一、初始化
二、找到返回条件
三、找到进入条件
四、使用
五、递归
六、回溯

### 代码

```python3
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 初始化 x 行(列) 数字(y)
        rows = [[False for _ in range(9)] for _ in range(9)]
        cols = [[False for _ in range(9)] for _ in range(9)]
        boxes = [[[False for _ in range(9)] for _ in range(3)] for _ in range(3)]
        # 原本有数字的地方填为True
        for row in range(9):
            for col in range(9):
                num = ord(board[row][col]) - ord('0')
                if 1 <= num <= 9:
                    rows[row][num-1] = True
                    cols[col][num-1] = True
                    boxes[row//3][col//3][num-1] = True
        self.solveSudokuCore(board, rows, cols, boxes, 0, 0)

    def solveSudokuCore(self, board, rows, cols, boxes, row, col):
        # 回溯发需要先找到return 条件
        if col == len(board[0]):
            col = 0
            row += 1
            if row == len(board):
                return True
        if board[row][col] == '.':
            for num in range(0,9):
                # 行， 列， 9格 全部满足条件时 (回溯法基本模板，找到进入条件)
                canUsed = not (rows[row][num] or cols[col][num] or boxes[row//3][col//3][num])
                if canUsed:
                    # 先使用
                    rows[row][num] = True
                    cols[col][num] = True
                    boxes[row//3][col//3][num] = True
                    board[row][col] = str(num+1)
                    # 再递归
                    if self.solveSudokuCore(board, rows, cols, boxes, row, col+1):
                        return True
                    # 最后回溯(还原)
                    rows[row][num] = False
                    cols[col][num] = False
                    boxes[row // 3][col // 3][num] = False
                    board[row][col] = '.'

        else:
            return self.solveSudokuCore(board, rows, cols, boxes, row, col+1)
        return False
```