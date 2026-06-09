很简单的用新的空间记录每个位置的状态，最后把值赋回去。
```
class Solution:
    def count(self, board,i,j):
        live = 0
        dead = 0
        dx = [-1,-1,-1,0,0,1,1,1]
        dy = [-1,0,1,-1,1,-1,0,1]
        for k in range(8):
            if( (i+dx[k]>=0 and i+dx[k] < len(board)) and (j+dy[k]>=0 and j+dy[k] < len(board[0])) ):
                if(board[i+dx[k]][j+dy[k]] == 1):
                    live += 1
                else:
                    dead +=1
        return live,dead
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        new_board = [[0 for _ in range(len(board[0]))] for _ in range(len(board))]
        for i in range(len(board)):
            for j in range(len(board[0])):
                # rule 1
                live,dead = self.count(board,i,j)
                if(board[i][j] == 1):
                    # rule 1
                    if live<2 or live>3:
                        new_board[i][j] = 0
                    else:
                        new_board[i][j] = 1
                else:
                    if(live == 3):
                        new_board[i][j] = 1
                    else:
                        new_board[i][j] = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = new_board[i][j]
```
