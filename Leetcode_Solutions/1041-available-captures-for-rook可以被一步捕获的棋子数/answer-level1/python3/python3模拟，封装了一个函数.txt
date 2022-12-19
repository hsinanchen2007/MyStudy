模拟行为
```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    L1 = i
                    L2 = j
        L_switch = [1,-1]
        def switch(A,B):
            collide_p1 = 0
            for j in range(2):    
                for i in range(8):
                    A = A + L_switch[j]
                    if  A>=8 or A < 0 or board[A][B] == 'B':
                        break
                    if board[A][B] == 'p':
                        collide_p1 += 1
                        break
            return collide_p1
        L_switch = [1,-1]
        def rswitch(A,B):
            collide_p2 = 0    
            for j in range(2):
                for i in range(8):
                    A = A + L_switch[j]
                    if  A>=8 or A < 0 or board[B][A] == 'B':
                        break
                    if board[B][A] == 'p':
                        collide_p2 += 1
                        break
            return collide_p2
            
        summ = switch(L1,L2) + rswitch(L2,L1)
        return summ

    


            

        
```
