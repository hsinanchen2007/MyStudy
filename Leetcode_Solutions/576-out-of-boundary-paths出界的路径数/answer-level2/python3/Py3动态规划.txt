
```
class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        map=[[0]*(n+2) for _ in range(m+2)]
        temp=[[0]*(n+2) for _ in range(m+2)]
        temp[i+1][j+1]=1
        res=0
        if(N==0):
            return 0
        if(i==0):
            res+=1
        if(i==m-1):
            res+=1
        if(j==0):
            res+=1
        if(j==n-1):
            res+=1
        while(N):
            N-=1
            map = [[0] * (n + 2) for _ in range(m + 2)]
            for x in range(1,m+1):
                for y in range(1,n+1):
                    map[x][y]=temp[x-1][y]+temp[x+1][y]+temp[x][y+1]+temp[x][y-1]
                    map[x][y]%=(10 * * 9+7)
                    if(N):
                        if(x==1):
                            res+=map[x][y]
                        if(x==m):
                            res += map[x][y]
                        if(y==1):
                            res+=map[x][y]
                        if(y==n):
                            res += map[x][y]
                        res%=(10 * * 9+7)
            temp=map.copy()
        return res
```

