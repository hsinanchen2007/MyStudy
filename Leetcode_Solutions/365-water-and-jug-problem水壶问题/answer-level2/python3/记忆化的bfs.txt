### 解题思路
记忆化的bfs，考虑六种情况

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        q=[(0,0)]
        memo=set()
        while q:
            now=q.pop(0)
            if now in memo:
                continue
            nx,ny=now[0],now[1]
            if nx==z or ny==z or nx+ny==z:
                return True
            memo.add(now)
            q.append((x,ny))
            q.append((nx,y))
            q.append((0,ny))
            q.append((nx,0))
            q.append((nx-min(nx,y-ny),ny+min(nx,y-ny)))
            q.append((nx+min(ny,x-nx),ny-min(ny,x-nx)))
        return False
```