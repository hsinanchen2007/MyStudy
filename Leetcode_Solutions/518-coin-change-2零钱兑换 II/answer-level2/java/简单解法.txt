递归：
```
public int change(int amount, int[] coins) {
    return process(coins, 0, amount);
}
    
public int process(int[] coins, int i, int rest) {
    if(rest == 0){
        return 1;
    }
    if(i == coins.length){
        return 0;
    }
    int bu = process(coins, i + 1,rest);
    int xuan = 0;
    if(rest >= coins[i]) {
        xuan = process(coins, i , rest - coins[i]);
    }
    return bu + xuan;   
}
```
二维数组
```
public int change(int amount, int[] coins) { 
    int rows = coins.length + 1;
    int cols = amount + 1;
    int[][] dp = new int[rows][cols];
    for(int i = rows - 1; i >= 0; i--){
        for(int j = 0; j < cols; j++){
            if(j == 0){ 
                dp[i][j] = 1;
            }else if(i == rows - 1) {
                dp[i][j] = 0;
            }else {
                //不用当前货币，只通过之前的几种货币能够组成当前amount的种数
                dp[i][j] = dp[i + 1][j];
                
                if(j - coins[i] >= 0) {
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }
        
    }
    return dp[0][amount];
}
```
空间复杂度优化：
```
public int change(int amount, int[] coins) {
        
    int rows = coins.length + 1;
    int cols = amount + 1;
    int[] dp = new int[cols];
    
    dp[0] = 1;
    for(int i = rows - 2; i >= 0; i--){
        for(int j = 0; j < cols; j++){ 
            if(j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
            }  
        }   
    }
    return dp[amount];
}
```

