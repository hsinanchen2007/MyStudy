class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] up = new int[grid[0].length];
        int[] left = new int[grid.length];
        for(int col = 0; col < grid[0].length; ++ col) {
            int max = grid[0][col];
            for(int row = 1; row < grid.length; ++ row) {
                max = Math.max(grid[row][col], max);
            }
            up[col] = max;
        }

        for(int row = 0; row < grid[0].length; ++ row) {
            int max = grid[row][0];
            for(int col = 1; col < grid[0].length; ++ col) {
                max = Math.max(grid[row][col], max);
            }
            left[row] = max;
        }

        int res = 0;
        for(int row = 0; row < grid.length; ++ row) {
            for(int col = 0; col < grid[0].length; ++ col) {
                res += Math.abs(Math.min(up[col], left[row]) - grid[row][col]);
            }
        } 
        return res;
    } 
}