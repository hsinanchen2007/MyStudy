一个 grid 有 len(grid) 行， len(grid[0]) 列。

对于每个格子 grid[row][col]，如果值为 1，它的边长取决于它四周的情况。
在格子值为 1 的情况下，考虑四周情况如下：
如果格子处于 grid 的边缘，即若 row == 0 或 row == len(grid)-1 代表它的上边或下边要计入周长；若 col == 0 或 col == len(grid[0])-1 代表它的左边或右边要计入周长。
如果格子不处于 grid 的边缘，则若 grid[row-1][col] == 0 或 grid[row+1][col] == 0 代表它的上面或下面是湖，边需要计入周长；若 grid[row][col-1] == 0 或 grid[row][col+1] == 0 代表它的左面或右面是湖，边需要计入周长。

对所有格子遍历一次，可以得到 grid 的周长。

程序如下：

```
class Solution(object):
    def islandPerimeter(self, grid):
        rn = len(grid)
        cn = len(grid[0])
        r = 0
        for row in range(0, rn):
            for col in range(0, cn):
                if grid[row][col] == 1:
                    if row == 0:
                        r += 1
                    elif grid[row-1][col] == 0:
                        r += 1
                    if col == 0:
                        r += 1
                    elif grid[row][col-1] == 0:
                        r += 1
                    if row == rn-1:
                        r += 1
                    elif grid[row+1][col] == 0:
                        r += 1
                    if col == cn-1:
                        r += 1
                    elif grid[row][col+1] == 0:
                        r += 1
        return r
```
