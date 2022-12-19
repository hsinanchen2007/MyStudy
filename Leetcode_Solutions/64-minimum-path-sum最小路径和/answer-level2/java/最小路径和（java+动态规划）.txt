class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;//行
        int n = grid[0].length;//列
        for(int i=1; i<m; i++){//初始化第一列
            grid[i][0] += grid[i-1][0];
        }
        for(int i=1; i<n; i++){//初始化第一行
            grid[0][i] += grid[0][i-1];
        }
        for(int i=1; i<m; i++){//在原数组进行动态规划：填格子，填上当前最小路径和
            for(int j=1; j<n; j++){
                grid[i][j] += Math.min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
}