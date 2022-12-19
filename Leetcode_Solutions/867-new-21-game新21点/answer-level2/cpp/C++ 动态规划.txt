# 思路：
1，`dp[i]`代表当前点数为i的时候的获胜概率
2，初始化：
当`i`属于`[K, min(K + W, N)]`区间时可以确定取值为`1.0`
且`dp[K - 1] = 1.0 * (N - K + 1) / W`
3，由于初始化可以确定的值是末端，因此动态规划方向为从大数到小数
4，动态规划转移方程:
当`i`属于`[0, K - 2]`区间时满足以下等式：
`dp[i] = dp[i + 1] - 1.0 * (dp[i + W + 1] - dp[i + 1]) / W`
推导过程为将`dp[i + 1]`与`dp[i]`的表达式写出来后，两式相减即可

```C++ []
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || K + W <= N) return 1.0;
        vector<double> dp(K + W + 1, 0);
        for (int i = K; i <= N && i <= K + W; ++i) {
            dp[i] = 1.0;
        }
        double r = 1.0 / W;
        dp[K - 1] = (N - K + 1) * r;
        for (int i = K - 2; i >= 0; --i) {
            dp[i] = dp[i + 1] - r * (dp[i + W + 1] - dp[i + 1]);
        }
        return dp[0];
    }
};
```

![image.png](https://pic.leetcode-cn.com/7ae595a22302504fc17ee69b5bdda649d4cf73604696493257ce76433995a61d-image.png)
