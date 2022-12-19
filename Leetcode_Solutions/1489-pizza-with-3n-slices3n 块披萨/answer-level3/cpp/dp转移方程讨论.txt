### 解题思路

我这个题解不打算讨论理论性的证明，因为其他人已经给好了，只是想讨论下关于转移方程的问题。
一般而言我看其他的答主(一维二维本质上也没啥区别，为了方便理解，这里用二维)

$dp[i][j] = max(dp[i - 1][0],...,dp[i -1][j - 2]) + slices[j]$

如果按照实际来看，这个转移方程似乎并不严谨，`dp[i][j]`表示的是**前j个数取到第i轮时得到的最大值**，所以说对于`slices[j]`来讲，我们应该由取或不取两种策略，如果取的话就是上面的这个，但实际上我们也可以不取这个数此时对应的方程应该是:

$dp[i][j] = dp[i][j - 1]$

总的转移方程就是两者取最大值就可以了

$dp[i][j] = max(d[i][j - 1], max(dp[i - 1][0],...,dp[i -1][j - 2]) + slices[j])$

**个人认为**这样思路比较好想一点

>虽然比赛中看到这题想了想没思路就弃了:(

这样的话最后就不用再遍历一遍dp..像其他答主的一般在最后会把dp的最后一行重新遍历一遍，求得最大值，这也是由于所谓`dp[i][j]`并不是真的最大值

### 代码

```cpp
class Solution {
        int dp[200][505];
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int res = 0;
        memset(dp, 0 , sizeof(dp));
        int maxFront = 0;
        // 第一轮 1 ~ n-1
        for (int i = 1; i <= n / 3; i++) {
            maxFront = 0;
            for (int j = 1 ; j <= n - 1; j++) {
                if (j >= 2) maxFront = max(dp[i - 1][j - 2], maxFront);
                dp[i][j] = max(dp[i][j - 1], slices[j - 1] + maxFront);
            }
        }
        res = max(res, dp[n / 3][n - 1]);
        memset(dp, 0, sizeof(dp));
        // 第二轮 2 ~ n
        for (int i = 1; i <= n / 3; i++) {
            maxFront = 0;
            for (int j = 2 ; j <= n; j++) {
                if (j >= 2) maxFront = max(dp[i - 1][j - 2], maxFront);
                dp[i][j] = max(dp[i][j - 1], slices[j - 1] + maxFront);
            }
        }
        return max(res, dp[n / 3][n]);
    }
};
```