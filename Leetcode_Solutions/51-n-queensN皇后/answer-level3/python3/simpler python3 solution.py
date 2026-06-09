### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []

        board = [['.']*n for _ in range(n)]

        backslashes = []
        forwardslashes = []
        columns = []

        def backtrace(board, row = 0):
            if row == n:
                res.append([''.join(e) for e in board])
                return

            for col in range(n):
                forward = row + col
                back = col - row

                if (forward in forwardslashes) or (back in backslashes) or (col in columns):
                    continue

                forwardslashes.append(forward)
                backslashes.append(back)
                columns.append(col)
                board[row][col] = 'Q'

                backtrace(board, row + 1)

                forwardslashes.pop()
                backslashes.pop()
                columns.pop()
                board[row][col] = '.'

        backtrace(board)

        return res
                
```