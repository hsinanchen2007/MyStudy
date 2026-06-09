### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        int r = grid.length;
        int c = grid[0].length;

        for(int i = 0; i<r; i++) {
            for(int j=0; j<c; j++) {
                    int area = 0;
                    if(grid[i][j] == 1) {
                        grid[i][j] = 0;

                        area = 1;
                        if(j<c-1 && grid[i][j+1] == 1) {
                            area += getArea(grid, i, j+1);
                        }
                        if(i<r-1 && grid[i+1][j] == 1) {
                            area += getArea(grid, i+1, j);
                        }

                        maxArea = Math.max(maxArea, area);

                    }
                }
        }

        return maxArea;
    }

    public int getArea(int[][] grid, int i, int j) {
        int area = 0; 
        int r = grid.length;
        int c = grid[0].length;

        if(grid[i][j] == 1) {
            grid[i][j] = 0; 
            area = 1;

            if(j<c-1 && grid[i][j+1] == 1) {
                area += getArea(grid, i, j+1);
            }
            if(i<r-1 && grid[i+1][j] == 1) {
                area += getArea(grid, i+1, j);
            }
            if(j>0 && grid[i][j-1] == 1) {
                area += getArea(grid, i, j-1);
            }
            if(i>0 && grid[i-1][j] == 1) {
                area += getArea(grid, i-1, j);
            }
        }
        
        return area;
    }
}
```