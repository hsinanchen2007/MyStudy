### 解题思路
每个元素只考虑右边和下边，如果本元素是0，右或下有1，则本元素变为1，否则不改变，并且标记有未改变的海域以供重新循环一次；如果本元素是1，右或下有0，则将0变为2，防止重复计算；如果本元素是2，则将2变为1。循环一遍后如果有标记的未改变的海域，则重新循环一次。按理说我的思路没问题，但是不知为何卡在了第26个用例

### 代码

```python
class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        count,lenth = 0,len(grid)
        for i in grid:
            count += sum(i)
        if count == 0 or count == lenth**2: return -1
        r = 1
        while True:
            flag = 0
            for i in range(lenth):
                for j in range(lenth):
                    if grid[i][j] == 0:
                        if (i<lenth-1 and grid[i+1][j]==1) or (j<lenth-1 and grid[i][j+1]==1):
                            grid[i][j] = 1
                        else:
                            flag = 1
                    if grid[i][j] == 1:
                        if i<lenth-1 and grid[i+1][j]==0:
                            grid[i+1][j] = 2
                        if j<lenth-1 and grid[i][j+1]==0:
                            grid[i][j+1] = 2
                    if grid[i][j] == 2:
                        grid[i][j] = 1
            for i in range(lenth):
                print(grid[i])
            print(flag)
            # 如果还有海洋
            if  flag == 1:
                r += 1
            else:
                return r
```