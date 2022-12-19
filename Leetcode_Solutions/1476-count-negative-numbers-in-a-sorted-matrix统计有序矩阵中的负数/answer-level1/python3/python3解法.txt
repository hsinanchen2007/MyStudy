解题思路：
因为矩阵非递增，所有我们只要在查找到负数时，
用矩阵的列数n减去当前查找到的负数所在的列数j，
并跳出此次列循环
代码：
```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        neg = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(0,m):
            for j in range(0,n):
                if grid[i][j] < 0:
                    neg = neg + (n-j)
                    break
        return neg
```
