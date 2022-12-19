### 解题思路
整体思路：
先算一束溜的表面积，正如代码计算的第一句
然后再排除重复的表面积，则是看相邻两个柱，看谁低，然后高度<<2

大一老师现在让学java，但上半学期学的C语言感觉蛮有意思的，c语言也借鉴别人思路实现了
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length, area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 先把grid[i][j]赋值给level，省掉了bound check，可以略微略微略微优化一下耗时。。。
                int level = grid[i][j];
                if (level > 0) {
                    // 一个柱体中：2个底面 + 所有的正方体都贡献了4个侧表面积 
                    area += (level << 2) + 2;
                    // 减掉 i 与 i-1 相贴的两份表面积
                    area -= i > 0? Math.min(level, grid[i - 1][j]) << 1: 0; 
                    // 减掉 j 与 j-1 相贴的两份表面积
                    area -= j > 0? Math.min(level, grid[i][j - 1]) << 1: 0;
                }  
            }
        }
        return area;
    }
}



//c语言实现
int surfaceArea(int** grid, int gridSize, int* gridColSize){
int res = 0;
int row = gridSize;
int col = *gridColSize;
for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        if (grid[i][j] > 0) {
            res += (grid[i][j] * 4 + 2);
             
        }
         if (i - 1 >= 0 && grid[i - 1][j] > 0) {
                res -= grid[i - 1][j] < grid[i][j] ? grid[i - 1][j] : grid[i][j];
            }
            
            if (i + 1 < row && grid[i + 1][j] > 0) {
                res -= grid[i + 1][j] < grid[i][j] ? grid[i + 1][j] : grid[i][j];
            }
            if (j - 1 >= 0 && grid[i][j - 1] > 0) {
                res -= grid[i][j - 1] < grid[i][j] ? grid[i][j- 1] : grid[i][j];
            }
            if (j + 1 < col && grid[i][j + 1] > 0) {
                res -= grid[i][j + 1] < grid[i][j] ? grid[i][j + 1] : grid[i][j];
            }  
        
    }
}
return res;
}
