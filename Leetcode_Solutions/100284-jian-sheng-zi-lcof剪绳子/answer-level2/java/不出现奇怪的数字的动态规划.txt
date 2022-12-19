dp[i] 表示长度 i 的绳子分段后最大的乘积（至少两段），每次划分得到的两部分 k 和 i-k，划分之后两者应该有四种情况：
1. k 不再划分，i-k 继续划分，所以是 k * dp[i-k]；
2. k 不再划分，k-i 不在划分，所以是 k * (i-k])；
3. k 继续划分，k-1 继续划分，所以是 dp[k] * dp[i-k]；
4. k 继续划分，k-1 不在划分，所以是 dp[k] * (i - k)；
dp[i] = max(k * dp[i-k],k * (i-k]),dp[k] * dp[i-k],dp[k] * (i - k))，其中dp[2] = 1,dp[3] = 2。一开始我是这么想的，然后看见题解里面的答案从 dp[1] = 1,dp[2] = 2，dp[3] = 3 开始，我就看得有点蒙，不是很懂这么想的。。。
貌似我这么分的话 dp[2] -> dp[n] 的数值都是正确的，计算量多一丢丢，
```
class Solution {
    public int cuttingRope(int n) {
        int[] dp = new int[n+2];
        dp[2] = 1;
        dp[3] = 2;
        if(n <= 3) return dp[n];
        for(int i = 4;i <= n;i++){
            for(int j = 1; j <= (i+1)/2 ;j++ ){
                // 省了一个中间变量 max，用 dp[i] 替代了
                dp[i] = Math.max(dp[i],Math.max(j*(i-j),dp[j]*dp[i-j]));
                dp[i] = Math.max(dp[i],Math.max(dp[j]*(i-j),j*dp[i-j]));
            }
        }
        return dp[n];
    }
}
```
