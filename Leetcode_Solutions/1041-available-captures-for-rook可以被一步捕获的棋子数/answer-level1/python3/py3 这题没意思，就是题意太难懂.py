```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        der=[[0,1],[1,0],[0,-1],[-1,0]]

        result=0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]=='R':
                    for d in der:
                        x=i+d[0]
                        y=j+d[1]
                        while 0<=x<len(board) and 0<=y<len(board[0]):
                            if board[x][y]=='p':
                                result+=1
                                break
                            elif board[x][y]=='B':
                                break
                            else:
                                x+=d[0]
                                y+=d[1]
                    break
        
        return result
                    
            


```
