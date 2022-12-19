思路其实很简单，dp[0]初始状态下网格状态，此时只有球的起始位置(i,j)
每一次移动后，dp[t]的状态依赖于dp[t-1]，dp[t]中(mi,ni)位置的数值
等于上一阶段dp[t-1]中(mi,ni)上下左右四个位置数值之和。

最后的出界数和0～N-1次移动后的网格状态有关。第i（0<=i<=N-1）次移动后，所有在边缘的球，
在第i+1次移动时都可以移动到外界。所以最后总的出界数 等于 0～N-1次移动后 所有边缘坐标 存在的球的个数的总和。

具体实现为了避免边界判断，上下左右都补了0，1<=mi<=m;1<=ni<=n,注意下标使用不要出错。

最后为了避免每次运算都%(1000000007),我们使用long来替代int，最后转换为int即可。
当然你要说我就使用int行不行（小伙子你挺犟啊），当然可以，多加几个取模运算即可，就是看起来不简洁。


```
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0)
            return 0;
        long dp[N][m + 2][n + 2];
        memset(dp, 0, sizeof(dp));
        dp[0][i + 1][j + 1] = 1;
        long int res = 0;
        if (i == 0)res++;
        if (i == m - 1)res++;
        if (j == 0)res++;
        if (j == n - 1)res++;

        for (int t = 1; t < N; t++) {
            for (int mi = 1; mi <= m; mi++) {
                for (int ni = 1; ni <= n; ni++) {
                    dp[t][mi][ni] = dp[t - 1][mi - 1][ni] + dp[t - 1][mi + 1][ni]
                                    + dp[t - 1][mi][ni - 1] + dp[t - 1][mi][ni + 1];
                    dp[t][mi][ni] %= 1000000007;
                    if (mi == 1)res += dp[t][mi][ni];
                    if (mi == m)res += dp[t][mi][ni];
                    if (ni == 1)res += dp[t][mi][ni];
                    if (ni == n)res += dp[t][mi][ni];
                    res %= 1000000007;
                }
            }
        }
        return int(res);
    }
};
```

最后的结果还是挺不错的，时间和空间利用都比较靠前：
![image.png](https://pic.leetcode-cn.com/313b8b8708eb900906691bf5685a3444574d144fcf1a0b4fec1403ba3321b45a-image.png)
