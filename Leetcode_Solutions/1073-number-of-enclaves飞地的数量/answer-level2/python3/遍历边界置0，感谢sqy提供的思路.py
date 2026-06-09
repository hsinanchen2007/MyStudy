### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        m = len(A)
        n = len(A[0])
        dire = [(0,1),(0,-1),(1,0),(-1,0)]
        def dfs(i,j):
            A[i][j]=0
            for di,dj in dire:
                ni, nj = i+di,j+dj
                if 0<=ni<m and 0<=nj< n and A[ni][nj]==1:
                    dfs(ni,nj)
        
        for i in range(m):
            for j in [0,n-1]:
                if A[i][j]==1:
                    dfs(i,j)
        for j in range(n):
            for i in [0,m-1]:
                if A[i][j]==1:
                    dfs(i,j)
        
        return sum([sum(A[i]) for i in range(m) ])
```