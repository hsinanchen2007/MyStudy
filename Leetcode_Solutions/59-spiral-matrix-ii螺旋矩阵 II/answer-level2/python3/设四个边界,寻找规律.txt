```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        r=n-1
        b=n-1
        l=0
        t=0
        c=1
        res=[[0]*n for i in range(n)]
        while c<=n*n:
            for i in range(l,r+1):
                res[t][i]=c
                c+=1
            t+=1
            for i in range(t,b+1):
                res[i][r]=c
                c+=1
            r-=1
            for i in range(r,l-1,-1):
                res[b][i]=c
                c+=1
            b-=1
            for i in range(b,t-1,-1):
                res[i][l]=c
                c+=1
            l+=1
        return res
```
