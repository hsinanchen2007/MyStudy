```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        result = 0
        for row, value in enumerate(board):
            for col, val in enumerate(value):
                if val == 'R':
                    ### 向上查找
                    for r in range(row-1, -1, -1):
                        if board[r][col] == 'B':
                            break
                        elif board[r][col] == 'p':
                            result += 1
                            break
                        else:
                            continue
                    ### 向下查找
                    for r in range(row, 8):
                        if board[r][col] == 'B':
                            break
                        elif board[r][col] == 'p':
                            result += 1
                            break
                        else:
                            continue
                    ### 向左查找
                    for c in range(col-1, -1, -1):
                        if board[row][c] == 'B':
                            break
                        elif board[row][c] == 'p':
                            result += 1
                            break
                        else:
                            continue
                    ### 向右查找
                    for c in range(row, 8):
                        if board[row][c] == 'B':
                            break
                        elif board[row][c] == 'p':
                            result += 1
                            break
                        else:
                            continue
        return result 
```
