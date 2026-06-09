class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        res=0
        for i in range(8): #i是横坐标
            try:
                t=board[i].index('R') #t是纵坐标
                break
            except:
                continue
        for left in range(t-1):#找左边
            if board[i][t-left-1] =='p':
                res+=1
                break
            if board[i][t-left-1] =='B':
                break
        for right in range(t,7,1):#找右边
            if board[i][right+1] =='p':
                res+=1
                break
            if board[i][right+1] =='B':
                break
        for up in range(i-1): #找上面
            if board[i-1-up][t] =='p':
                res+=1
                break
            if board[i-1-up][t] =='B':
                break
        for down in range(i,7,1):#找下面
            if board[down+1][t] =='p':
                res+=1
                break
            if board[down+1][t] =='B':
                break        
        return res
                
                
        
        
