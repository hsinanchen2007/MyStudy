### 解题思路
1、初始化grid
2、遍历grid，if grid[i][j]==1: 使用搜索方法，搜寻四个方向上的连续1的长度，返回cur=depth
3、res=max(res,cur)

这样写完会超时，当N=500的时候，所以加了两个剪枝条件
1、边界处的直接判断是否为1
2、当ij的位置与边界的距离都小于目前的最优值，那么该位置肯定不会成为最优值，直接跳过。
![image.png](https://pic.leetcode-cn.com/7df5e6ef8ecdd98ec6c0a88c39118a74d9e77f551fe3fc441ccdb8c267aec914-image.png)

惊险通过。

### 代码

```python3
class Solution:
    def orderOfLargestPlusSign(self, N: int, mines: List[List[int]]) -> int:
        def dfs(grid,i,j):
            depth=1
            while i+depth<len(grid) and i-depth>=0 and j+depth<len(grid[0]) and j-depth>=0 and grid[i+depth][j]==1 and grid[i][j+depth]==1 and grid[i-depth][j] and grid[i][j-depth]==1:
                depth+=1
            return depth
    
        grid=[[1 for _ in range(N)] for _ in range(N)]
        for mine in mines:
            grid[mine[0]][mine[1]]=0
        res=0
        for i in range(N):
            for j in range(N):
                if (i==0 or  i==N-1 or j==0 or j==N-1) and grid[i][j]==1:
                    res=max(1,res)
                    continue
                if min([i+1,j+1,N-i,N-j])<=res:
                    continue
                if grid[i][j]==1:
                    cur=dfs(grid,i,j)
                    res=max(cur,res)
        return res
```