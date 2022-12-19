**思路**
`dp[i][j]`代表前`i`个钢筋组成的两个框架高度差为`j`的时候的长度之和
由于考察到第`i`个钢筋的时候，其结果仅取决于上一个钢筋的结果，因此可以进行状态压缩为一维的dp。
状态转移方程详可代码注释。
```
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int N = rods.size();
        int K = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(K + 1, 0);
        for (int i = 1; i <= N; ++i) {
            auto dp1 = dp;
            for (int j = 0; j <= K; ++j) {
                // 钢筋高度差为j的时候其加和至少为j，因此不符合条件的跳过
                if (dp[j] < j) continue;
                // 加到长的那一侧
                int k = j + rods[i - 1];
                dp1[k] = max(dp1[k], dp[j] + rods[i - 1]);
                // 加到短的那一侧
                k = abs(j - rods[i - 1]);
                dp1[k] = max(dp1[k], dp[j] + rods[i - 1]);
            }
            swap(dp, dp1);
        }
        return dp[0] / 2;
    }
};
```

![image.png](https://pic.leetcode-cn.com/fc5b89ce41d640aaa1d972c6dd526967e257881bf146efa65a375ccfef47cc80-image.png)
