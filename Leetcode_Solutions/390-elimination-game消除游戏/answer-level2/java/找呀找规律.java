    
// 找规律的题：设dp[n]表示从左往右遍历n个值时剩余的数字，rdp[n]表示从右往左遍历n个值时剩余的数字
// 则有：dp[n] = 2 * rdp[n/2];
// rdp[n] = n&1==0时，=2 * dp[n/2]-1; n&1==1时，=2 * dp[n/2]

```
public class Solution {
    public int lastRemaining(int n) {
        return dp(n, 0);
    }
    private int dp(int n, int f) {
        if (n == 1) {
            return 1;
        }
        int v = 2 * dp(n >> 1, f ^ 1);
        if (f == 1 && (n & 1) == 0) {
            v--;
        }
        return v;
    }
}
```
