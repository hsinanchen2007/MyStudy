```
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        int ans = 0;
        if(grid.length ==0 || grid[0].length==0)
            return ans;
        
        int[][][] dp = new int[grid.length+2][grid[0].length+2][4];
        int p,q;
        for(int i=0;i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j]=='E'){
                    dp[i+1][j+1][0] = dp[i][j+1][0]+1;
                    dp[i+1][j+1][1] = dp[i+1][j][1]+1;
                }else if(grid[i][j]=='W'){
                    dp[i+1][j+1][0] = 0;
                    dp[i+1][j+1][1] = 0;
                }else{
                    dp[i+1][j+1][0] = dp[i][j+1][0];
                    dp[i+1][j+1][1] = dp[i+1][j][1];
                }

                p = grid.length-i-1;
                q = grid[0].length-j-1;
                if(grid[p][q]=='E'){
                    dp[p+1][q+1][2] = dp[p+2][q+1][2]+1;
                    dp[p+1][q+1][3] = dp[p+1][q+2][3]+1;
                }else if(grid[p][q]=='W'){
                    dp[p+1][q+1][2] = 0;
                    dp[p+1][q+1][3] = 0;
                }else{
                    dp[p+1][q+1][2] = dp[p+2][q+1][2];
                    dp[p+1][q+1][3] = dp[p+1][q+2][3];
                }

            }
        }

        for(int i=0;i<grid.length; i++)
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j]=='0'){
                    ans = Math.max(ans, dp[i+1][j+1][0]+dp[i+1][j+1][1]+dp[i+1][j+1][2]+dp[i+1][j+1][3]);
                }
            }
        return ans;
    }

}
```


动态规划：
dp为分别记录每个点朝四个方向走到尽头(或碰到墙)所遇到的敌人总数

实际上需要走两遍dp，
一遍从上至下，从左往右，记录每个坐标向上，向左延伸能碰到几个敌人
一遍从下至上，从右往左，记录每个坐标向下，向右延伸能碰到几个敌人

最后把是‘0’的坐标的记录的四个方向的值加起来，找最大值即可
