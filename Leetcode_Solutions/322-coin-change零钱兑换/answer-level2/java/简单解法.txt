```
class Solution {
    //1.递归
    public int coinChange1(int[] coins, int amount) {
        return process(coins,0,amount);
    }

    public int process(int[] coins,int i,int rest){
        if(rest == 0) return 0;
        if(i == coins.length) return -1;  

        int bu = process(coins, i + 1, rest);
        int xuan = -1;
        if(coins[i] <= rest) {
            int sub = process(coins, i, rest - coins[i]);
            xuan =  sub == -1 ? -1 : sub + 1;
        }
        if(xuan != -1 && bu != -1) {
            return Math.min(xuan, bu);
        }
        return xuan == -1 ? bu : xuan;
    }

    //2.二维数组   
    public int coinChange2(int[] coins, int amount) {
        int rows = coins.length + 1;
        int cols = amount + 1;
        int[][] dp = new int[rows][cols];
        dp[rows - 1][0] = 0;
        for(int i = 1; i < cols; i++) {
            dp[rows - 1][i] = -1;
        }
        for(int i = rows - 2; i >= 0; i--) {
            
            for(int j = 0; j < cols; j++) {
                dp[i][j] = dp[i + 1][j];
                
                if(coins[i] <= j && dp[i][j - coins[i]] != -1) {
                    
                    if(dp[i][j] != -1) {
                        dp[i][j] = Math.min(dp[i][j],dp[i][j - coins[i]] + 1);
                    }else {
                        dp[i][j] = dp[i][j - coins[i]] + 1;
                    }
                    
                }
            }  
        }
        return dp[0][amount];
    }
    //3.空间优化
    public int coinChange(int[] coins, int amount) {
        int cols = amount + 1;
        int rows = coins.length + 1;
        int[] dp = new int[cols];
        dp[0] = 0;
        for(int i = 1; i < cols; i++) {
            dp[i] = -1;
        }
        for(int i = rows - 2; i >= 0; i--) {
            for(int j = 0; j < cols; j++) {
                if(coins[i] <= j && dp[j - coins[i]] != -1) {
                    if(dp[j] != -1) {
                        dp[j] = Math.min(dp[j],dp[j - coins[i]] + 1);
                    }else {
                        dp[j] = dp[j - coins[i]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }    
}
```
