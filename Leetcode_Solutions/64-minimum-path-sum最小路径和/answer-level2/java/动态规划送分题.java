

class Solution {
     public int minPathSum(int[][] grid) {
        int row_num = grid.length;
        int col_num = grid[0].length;
        int[][]grid_sum = new int[row_num][col_num];

        grid_sum[0][0] = grid[0][0];

        for (int i=1;i <col_num;i++) {
            grid_sum[0][i] = grid_sum[0][i-1] + grid[0][i];
        }

        for (int i=1;i <row_num;i++) {
            grid_sum[i][0] = grid_sum[i-1][0] + grid[i][0];
        }

        for (int i=1;i < row_num;i++) {
            for (int j=1;j<col_num;j++) {
                    grid_sum[i][j] = grid[i][j] + Math.min(grid_sum[i][j-1],grid_sum[i-1][j]);
                }
        }
        return grid_sum[row_num-1][col_num-1];
    }

}`