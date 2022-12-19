### 解题思路
傻兮兮一大堆，按正常逻辑写出来的。 没用到啥算法，我感觉我错过了什么。。

1.遍历单位时间内会将要腐烂的橘子，坐标记-1
2.遍历，单位时间结束时，将-1正式记为2
3.若某个单位时间无新增腐烂，则结束
4.遍历，若还存在新鲜的，则返回-1
若都已腐烂，反馈消耗时间。


### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        time = 0
        row = len(grid)
        col = len(grid[0])
        flag = True
        while flag:
            for m in range(0, row):
                for n in range(0, col):
                    if grid[m][n] == 2:
                        if m - 1 >= 0 and grid[m - 1][n] == 1:
                            grid[m - 1][n] = -1
                        if n + 1 <= col-1 and grid[m][n + 1] == 1:
                            grid[m][n + 1] = -1
                        if m + 1 <= row-1 and grid[m + 1][n] == 1:
                            grid[m + 1][n] = -1
                        if n - 1 >= 0 and grid[m][n - 1] == 1:
                            grid[m][n - 1] = -1

            flag = False
            for m in range(0, row):
                for n in range(0, col):
                    if grid[m][n] == -1:
                        grid[m][n] = 2
                        flag = True
            if flag:
                time += 1
        #exsit 1 , return -1
        for m in range(0, row):
            for n in range(0, col):
                if grid[m][n] == 1:
                    return -1
        #else return the time
        return time


                


```