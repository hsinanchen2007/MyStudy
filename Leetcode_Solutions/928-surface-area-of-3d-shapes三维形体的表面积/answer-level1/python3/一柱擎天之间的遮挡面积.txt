### 解法
首先假设在每个位置上的立方体都是一柱擎天的堆放，并且相邻的位置之间没有遮挡，那么k个立方体累起来面积大小，（**特别说明，k = 0的时候该公式不适用，直接为0.**）：
$$ 4*k+2 \qquad  if \quad  k > 0 $$


然后，我们再计算出，每个位置上被前后左右遮挡了多少面积。
1. 如果右边没有方块，那么遮挡面积就是0；
2. 如果右边方块比自己低，那么遮挡面积就是右边方块的高度；
3. 如果右边方块比自己高，那么遮挡面积就是自己的高度。
4. 特别注意，在边界的方块不要越界。

### 代码
```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        totalArea = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                initArea = 4*grid[i][j] +2 if grid[i][j] > 0 else 0
                shadowArea = self.shadowArea(grid, i ,j)
                totalArea += initArea - shadowArea
        return totalArea

    def shadowArea(self, grid, i, j):
        left = 0 if j == 0 else grid[i][j-1] if grid[i][j-1] < grid[i][j] else grid[i][j]
        right = 0 if j == len(grid[0])-1 else grid[i][j+1] if grid[i][j+1] < grid[i][j] else grid[i][j]

        up = 0 if i == 0 else grid[i-1][j] if grid[i-1][j] < grid[i][j] else grid[i][j]
        down = 0 if i == len(grid)-1 else grid[i+1][j] if grid[i+1][j] < grid[i][j] else grid[i][j]
        # print(i,j,left,right,up,down)
        return left+ right + up + down
```

### 抽象草稿

接下来是灵魂画手时间：
 ![image.png](https://pic.leetcode-cn.com/46936f4d704866eda48878a9b67fccb7e2505270a4691e752942713f2305524b-image.png)

