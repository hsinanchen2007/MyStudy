第i，j位置的解肯定是从第i-1，j位置走过来 或者 从第i，j-1位置走过来。只要注意一下边界就好了

在原数组上进行操作可以减少内存消耗

```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n=len(grid)
        if n==0:
            return 0
        m=len(grid[0])
        for i in range(n):
            for j in range(m):
                if i==0 and j==0:
                    continue
                elif i==0 and j!=0:
                    grid[i][j]=grid[i][j-1]+grid[i][j]
                elif j==0 and i!=0:
                    grid[i][j]=grid[i-1][j]+grid[i][j]
                else:
                    grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j]
        return grid[n-1][m-1]
```

> 执行用时 :
92 ms
, 在所有Python3提交中击败了
31.05%
的用户


>内存消耗 :
14.4 MB
, 在所有Python3提交中击败了
81.13%
的用户