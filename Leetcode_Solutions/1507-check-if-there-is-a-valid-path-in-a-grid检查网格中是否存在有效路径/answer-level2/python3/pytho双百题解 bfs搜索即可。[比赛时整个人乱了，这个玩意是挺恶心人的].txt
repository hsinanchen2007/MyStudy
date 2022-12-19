### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        xf = [-1,0,+1,0]
        yf = [0, -1, 0, +1]
        dout = [[2,5,6],[1,3,5],[2,3,4],[1,4,6]]
        din = [[2,3,4],[1,4,6],[2,5,6],[1,3,5]]
        
        q = [(0,0,grid[0][0])]
        grid[0][0] = 0
        while len(q) > 0:
            x,y,d = q.pop()
            if x==len(grid) - 1 and y==len(grid[0])-1:
                return True
            # 四个方向检查
            for i in range(0, 4):
                if x+xf[i] >= 0 and x+xf[i] < len(grid) and y+yf[i] >= 0 and y+yf[i] < len(grid[0]) \
                and d in dout[i] and grid[x+xf[i]][y+yf[i]] in din[i]:
                    cur_x = x + xf[i]
                    cur_y = y + yf[i]
                    d = grid[cur_x][cur_y]
                    q.append((cur_x, cur_y, d))
                    grid[cur_x][cur_y] = 0 # 走过的不再走
        return False
```