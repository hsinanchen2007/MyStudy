```
class Solution {
    public int countVowelPermutation(int n) {
        if(n <= 0)
            return 0;
        long[][] dp = new long[n][5];
        //a->0  ,  e->1,  i->2,  o->3,  u->4
        for(int i = 0;i < 5;i++)
            dp[0][i] = 1L;
        int mod = (int)Math.pow(10,9) + 7;
        
        for(int i = 1;i < n;i++){
            //a前面可能为e,i,u
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            //e前面可能为a,i
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            //i前面可能为e,o
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            //o前面可能为i,
            dp[i][3] = dp[i - 1][2];
            //u前面可能为i,o
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        
        int res = 0;
        for(int i = 0;i < 5;i++){
            res += dp[n - 1][i];
            res %= mod;
        }
        
        return res;
        
    }
    
}
```
