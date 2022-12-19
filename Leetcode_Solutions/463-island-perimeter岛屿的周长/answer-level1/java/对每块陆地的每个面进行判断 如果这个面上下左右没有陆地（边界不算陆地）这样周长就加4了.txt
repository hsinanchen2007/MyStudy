class Solution {
    public int islandPerimeter(int[][] grid) {
        if(grid == null ||grid.length == 0) return 0;
        int count = 0;
        for (int i = 0 ; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    //对每块陆地的每个面进行判断 如果这个面上下左右没有陆地（边界不算陆地）这样周长就加4了
                    if (i == 0  || grid[i-1][j] != 1) {
                        count ++;
                    }
                    if (j == 0 || grid[i][j - 1] != 1) {
                        count ++;
                    }
                    if (i == (grid.length - 1) ||grid[i+1][j] != 1) {
                        count ++;
                    }
                    if (j == (grid[0].length -1) ||grid[i][j+1]!= 1) {
                        count ++;
                    }
                }
            }
        }
        return count;
    }
}