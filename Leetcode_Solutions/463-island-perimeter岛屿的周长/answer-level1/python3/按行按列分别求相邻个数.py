### 解题思路
    #第一步，由于所有1相连，所以直接求1的个数作为有效1的个数
    #第二步，按行求相邻1的个数
    #第三步。按列求相邻1的个数
    #第四步，周长=4*有效1-2*（行相邻+列相邻）

### 代码

```python3
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
    #第一步，由于所有1相连，所以直接求1的个数作为有效1的个数
    #第二步，按行求相邻1的个数
    #第三步。按列求相邻1的个数
    #第四步，周长=4*有效1-2*（行相邻+列相邻）
        lenth=len(grid[0])
        width=len(grid)
        count_useable=0
        for i in grid:
            for m in i:
                if(m==1):
                    count_useable=count_useable+1
        count_row=0
        for i in grid:
            for m in range(lenth-1):
                z=m+1
                if(i[m]==1 and i[m]==i[z]):
                    count_row=count_row+1
        count_col=0
        for i in range(lenth):
            for m in range(width-1):
                z=m+1
                if(grid[m][i]==1 and grid[z][i]==grid[m][i]):
                    count_col=count_col+1
        zhouchang=count_useable*4-2*(count_col+count_row)
        return zhouchang
```