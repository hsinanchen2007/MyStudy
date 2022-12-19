### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        marked = [[0]*n for _ in range(m)]
        self.res = 0
        def dfs(i,j,marked):
            if 0<=i<m and 0<=j<n and marked[i][j]==0:
                tmp=0
                for c in str(i):
                    tmp += int(c)
                for c in str(j):
                    tmp += int(c)

                if tmp <=k:                
                    dr = [(0,1),(0,-1),(1,0),(-1,0)]
                    self.res+=1
                    for d in dr:
                        marked[i][j]=1
                        dfs(i+d[0],j+d[1],marked)
                        # marked[i][j]=0
                        
        dfs(0,0,marked)
        # print(self.res)
        return self.res
        
        
        
        
        
        
        
        
```