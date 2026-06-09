### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        moves = [(2, -1), (2, 1), (-2, -1), (-2, 1), (1, -2), (1, 2), (-1, -2), (-1, 2)]
        queue = [(0,0,0)]
        vistied = set()
        vistied.add((0,0))
        x,y= abs(x),abs(y)
        while queue:
            i,j,step =queue.pop(0)
            if i==x and j==y:
                return step
            for di,dj in moves:
                ni,nj = i+di,j+dj
                if -2<ni<x+3 and -2<nj<y+3 and (ni,nj) not in vistied:
                    vistied.add((ni,nj))
                    queue.append((ni,nj,step+1))
```