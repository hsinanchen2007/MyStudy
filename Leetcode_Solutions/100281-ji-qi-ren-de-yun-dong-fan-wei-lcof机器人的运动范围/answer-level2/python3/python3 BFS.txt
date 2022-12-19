```
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        q = collections.deque([(0,0)])
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        visited=set()
        visited.add((0,0))
        res = 0
        while q:
            x,y = q.popleft()
            res+=1
            for dx,dy in dirs:
                nx,ny=x+dx,y+dy
                if self.is_valid(nx,ny,m,n,k,visited):
                    q.append((nx,ny))
                    visited.add((nx,ny))
        return res
    
    def is_valid(self,nx,ny,m,n,k,visited):
        return 0<=nx<m and 0<=ny<n and nx//10+nx%10+ny//10+ny%10<=k and (nx,ny) not in visited   
```
