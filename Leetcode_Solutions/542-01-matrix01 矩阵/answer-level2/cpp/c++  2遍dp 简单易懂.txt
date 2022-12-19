### 解题思路
定义dp[i][j]表示该位置距离0的最短距离，其实很容易想到dp[i][j]要么等于0，要么等于min(dp[i-1][j],dp[i+1][j],dp[i][j-1],dp[i][j+1])+1

这个问题棘手的就是，我们更新状态的时候，要么从左上到右下，要么右下到左上，或者更不常见的右上到左下以及左下到右上。无论哪种更新方式都只能依赖两个前置状态（比如从左上到右下时， dp[i][j]只能依赖dp[i-1][j]和dp[i][j-1]）。

这里做两遍dp状态的更新来解决上述问题， 第一次从左上到右下，转移方程为：
dp[i][j] = 0          或
dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]+1)
第二次更新从右下到左上，转移方程为
dp[i][j] = 0          或
dp[i][j] = min(dp[i][j], dp[i][j+1]+1, dp[i+1][j]+1)

齐活
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!matrix[i][j]) continue;
                int t_val = i == 0 ? 10001 : dp[i-1][j] + 1;
                int l_val = j == 0 ? 10001 : dp[i][j-1] + 1;
                dp[i][j] = min(t_val, l_val);
            }
        }
        for (int i = matrix.size()-1; i >= 0; --i) {
            for (int j = matrix[0].size()-1; j >= 0; --j) {
                if (!matrix[i][j]) continue;
                int b_val = i == matrix.size()-1 ? 10001 : dp[i+1][j] + 1;
                int r_val = j == matrix[0].size()-1 ? 10001 : dp[i][j+1] +1;
                dp[i][j] = min(dp[i][j], min(b_val, r_val));
            }
        }
        return dp;
    }
};
```
![微信图片_20200227123538.png](https://pic.leetcode-cn.com/88d74f0e4b01b25d01983910f6ac251c6cb24c21549b8818ca7170a6c9d11b42-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200227123538.png)
