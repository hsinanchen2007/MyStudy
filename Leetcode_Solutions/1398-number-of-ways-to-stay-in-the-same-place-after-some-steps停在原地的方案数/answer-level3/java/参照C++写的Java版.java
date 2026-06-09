
```
class Solution {
    public int numWays(int steps, int arrLen) {
        final int MOD = (int)1e9 + 7;
        long[][] dp = new long[steps+1][steps+1];
        dp[0][0] = 1;
        for(int i = 1; i <= steps; i++){
            for(int j = 0; j < i && j < arrLen; j++){
                for(int d = -1; d <= 1; d++){
                    //前i-1步走到了j，所以j < i，第i步走到j+d
                    if(j+d >= 0 && j+d < arrLen){
                        dp[i][j+d] += dp[i-1][j];
                        dp[i][j+d] %= MOD;
                    }
                }
            }
        }
        return (int)dp[steps][0];
    }
}
```
