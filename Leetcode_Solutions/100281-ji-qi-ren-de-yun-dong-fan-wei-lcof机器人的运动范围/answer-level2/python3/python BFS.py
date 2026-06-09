BFS的简单题，套路就是，定义visited代表遍历过的结果；然后逐层按照四个方向进行遍历 (其实遍历向下，向右两个方向就够了)。
```
from collections import deque

class Solution:
    def check(self,x,y,m,n):
        if (x>=0 and x<m) and (y>=0 and y<n):
            return True
        return False

    def get_sum(self,x):
        res = 0
        while x > 0:
            res += x%10
            x = x//10
        return res

    def movingCount(self, m: int, n: int, k: int) -> int:
        # start
        q = deque()
        sx = 0
        sy = 0
        q.append((sx,sy,0))
        visited = set([(sx,sy)])

        res = 1
        while (len(q)>0):
            cnt = len(q)
            for _ in range(cnt):
                x,y,num = q.popleft()
                directions = [(-1,0),(1,0),(0,-1),(0,1)]
                for d in directions:
                    nx = x+d[0]
                    ny = y+d[1]
                    if self.check(nx,ny,m,n):
                        nnum = self.get_sum(nx) + self.get_sum(ny)
                        if (nx,ny) not in visited:
                            visited.add((nx,ny))
                            if nnum <= k:
                                q.append((nx,ny,nnum))
                                res += 1
        return res
                        
                
```
