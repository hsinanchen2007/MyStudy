
简单，四个方向，找到就计数，遇到象就跳过这个方向。

```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        
        x=[1,-1,0,0]
        y=[0,0,1,-1]
        
        self.res=0
        
        def find(row,col):
            for k in range(4):
                nx=row
                ny=col
                while 0<=nx<8 and 0<=ny<8:
                    if board[nx][ny]=='B':
                        break
                    if board[nx][ny]=='p':
                        self.res+=1
                        break
                    nx+=x[k]
                    ny+=y[k]
                
        
        for row in range(8):
            for col in range(8):
                if board[row][col]=="R":
                    find(row,col)
                    break
        
        return self.res
```
