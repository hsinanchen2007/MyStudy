看懂题目后，就想求新矩阵然后求差。感觉是最容易想到的求法。
注意到这是个方阵，所以把数组的长度提出来作为常数了。

1.直接求出需要的最大水平数组horizon和最大垂直数组vertical
2.grid[i][j]每个位置对应的horizon[i]和vertical[j]两个数组的最小值，就是此处应该得到的最大值
3.然后grid[i][j]和 min(horizon[i],vertical[j])求差，再累加一起求和即可。
4.两次O(n)的循环,速度还是比较慢，比较容易想。

```
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        lenth=len(grid)
        horizon=[max(grid[i]) for i in range(lenth)]
        vertical=[max(grid[i][j] for i in range(lenth)) for j in range(lenth)]

        res=0
        for i in range(lenth):
            for j in range(lenth):
                maxTerm = min(horizon[i],vertical[j])
                res+= maxTerm-grid[i][j]
        return res
```
