### 解题思路
dp[i][j]表示0~i枚硬币j个正面朝上的概率
// 1. 前一次已有j个正面朝上，这一次反面朝上
// 2. 前一次已有j-1个正面朝上，这一次还是正面朝上
dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];

![图片.png](https://pic.leetcode-cn.com/76fddcee6c898d293e744739b3eb89b85fa47ab3a5e8c0a1c4720c728af0e7d0-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        if (target > n) return 0.0;
        if (target == 0 || target == n) {
            double ans = 1.0;
            for (auto p : prob) {
                ans *= ((target == 0) ? (1 - p) : p);
            }
            return ans;
        }
        vector<vector<double>> dp(n, vector<double>(target + 1, 0));   // dp[i][j]表示0~i枚硬币j个正面朝上的概率
        // 设置初始边界条件
        dp[0][0] = 1 - prob[0];
        dp[0][1] = prob[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
            if (i <= target - 1) {
                dp[i][i + 1] = dp[i - 1][i] * prob[i];
            }
        }
        // 递推计算
        for (int i = 1; i < n; ++i) {
            for (int j = 1; (j <= target) && (j <= i + 1); ++j) {
                // 1. 前一次已有j个正面朝上，这一次反面朝上
                // 2. 前一次已有j-1个正面朝上，这一次还是正面朝上
                dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
            }
        }
        return dp[n - 1][target];
    }
};
```