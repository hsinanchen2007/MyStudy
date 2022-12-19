这道题目本质是求 n 个骰子抛出的和的种类数，n 个骰子能抛出的最小值为 n，最大值为 6n。

例如：当 n = 1 时，和的取值为 [1, 6]，并且组成每个和的种类数为1个。

当 n = 2时，和的取值为 [2, 12]，组成 2 的种类只有 1 种(2个骰子都为1点)，组成 3 的种类有 2 种(1,2 和 2,1)

因此，使用动态规划思想，定义 dp[i][j] 表示当前有 i 个骰子抛出和为 j 的种类数。

最后，对于n个骰子，先求和，再计算概率即可。

```
class Solution {
   public:
    vector<double> twoSum(int n) {
        int num = n * 6;
        vector<vector<int>> dp(n + 1, vector<int>(num + 1, 0));

        for (int i = 1; i <= 6; i++) dp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= i * 6; j++) {
                for (int k = 1; k <= 6 && k <= j; k++) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        int sum = 0;
        for (int i = n; i <= num; i++) sum += dp[n][i];

        vector<double> res;
        for (int i = n; i <= num; i++) {
            if (dp[n][i] != 0) {
                res.push_back(1.0 * dp[n][i] / sum);
            }
        }
        return res;
    }
};
```

时间复杂度：O(n^2)
空间复杂度：O(n^2) 可优化到 O(n)

![image.png](https://pic.leetcode-cn.com/2f2fa372b0b252259374eabc478da21f24569fae268b5cbbade07850eb1d6bf8-image.png)
