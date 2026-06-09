### 解题思路
最开始的思路是：把从上、右、前方看到的面积加起来再乘二就可以得到表面积。但是这样会忽略内陷的情况，就会少算一部分面积。

具体思路：
对于每个位置上的立方体：
1. 若大于0则贡献上下两个单位面积
2. 遍历四周，若高于旁边，则贡献高度差个单位面积，否则为0。对四个方向求和。

时间复杂度：O(N*N)
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        N = len(grid)
        result = 0

        for i in range(N):
            for j in range(N):
                
                if grid[i][j]:
                    result += 2
                    
                    for ii,jj in ((i,j+1), (i,j-1), (i+1,j), (i-1,j)):
                        if 0 <= ii < N and 0 <= jj < N:
                            diff = grid[i][j] - grid[ii][jj]
                        else:
                            diff = grid[i][j]
                        
                        result += max(diff, 0)

        return result    
```