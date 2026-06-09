### 解题思路
遍历，一个位置上如果有立方体，那么上下面肯定有，侧面取决于其临近柱子的高度，超出边界的高度可以看作是0
逐个增加即可

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] > 0:
                    ans += 2
                    for r,c in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
                        if r < 0 or r > n-1 or c<0 or c > n-1:
                            compare = 0
                        else:
                            compare = grid[r][c]
                        
                        ans += max(grid[i][j] - compare,0)
        
        return ans 
                
                    
```