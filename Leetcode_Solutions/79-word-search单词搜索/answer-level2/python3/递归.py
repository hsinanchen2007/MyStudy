```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        found = False
        def searchwd(board, i, j, word):
            nonlocal found
            if found:
                return False
            rows = len(board)
            cols = len(board[0])
            #print(i,j,word)
            if i<0 or i>=rows or j<0 or j>=cols or board[i][j] != word[0]:
                return False
            if len(word) == 1:
                found = True
                return True
            old = board[i][j]
            board[i][j] = ' '
            for oi, oj in [[0,1],[1,0],[0,-1],[-1,0]]:
                searchwd(board, i+oi, j+oj, word[1:])
            board[i][j] = old
            return True
        for i in range(len(board)):
            for j in range(len(board[0])):
                searchwd(board, i, j, word)
                if found:
                    return True
        return found
```
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def searchwd(board, i, j, word):
            rows = len(board)
            cols = len(board[0])
            if i<0 or i>=rows or j<0 or j>=cols or board[i][j] != word[0]:
                return False
            if len(word) == 1:
                return True
            old = board[i][j]
            board[i][j] = ' '
            for oi, oj in [[0,1],[1,0],[0,-1],[-1,0]]:
                if searchwd(board, i+oi, j+oj, word[1:]):
                    board[i][j] = old
                    return True
            board[i][j] = old
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if searchwd(board, i, j, word):
                    return True
        return False
```
