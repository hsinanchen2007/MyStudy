```
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m=len(board)
        n=len(board[0])
        turn=[[-1 for i in range(n)]for j in range(m)]
        for i in range(m):
            for j in range(n):
                count=0
                for x,y in [[i-1,j-1],[i-1,j],[i-1,j+1],[i,j-1],[i,j+1],[i+1,j-1],[i+1,j],[i+1,j+1]]:
                    if x>=0 and x<m and y>=0 and y<n:
                        if board[x][y]==1:
                            count+=1
                if (count<2 or count>3) and board[i][j]==1:
                    turn[i][j]=0
                elif count==3 and board[i][j]==0:
                    turn[i][j]=1
        for i in range(m):
            for j in range(n):
                if turn[i][j]==0:
                    board[i][j]=0
                elif turn[i][j]==1:
                    board[i][j]=1
```

