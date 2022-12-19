### 解题思路
<与62/63不同路径>相似
动态规划或建立图来处理(需要建立顶点类/图类，建立图，再采用Dijkstra算法。比较繁琐)
使用动态规划：
#### 初始化/边界条件
grid[0][0]处不动
第一行为边界，只加左边元素
`grid[0][i]+=grid[0][i-1]`
第一列为边界，只加上面元素
`grid[j][0]+=grid[j-1][0]`
#### 遍历
遍历其余元素，转移方程：
`grid[i][j]=min(grid[i][j-1],grid[i-1,j])+grid[i][j]`
### 代码

```python3
#给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
#说明：每次只能向下或者向右移动一步。
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        #<与62/63不同路径>相似
        #动态规划或建立图来处理(需要建立顶点类/图类，建立图，再采用Dijkstra算法。比较繁琐)
        #二维动态规划
        m=len(grid)
        n=len(grid[0])
        #grid[0][0]处不动
        for i in range(1,n):#第一行为边界
            grid[0][i]+=grid[0][i-1]#只加左边元素
        for j in range(1,m):#第一列为边界
            grid[j][0]+=grid[j-1][0]#只加上面元素
        #遍历其余元素，转移方程：grid[i][j]=min(grid[i][j-1],grid[i-1,j])+grid[i][j]
        for i in range(1,m):
            for j in range(1,n):
                grid[i][j] += min(grid[i][j-1],grid[i-1][j])
        return grid[-1][-1]
                
                




                



```