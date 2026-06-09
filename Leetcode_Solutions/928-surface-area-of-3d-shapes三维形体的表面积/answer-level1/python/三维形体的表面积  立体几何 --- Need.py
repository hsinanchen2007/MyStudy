### 解题思路
1. 方法一：做加法的思路 
    - 将单元格 (i, j) 上堆叠的 v 个正方体分别计算表面积
    - 首先，v > 0 的话，柱子顶部、底部的表面积都是 1。

    - 然后是上、下、左、右四个侧面的表面积
    
2. 方法二：做减法的思路 
    - 我认为这个方法更加巧妙，我们先计算全部的表面积，然后再减去重叠的部分
    - 自身重叠 + 与前面j-1 和 与左面i-1

### 代码

```python3
## 加法
class Solution(object):
    def surfaceArea(self, grid):
        N = len(grid)

        ans = 0
        for r in range(N):
            for c in range(N):
                if grid[r][c]:
                    ans += 2
                    for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r,c+1)):
                        if 0 <= nr < N and 0 <= nc < N:
                            nval = grid[nr][nc]
                        else:
                            nval = 0

                        ans += max(grid[r][c] - nval, 0)

        return ans

## 减法
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n, face = 0, 0
        nsize = len(grid)
        if nsize < 1:
            return 0
        msize = len(grid[0])
        if msize < 1:
            return 0
        
        for i in range(nsize):
            for j in range(msize):
                cur = grid[i][j]
                n += cur ## 计数
                if grid[i][j] > 0:
                    face += cur -1  ## 自身重合
                
                if i-1 >= 0 and grid[i-1][j] > 0:
                    face += min(cur, grid[i-1][j]) ## 左侧重合数目
                if j-1 >= 0 and grid[i][j-1] > 0:
                    face += min(cur, grid[i][j-1])  ## 前侧重合数组
        
        return n*6 - face * 2 
```