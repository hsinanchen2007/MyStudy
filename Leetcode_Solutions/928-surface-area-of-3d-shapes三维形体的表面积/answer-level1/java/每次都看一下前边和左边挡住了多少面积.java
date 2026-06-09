class Solution {
    public int surfaceArea(int[][] grid) {
        int sum = 0;
        for (int i  = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                int  high = grid[i][j];
                if(high > 0)
                    sum += 6 * high - 2* (high -1);
                if (j -1 >= 0){
                    sum -= Math.min(grid[i][j-1], high) * 2;
                }
                if(i - 1 >= 0){
                    sum -= Math.min(grid[i-1][j], high) * 2;
                }
            }
        }

        return sum;
    }
}