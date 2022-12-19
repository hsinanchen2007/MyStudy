### 解题思路
dfs遍历grid，找出每个岛并保存最大岛面积。

虽然这么写比较慢，但看起来爽啊。需要注意的是max(*[0])居然会报错，不知什么缘故。

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if grid==[]:
            return 0
        return max(*[max(*[island_scan(grid,i,j)\
                     for j in range(len(grid[0]))]+[0])\
                     for i in range(len(grid))]+[0])

def island_scan(l,i,j):
    if l[i][j]==0:
        return 0
    m,n=len(l),len(l[0])
    l[i][j]=0
    land_size=1+sum([island_scan(l,a,b) for a,b in 
                     filter(lambda x:0<=x[0]<m and 0<=x[1]<n and l[x[0]][x[1]]==1,
                            [(i-1,j),(i+1,j),(i,j-1),(i,j+1)])])
    return land_size
```