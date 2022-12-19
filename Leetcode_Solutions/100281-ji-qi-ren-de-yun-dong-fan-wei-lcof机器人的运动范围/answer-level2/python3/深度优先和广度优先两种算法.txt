广度优先



```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def bfs(i,j,count,mark):
            queue=list()
            queue.append([i,j])
            while queue:
                loc = queue.pop()
                i,j = loc[0],loc[1]
                if (mark[i][j]==0):
                    count = count+1
                    mark[i][j]=1
                    #print(f"i:{i}   j:{j}") 
                dx=[1,0]
                dy=[0,1]
                for ori in range(2):
                    newi = i + dx[ori]
                    newj = j + dy[ori]
                    tmp = newi//10+newi%10+newj//10+newj%10
                    if (0<=newi<m and 0<=newj<n and tmp<=k and mark[newi][newj]==0):
                        queue.append([newi,newj])
            return count
        mark = [ [0] * n for i in range(m)]
        return bfs(0,0,0,mark)

```
深度优先
```
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def dfs(i,j,count,mark):
            if i>=m or j>=n:
                return count
            mark[i][j]=1
            tmp = (i+1)//10+(i+1)%10+j//10+j%10    
            if tmp<=k and i<m-1 and mark[i+1][j]==0 :
                count = dfs(i+1,j,count+1,mark)
            tmp = i//10+i%10+(j+1)//10+(j+1)%10
            if tmp<=k and j<n-1 and mark[i][j+1]==0 :
                count = dfs(i,j+1,count+1,mark)
            
            return count
        mark=[[0]*n for i in range(m)]
        return dfs(0,0,1,mark)
```
