```
#纸上画个图
#对于grid中的每个位置，先找出该位置上行与列上的最大值
#把该位置上的值变为两个最大值中较小者，其增量即为最大的增加量

class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        #先找出行列中的最大值
        h = []
        l = []
        for i in range(len(grid)):#寻找行最大
            m = 0
            for j in range(len(grid[0])):
                if grid[i][j]>=m:
                    m = grid[i][j]
            h.append(m)
        for i in range(len(grid[0])):#列最大
            k = 0
            for j in range(len(grid)):
                if grid[j][i]>=k:
                    k = grid[j][i]
            l.append(k)
        s =0
        for i in range(len(grid)):  #计算最大差值
            for j in range(len(grid[0])):
                g = min(h[i],l[j])
                s+=(g-grid[i][j])
        return s
```
