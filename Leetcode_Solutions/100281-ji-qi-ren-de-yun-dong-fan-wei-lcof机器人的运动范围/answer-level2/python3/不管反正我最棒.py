```
def addDigits(num):
    newNum = 0
    for i in str(num):
        newNum += int(i)
    return newNum

def dfs(visited,x,y,k) -> int: 
    if x<0 or y<0 or x>=len(visited) or y>=len(visited[0]) or visited[x][y]==1:
        return 0
    n = addDigits(x) + addDigits(y)
    if n>k:
        return 0
    visited[x][y]=1
    cnt=1
    cnt+=dfs(visited,x+1,y,k)
    cnt+=dfs(visited,x-1,y,k)
    cnt+=dfs(visited,x,y+1,k)
    cnt+=dfs(visited,x,y-1,k)
    return cnt

class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        visited=[([0]*n) for i in range(m)]
        return dfs(visited,0,0,k)
```
