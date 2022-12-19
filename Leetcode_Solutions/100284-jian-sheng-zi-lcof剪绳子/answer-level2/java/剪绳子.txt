剪绳子问题，只需要比较的是 剪了绳子以后的段相乘的结果的大小即可；
比较k*(i-k)和k*dp[n-k]

k代表的是每次要减去的长度，i-k代表的是长度为i的时候，减去K的长度；
dp[i-k]代表的是 减去i-k代表的最大长度，比较二者的大小即可；
```java
class Solution {
    //只需要比较i*(n-i)和i*dp[n-i]之间的大小；
    public int cuttingRope(int n) {
        int[] dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++){
            for(int k=2;k<=i-1;k++){
                dp[i] = Math.max(dp[i],Math.max(k*(i-k),k*dp[i-k]));
            }
        }
        return dp[n];
    }
}
```
