### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        int r = grid.length;
        int c = grid[0].length;
        int[][] flag = new int[r][c];

        for(int i = 0; i<r; i++) {
            for(int j=0; j<c; j++) {

                if(flag[i][j] == 1) {
                    continue;
                } else {
                    flag[i][j] = 1;
                    int area = 0;
                    if(grid[i][j] == 1) {
                        area = 1;

                        if(j<c-1 && flag[i][j+1] == 0) {
                            area += getArea(grid, flag, i, j+1);
                        }
                        if(i<r-1 && flag[i+1][j] == 0) {
                            area += getArea(grid, flag, i+1, j);
                        }

                    
                        maxArea = Math.max(maxArea, area);
                    }
                }
            }
        }

        return maxArea;
    }


    public int getArea(int[][] grid, int[][] flag, int i, int j) {
        int area = 0; 
        int r = grid.length;
        int c = grid[0].length;
        if(flag[i][j] == 1) {
            area = 0;
        } else {
            flag[i][j] = 1;

            if(grid[i][j] == 1) {
                area = 1;

                if(j<c-1 && flag[i][j+1] == 0) {
                    area += getArea(grid, flag, i, j+1);
                 }
                if(i<r-1 && flag[i+1][j] == 0) {
                    area += getArea(grid, flag, i+1, j);
                }
                if(j>0 && flag[i][j-1] == 0) {
                    area += getArea(grid, flag, i, j-1);
                }
                if(i>0 && flag[i-1][j] == 0) {
                    area += getArea(grid, flag, i-1, j);
                }
            }
        }

        return area;
    }
}
```