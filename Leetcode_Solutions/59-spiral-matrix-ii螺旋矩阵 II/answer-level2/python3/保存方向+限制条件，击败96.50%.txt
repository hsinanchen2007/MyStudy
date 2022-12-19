```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[False] * n for i in range(n)]
        dr=[0,1,0,-1]
        dc=[1,0,-1,0]
        r=c=di=0
        for i in range(n*n):
            res[r][c]=i+1
            cr,cc=r+dr[di],c+dc[di]
            if(0<=cr<n and 0<=cc<n and not res[cr][cc]):
                r,c=cr,cc
            else:
                di=(di+1)%4
                r,c=r+dr[di],c+dc[di]
        return res
```
