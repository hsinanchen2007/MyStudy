```java
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
            int[] top = top(grid);
            int[] left = left(grid);
            return increase(top,left,grid);
    }
    public int[] top(int[][] grid){
        int[] top = new int[grid.length];
        int max = 0;
        for (int j = 0; j < grid.length; ++j) {
            for (int i = 0; i < grid.length; ++i) {
                if (max < grid[i][j]) {
                    max = grid[i][j];
                }
            }
            top[j] = max;
            max = 0;
        }
        return top;
    }
    public int[] left(int[][] grid){
        int[] left = new int[grid.length];
        int max = 0;
        for (int j = 0; j < grid.length; ++j){
            for (int i = 0; i < grid.length; ++i){
                if (max < grid[j][i]){
                    max = grid[j][i];
                }
            }
            left[j] = max;
            max = 0;
        }
        return left;

    }
    public int increase(int[] top, int[] left, int[][]grid){
        int res = 0;
        int max = 0;
        for (int j = 0; j < grid.length; ++j){
            for (int i = 0; i < grid.length; ++i){
                int min = Math.min(left[j],top[i]);
                 res += min - grid[j][i];
            }
            left[j] = max;
            max = 0;
        }
        return res;
    }
}
```