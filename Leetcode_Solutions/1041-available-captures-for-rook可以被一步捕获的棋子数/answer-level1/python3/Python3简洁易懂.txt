```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        r,c=0,0
        for i in range(8):
            for j in range(8):
                if board[i][j]=='R':
                    r,c=i,j
        count=0
        for xb,yb in [[0,1],[0,-1],[-1,0],[1,0]]:
            a,b=r,c
            while 0<=a<8 and 0<=b<8:
                if board[a][b] == 'p':
                    count+=1
                    break
                elif  board[a][b] in 'B':
                    break
                a+=xb
                b+=yb
        return count
```
