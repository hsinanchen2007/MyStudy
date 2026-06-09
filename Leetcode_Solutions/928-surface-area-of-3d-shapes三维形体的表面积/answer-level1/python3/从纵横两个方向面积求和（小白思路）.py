很简单的思路，不需要考虑四个方向
只需要考虑行和列，每行/列（除最外侧的四个面）的侧面积增加量为两行立方体的高度差，累计求和，最后加上最外侧六个方向的面积

```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        zero,sum2,sum1,sum3 = 0,0,0,0
        for i in range(0,n):
            sum3 += grid[0][i] + grid[i][0] + grid[n-1][i] + grid[i][n-1] #外层侧面积
            for j in range(0,n):
                if grid[i][j]==0: 
                    zero +=1 #搜集空格点
                if i >0:
                    sum1 += abs(grid[i][j]-grid[i-1][j]) #纵向侧面积
                if j >0:
                    sum2 += abs(grid[i][j]-grid[i][j-1]) #横向侧面积
        sum4 = 2*(n*n-zero) #两个底面积
        return sum1 + sum2 + sum3 + sum4
```