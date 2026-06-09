 先上代码
```
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        raw=len(grid)
        coloum=len(grid[0])
        Best=[[0 for _ in range(coloum)]for _ in range(raw)]
        Best[0][0]=grid[0][0]
        for m in range(1,coloum):
            Best[0][m] = Best[0][m-1] + grid[0][m]
        for n in range(1,raw):
            Best[n][0] = Best[n-1][0] + grid[n][0]
        for i in range(1,raw):
            for j in range(1,coloum):
                Best[i][j]=max(Best[i-1][j],Best[i][j-1])+grid[i][j]
        return Best[raw-1][coloum-1]

```
基本思路：对于1行n列和n行1列的子问题，只需累加即可得到最大价值。用Best矩阵存储其对应的最大价值，对于grid[i][j]，在Best[i-1][j]和Best[i][j-1]中取最大值，再加上grid[i][j]即可。