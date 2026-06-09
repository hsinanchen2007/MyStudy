```
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1 = len(s1)
        l2 = len(s2)
        l3 = len(s3)
        if l1 + l2 != l3:
            return False
        
        L = [[0] * (l2+1) for i in range(l1+1)]
        
        L[0][0] = 1
        
        for i in range(1, l1+1):
            if s1[i-1] == s3[i-1]:
                L[i][0] = 1
            else:
                break
        
        for i in range(1, l2+1):
            if s2[i-1] == s3[i-1]:
                L[0][i] = 1
            else:
                break
        
        for i in range(1, l1+1):
            for j in range(1, l2+1):
                equ1 = s3[i+j-1] == s1[i-1]
                equ2 = s3[i+j-1] == s2[j-1]
                if equ1 and not equ2:
                    L[i][j] = L[i-1][j]
                elif equ2 and not equ1:
                    L[i][j] = L[i][j-1]
                elif equ1 and equ2:
                    L[i][j] = L[i-1][j] or L[i][j-1]
                
                    
        return L[l1][l2]
```
