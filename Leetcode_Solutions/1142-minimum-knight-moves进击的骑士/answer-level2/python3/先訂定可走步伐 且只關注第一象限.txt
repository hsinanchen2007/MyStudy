### 解题思路
先設定可走步伐
且只關注第一象限 
產生一個 set 放置所有可能的種子位置
依序找尋 直到 到達目標位置

### 代码

```python3
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        choise = [(2,1),(1,2),(2,-1),(1,-2),(-2,-1),(-1,-2),(-2,1),(-1,2)]
        x, y = abs(x), abs(y)
        position = set()
        position.add((0,0))
        queue = [(0,0,0)]
        while queue:
            i,j,step = queue.pop(0)
            if i == x and j == y:
                res = step
                break           
            for di, dj in choise: 
                ni, nj = i+di, j+dj                   
                if -2<ni<x+3 and -2<nj<y+3 and (ni,nj) not in position:
                    position.add((ni,nj))
                    queue.append((ni,nj,step+1))

        return res            

```