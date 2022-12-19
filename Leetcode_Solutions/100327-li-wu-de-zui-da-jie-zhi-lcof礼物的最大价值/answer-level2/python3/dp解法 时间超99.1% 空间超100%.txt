### 解题思路
对于这类问题，我们可以简称为dp二维矩阵问题，对于这类问题，均有相关通式：
dp[i][j]=max/min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j])
基本状态转移方程均类似，该式的含义为要得到dp[i][j]，每次均为两种情况，可以向下或向右，向右的话就是上一dp状态dp[i][j-1]+grid的当前值，向下的话类似。所以可以写出动态规划部分代码for循环加转移方程：
        for i in range(1,len(grid)):
            for j in range(1,len(grid[0])):
                dp[i][j]=max(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j])
这里需要注意dp二维矩阵的构建，因为只有一行或者一列时，最大取值即为该行或该列的所有值相加，所有在构建dp矩阵时可以先从第一行和第一列入手，对应代码为：
        begin=[grid[0][0]]
        for i in range(1,len(grid[0])):
            begin.append(grid[0][i]+begin[i-1])
        dp=[]
        dp.append(begin)
        mid=[grid[0][0]+grid[1][0]]
        for j in range(1,len(grid)-1):
            mid.append(grid[j+1][0]+mid[j-1])
        for n in mid:
            dp.append([n]+[0]*(len(grid[0])-1))
上边两部分进行组合，就是通用的dp解题套路，另外需要注意一些特例，即原来二维矩阵只有一行的情况下，mid=[grid[0][0]+grid[1][0]]的index会超范围，所以需要加if判断特例，即：
        if len(grid)==1:return sum(grid[0])
因为矩阵长度大于0，所以不用考虑空矩阵。

### 代码
```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if len(grid)==1:return sum(grid[0])
        begin=[grid[0][0]]
        for i in range(1,len(grid[0])):
            begin.append(grid[0][i]+begin[i-1])
        dp=[]
        dp.append(begin)
        mid=[grid[0][0]+grid[1][0]]
        for j in range(1,len(grid)-1):
            mid.append(grid[j+1][0]+mid[j-1])
        for n in mid:
            dp.append([n]+[0]*(len(grid[0])-1))
        for i in range(1,len(grid)):
            for j in range(1,len(grid[0])):
                dp[i][j]=max(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j])
        return dp[-1][-1]


```![力扣 dp.png](https://pic.leetcode-cn.com/55275da9eefc8363e91e0550713f3283dde12d2f5c55298a95b63966328afbe7-%E5%8A%9B%E6%89%A3%20dp.png)
