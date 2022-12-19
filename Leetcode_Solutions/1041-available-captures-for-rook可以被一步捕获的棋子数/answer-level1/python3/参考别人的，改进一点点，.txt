
看了，各位的代码，收获较大，，写了出来，一点点改进 。

只是早早break 。36ms ,

`内联代码
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        
        #定位 车 
        booll=True
        for hang ,row in enumerate (board):
            for lie,v in enumerate (row):
                if v =="R":
                    booll=False
                    break
            if not booll :break
        
        #定位边界----四个方向-----------
        #up
        tt1 =hang-1
        res=0
        while tt1>-1:
            
            if board[tt1][lie] =="B":
                break
            elif board[tt1][lie] =="p":
                res+=1
                break
            #elif board[tt1][lie] ==".":
            tt1-=1  
        #down-------------------------------
        tt2=hang+1
        while tt2<8:
            if board[tt2][lie] =="B":
                break
            elif board[tt2][lie] =="p":
                res+=1
                break
            #elif board[tt2][lie] ==".":
            tt2+=1        
        #left---------------------------------
        left = lie-1
        while left >=0 :
            if board[hang][left] =="B" :
                break
            elif board[hang][left] =="p":
                res+=1
                break
            #elif board[hang][left] ==".":
            left-=1
        #right-------------------------------
        right =lie +1
        while right <8 :
            if board[hang][right] =="B" :
                break
            elif board[hang][right] =="p":
                res+=1
                break
            #elif board[hang][right] ==".":
            right+=1            

        #收货加起来，返回--------------------------
        return res`

