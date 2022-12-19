这是一个完全背包问题，可以把第i个完全平方数看成重量为i*i,价值为1的物品，背包容量为n, 求总价值和最小。

背包代码：
```
for (int i = 1; i <= n; i++)
    for (int j = w[i]; j <= V; j++)
        f[j] = min(f[j], f[j - w[i]] + v[i]);
```


```
class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];

        Arrays.fill(dp, 1000);
        for (int i = 1; i * i < n + 1; i++) {
            dp[i*i] = 1;
        }
        for (int i = 1; i * i < n + 1; i++) {
            for (int j = i * i; j < n + 1; j++) {
                dp[j] = Math.min(dp[j], dp[j - i*i] + 1);
            }
        }
        return dp[n];
    }
}
```
