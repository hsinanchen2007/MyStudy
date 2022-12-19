import copy
class Solution:
    def gameOfLife(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        temp = copy.deepcopy(board)
        for i in range(m):
            for j in range(n):
                lives = 0
                for move_i,move_j in [(1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)]:
                    if i+move_i < 0 or i+move_i > m-1 or j+move_j < 0 or j+move_j > n-1:
                        continue
                    lives += temp[i+move_i][j+move_j]
                if lives < 2 or lives > 3:#这里可以注意的是
                    board[i][j] = 0
                if lives == 3:
                    board[i][j] = 1
        return None
```
import copy
class Solution:
    def gameOfLife(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        temp = copy.deepcopy(board)
        for i in range(m):
            for j in range(n):
                lives = 0
                for move_i,move_j in [(1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)]:
                    if i+move_i < 0 or i+move_i > m-1 or j+move_j < 0 or j+move_j > n-1:
                        continue
                    lives += temp[i+move_i][j+move_j]
                if lives < 2 or lives > 3:#这里可以注意的是我们只需要更新那些会死或者会活的
                    board[i][j] = 0
                if lives == 3:
                    board[i][j] = 1
        return None

```
