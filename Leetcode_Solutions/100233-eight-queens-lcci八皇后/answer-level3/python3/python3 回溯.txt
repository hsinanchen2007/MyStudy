```
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        count = []
        board = [['.' for i in range(n)] for j in range(n)]
        def backtrack(row, board):
            n = len(board)
            if row==n:
                temp = []
                for i in board:
                    temp.append("".join(i))
                count.append(temp)
                return 
            for col in range(n):
                if isvalid(board, row, col) == False:
                    continue
                board[row][col] = 'Q'
                backtrack(row+1, board)
                board[row][col] = '.'
    
        def isvalid(board, row, col):
            for j in range(len(board)):
                if board[j][col] == 'Q':
                    return False
            a = row-1; b = col-1; 
            while a>=0 and b>=0:
                if board[a][b] == 'Q':
                    return False
                a -= 1; b -= 1
            c = col+1; d = row-1
            while d>=0 and c<n:
                if board[d][c] == 'Q':
                    return False
                d -= 1; c += 1
            return True
        backtrack(0, board)
        return count
```

