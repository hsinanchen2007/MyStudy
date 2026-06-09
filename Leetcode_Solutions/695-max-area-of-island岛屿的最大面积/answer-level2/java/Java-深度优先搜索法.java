### 解题思路
借鉴官方题解和精选题解

### 代码

```java
class Solution {
    /**
     * 求岛屿的最大面积，深度优先搜索法
     * https://leetcode-cn.com/problems/max-area-of-island/
     * @param grid
     * @author Geyuxuan 2020-03-15 21:55:26
     * @return int
     */
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == 1){
                    int area = getArea(grid,i,j);
                    maxArea = maxArea > area ? maxArea : area;
                }
            }
        }
        return maxArea;
    }

    private int getArea(int[][] grid, int i, int j) {
        if(i == grid.length || i < 0){
            return 0;
        }else if(j == grid[0].length || j<0){
            return 0;
        }
        if(grid[i][j] == 1){
            grid[i][j] = 0;
            return 1+getArea(grid,i+1,j)+getArea(grid,i-1,j)+getArea(grid,i,j+1)+getArea(grid, i, j-1);
        }
        return 0;
    }
}
```