### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def isVaild(n,col,k):
            for m in range(len(board[0])):
                if board[n][m] == str(k):
                    return False
            for l in range(len(board)):
                if board[l][col] == str(k):
                    return False
            if n <= 2 and col <= 2:
                for i in range(3):
                    for j in range(3):
                        if board[i][j] == str(k):
                            return False
            if n > 2 and n <= 5 and col <= 2:
                for i in range(3,6,1):
                    for j in range(3):
                        if board[i][j] == str(k):
                            return False
            if n > 5 and col <= 2:
                for i in range(6,9,1):
                    for j in range(3):
                        if board[i][j] == str(k):
                            return False
            if n <= 2 and col > 2 and col <= 5:
                for i in range(3):
                    for j in range(3,6,1):
                        if board[i][j] == str(k):
                            return False
            if n <= 2 and col > 5:
                for i in range(3):
                    for j in range(6,9,1):
                        if board[i][j] == str(k):
                            return False
            if n > 2 and n <= 5 and col > 2 and col <= 5:
                for i in range(3,6,1):
                    for j in range(3,6,1):
                        if board[i][j] == str(k):
                            return False
            if n > 2 and n <= 5 and col > 5:
                for i in range(3,6,1):
                    for j in range(6,9,1):
                        if board[i][j] == str(k):
                            return False
            if n > 5 and col > 2 and col <= 5:
                for i in range(6,9,1):
                    for j in range(3,6,1):
                        if board[i][j] == str(k):
                            return False
            if n > 5 and col > 5:
                for i in range(6,9,1):
                    for j in range(6,9,1):
                        if board[i][j] == str(k):
                            return False
            return True
        def back(board,n,k):
            global result
            if n == len(board):
                return True
            if board[n][k] == '.':
                for i in range(1,10,1):
                    if isVaild(n,k,i):
                        board[n][k] = str(i)
                        if k + 1 < len(board[0]):
                            if (back(board,n,k + 1)):
                                return True
                        if k + 1 == len(board[0]):
                            if (back(board,n + 1,0)):
                                return True
                        board[n][k] = '.'
            else:
                if k + 1 < len(board[0]):
                    if (back(board,n ,k + 1)):
                        return True
                elif k + 1 == len(board[0]):
                    if (back(board,n + 1,0)):
                        return True
        back(board,0,0)
```