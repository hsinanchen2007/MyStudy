先求出输入数组的大小m和n。然后先处理边界dp动态数组，最后覆盖所有的dp


class Solution {
    public int maxValue(int[][] grid) {
        if(grid==null){
            return -1;
        }
        int m=grid.length;
        int n=grid[0].length;
        int[][] dp=new int[m][n];
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int x=1;x<m;x++){
            for(int y=1;y<n;y++){
                dp[x][y]=grid[x][y]+Math.max(dp[x-1][y],dp[x][y-1]);
            }
        }
        return dp[m-1][n-1];
    }
}
