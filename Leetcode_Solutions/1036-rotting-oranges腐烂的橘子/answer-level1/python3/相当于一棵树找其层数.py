### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def orangesRotting(self,grid) -> int:
        spend_time = 0
        good_it = []
        bad_it = []
        col = len(grid)
        li = len(grid[0])
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    good_it.append((i, j))
                elif grid[i][j] == 2:
                    bad_it.append((i, j,0))
        while len(bad_it) > 0:
            x = bad_it[0][0]
            y = bad_it[0][1]
            h = bad_it[0][2]
            c = 0
            if x - 1 >= 0 and (x - 1, y) in good_it:
                good_it.remove((x - 1, y))
                bad_it.append((x - 1, y,h+1))
                c +=1
            if x + 1 < col and (x + 1, y) in good_it:
                good_it.remove((x + 1, y))
                bad_it.append((x + 1, y,h+1))
                c +=1
            if y - 1 >= 0 and (x, y - 1) in good_it:
                good_it.remove((x, y - 1))
                bad_it.append((x,y-1,h+1))
                c+=1
            if y + 1 < li and (x, y + 1) in good_it:
                good_it.remove((x, y + 1))
                bad_it.append((x,y+1,h+1))
                c+=1
            bad_it.pop(0)
            if c != 0:
                spend_time = max(spend_time,h+1)
        if len(good_it) > 0:
            return -1
        return spend_time     
```