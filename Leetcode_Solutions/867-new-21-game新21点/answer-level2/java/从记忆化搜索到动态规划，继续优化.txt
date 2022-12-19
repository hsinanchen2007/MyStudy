```
class Solution {
    // 根据暴力法可得：
    // dp[i] = 1/W(dp[i+1] + dp[i+2] + …… + dp[i+W])
    public double new21Game(int N, int K, int W) {
        if(K == 0){
            return 1.0;
        }
        double[] dp = new double[20000];
        for(int cur = K; cur <= N; cur++){
            dp[cur] = 1.0;
        }
        for(int cur = N+1; cur >= K && cur <= K-1+W; cur++){
            dp[cur] = 0.0;
        }
        
        int pos = K-1+W-W;
        double sum = 0.0;
        for(int j = 1; j <= W; j++){
            sum += 1.0/W*dp[pos+j];
        }
        dp[pos] = sum;
        for(int i = pos-1; i >= 0; i--){
            // 这就是关键优化所在。。相当于滑动窗口的思想，避免每次都重复计算i+1,……,i+W
            dp[i] = 1.0/W*dp[i+1] + dp[i+1] - 1.0/W*dp[i+1+W];
        }
        return dp[0];
    }
    
    // // 记忆化搜索（超时)，这道题说明记忆化搜索缺陷，不方便继续优化。。
    // public double new21Game(int N, int K, int W) {
    //     double[] dp = new double[20000];
    //     Arrays.fill(dp, -1.0);
    //     return f(N, K, W, 0, dp);
    // }
    // private double f(int N, int K, int W, int cur, double[] dp){
    //     if(dp[cur] >= 0.0){
    //         return dp[cur];
    //     }
    //     if(cur >= K){
    //         return cur <= N ? 1 : 0;
    //     }
    //     double ans = 0.0;
    //     for(int i = 1; i <= W; i++){
    //         double res = f(N, K, W, cur+i, dp);
    //         if(res > 0.0){
    //             ans += 1.0/W*res;
    //         }
    //     }
    //     return dp[cur] = ans;
    // }
}
```
