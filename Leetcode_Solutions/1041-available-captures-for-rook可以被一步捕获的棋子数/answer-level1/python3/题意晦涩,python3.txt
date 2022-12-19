```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        directions=[(-1,0),(1,0),(0,1),(0,-1)]
        
        for i in range(8):
            for j in range(8):
                if board[i][j]=="R":
                    Rook=(i,j)
                    break
        res=0
        for i in range(4):
            x,y=Rook
            for j in range(8):
                new_x=x+directions[i][0]*j
                new_y=y+directions[i][1]*j
                if 0<=new_x<8 and 0<=new_y<8:
                    if board[new_x][new_y]=="p":
                        res+=1
                        break
                    elif board[new_x][new_y]=="B":
                        break
                else:
                    break
        return res

```
