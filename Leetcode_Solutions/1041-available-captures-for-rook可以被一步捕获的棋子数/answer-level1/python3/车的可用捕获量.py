1. 暴力解法，直到循环出解
```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        row = col = count = 0
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'R':
                    row,col = i,j
                    break
        a = 1
        while row - a > -1:
            if board[row-a][col] == 'B':
                break
            elif board[row-a][col] == 'p':
                count += 1
                break
            a += 1
        a = 1
        while row + a < len(board):
            if board[row+a][col] == 'B':
                break
            elif board[row+a][col] == 'p':
                count += 1
                break
            a += 1
        a = 1
        while col - a > -1:
            if board[row][col-a] == 'B':
                break
            elif board[row][col-a] == 'p':
                count += 1
                break
            a += 1
        a = 1
        while col + a < len(board):
            if board[row][col+a] == 'B':
                break
            elif board[row][col+a] == 'p':
                count += 1
                break
            a += 1
        return count
```