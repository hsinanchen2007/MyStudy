### 解题思路
分两种情况：
1.上下底面
上下底面比较特殊，只与格子的个数有关
2.除上下底面外的4个面
从不同的面去数，相邻的两个立方体有重叠，高加低减。首尾两个面都要加上。



### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:return 0
        #从不同的面去数，相邻的两个立方体，高加低减。上下底面比较特殊，只与格子的个数有关
        surfacei=0
        surfacej=0
        surfaceupdown=0
        n=len(grid)
        for i in range(n):
            tmpi=grid[i][0]
            if tmpi!=0:surfaceupdown+=1
            for j in range(n-1):
                tmpi+=abs(grid[i][j]-grid[i][j+1])
                if grid[i][j+1]!=0:
                    surfaceupdown+=1
            surfacei+=tmpi+grid[i][n-1]
        for j in range(n):
            tmpj=grid[0][j]
            for i in range(n-1):
                tmpj+=abs(grid[i][j]-grid[i+1][j])
            surfacej+=tmpj+grid[n-1][j]
        #print(surfacei,surfacej,surfaceupdown)
        return surfacei+surfacej+surfaceupdown*2
```