### 解题思路
三步：
1.所有柱体=上下底面2+侧面积*4
2.去掉i和i-1重合的2个面积
3.去掉j和j-1重合的2个面积
时间复杂度两层循环 O(N*N)   空间复杂度O(1)

### 代码

```python3
# python版本
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        area = 0 
        for i in range(n):
            for j in range(n):
                level = grid[i][j]
                if level>0:
                    area+=level*4+2
                    if i>0:
                        area-=min(grid[i][j],grid[i-1][j])*2
                    if j>0:
                        area-=min(grid[i][j],grid[i][j-1])*2
        return area
```
```
// java版本
class Solution {
    public int surfaceArea(int[][] grid){
        int n = grid.length;
        int area = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int level = grid[i][j];
                if(level>0){                
                area += (level*4)+2;
        // 每个主题=上下底面+正方体四个侧面积
                area -= i>0?Math.min(level,grid[i-1][j])*2:0;
        // 减去i与i-1的相贴表面积
                area -= j>0?Math.min(level,grid[i][j-1])*2:0;
        // 减去j和j-1相贴的表面积   （高的最小值）    
            }
            }
        }
        return area;
}
}
```
