### 解题思路
思路比较简单：看代码注释吧

### 代码

```python3
class Solution(object):
    def surfaceArea(self, grid):
        total_surface = 0
        l = len(grid)
        #每次遍历一个方格：
        for i in range(0,l):
            for j in range(0,l):
                #计算该方格内的所有立方体 在不跟其他方格干扰的情况下 的表面积
                p = grid[i][j]
                total_surface += p*6-(p-1)*2 if p>0 else 0
                #减去该方格的立方体 跟周围方格的立方体 的重叠面数
                    #这里用了小技巧，比较繁琐的是上下左右的grid都算一遍
                    #但实际上，只需要计算 [i,j]方格 的 [i,j+1]右侧和[i+1,j]下侧的方格的立方体重叠面数乘以2就行。
                    #因为重叠是相互的！！！
                    #焗个栗子：[1,1]和[1,2]的重叠数 与 [1,2]和[1,1]的重叠数 是一样的
                    #所以上下左右四个周围方格，选两个方向的再乘2就行。
                    #重叠数的计算也不难，两个相邻方格的最小值乘2就是重叠面数了。
                total_surface -= min(p,grid[i+1][j])*2 if i+1<l else 0
                total_surface -= min(p,grid[i][j+1])*2 if j+1<l else 0
        return total_surface
```