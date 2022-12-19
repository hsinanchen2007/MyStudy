```
class Solution(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        count = 0
        for x in range(len(board)):
            for y in range(len(board[0])):
                if board[x][y] == 'R':
                    i = x
                    j = y
                    break
        if i == 0:
            for col in range(1, len(board)):
                if board[col][j] == 'B':
                    break
                elif board[col][j] == 'p':
                    count += 1
                    break
        elif i == len(board):
            for col in range(len(board) - 1, -1, -1):
                if board[col][j] == 'B':
                    break
                elif board[col][j] == 'p':
                    count += 1
                    break
        else:
            for col in range(i - 1, -1, -1):
                if board[col][j] == 'B':
                    break
                elif board[col][j] == 'p':
                    count += 1
                    break
            for col in range(i + 1, len(board)):
                if board[col][j] == 'B':
                    break
                elif board[col][j] == 'p':
                    count += 1
                    break
        if j == 0:
            for row in range(1, len(board[0])):
                if board[i][row] == 'B':
                    break
                elif board[i][row] == 'p':
                    count += 1
                    break
        elif j == len(board[0]):
            for row in range(len(board[0]) - 1, -1, -1):
                if board[i][row] == 'B':
                    break
                elif board[i][row] == 'p':
                    count += 1
                    break
        else:
            for row in range(j - 1, -1, -1):
                if board[i][row] == 'B':
                    break
                elif board[i][row] == 'p':
                    count += 1
                    break
            for row in range(j + 1, len(board[0])):
                if board[i][row] == 'B':
                    break
                elif board[i][row] == 'p':
                    count += 1
                    break            
        return count
```
