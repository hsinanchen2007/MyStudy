class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        if(dungeon.length==0){
            return 0;
        }
        int m=dungeon.length;
        int n=dungeon[0].length;
        int[][] dp=new int[m][n];
        dp[m-1][n-1]=Math.max(1,1-dungeon[m-1][n-1]);
        for(int i=n-2;i>=0;i--){
            if(dungeon[m-1][i]>=dp[m-1][i+1]){
                 dp[m-1][i]=1;
            }else{
                dp[m-1][i]=dp[m-1][i+1]-dungeon[m-1][i];
            }
            
        }
        for(int i=m-2;i>=0;i--){
            if(dungeon[i][n-1]>=dp[i+1][n-1]){
                dp[i][n-1]=1;
            }else{
                dp[i][n-1]=dp[i+1][n-1]-dungeon[i][n-1];
            }
            
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(dungeon[i][j]>=dp[i+1][j]||dungeon[i][j]>=dp[i][j+1]){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=Math.min(dp[i+1][j]-dungeon[i][j],dp[i][j+1]-dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
 }


![image.png](https://pic.leetcode-cn.com/a39f1c8aa9c0ce910a6b35a9585cab03ecf0ea0223b600a966410bf8c8ef2ad6-image.png)
状态：dp[i][j] 当前格子所需要的最少健康值
状态转移方程：当 当前格子的dungeon大于等于 右方和下方时最少健康值(dp)时，当前格子的dp值等于1
 dp[i][j]=Math.min(dp[i+1][j]-dungeon[i][j],dp[i][j+1]-dungeon[i][j])
输出：dp[0][0]
欢迎大佬们进行优化

