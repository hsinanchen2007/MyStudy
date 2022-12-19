
```python []
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res=[[0]*n for _ in range(n)]
        dr=[0,1,0,-1]
        dc=[1,0,-1,0]
        seen=[[False]*n for _ in range(n)]
        r,c=0,0
        di=0
        for i in range(1,n**2+1):
            res[r][c]=i
            seen[r][c]=True
            cr=r+dr[di]
            cc=c+dc[di]
            if 0<=cr <n and 0<=cc <n and not seen[cr][cc]:
                    r=cr
                    c=cc
            else:
                    di=(di+1)%4
                    r=r+dr[di]
                    c=c+dc[di]
        return res
```



`