### 解题思路
1. 定义：`dp[n][i]`为前`n`个骰子和达到`i`的总个数
2. 转移方程：`dp[n][i]`可以由`{dp[n-1][i-1], dp[n-1][i-2],...,dp[n-1][i-6]}`转移得来
3. 边界条件：初始时`dp[1][i] = 1`,即掷一个骰子，得到数字`1-6`的可能总数都为`1`

### 代码

```cpp
class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[12][67];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= 6; ++i){
            dp[1][i] = 1;
        }
        for(int i = 2; i <= n ; ++i){
            for(int j = i; j <= 6 * i; ++j){
                for(int k = 1; k <= 6; ++k){
                    if(j - k <= 0) break;
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ans;
        for(int i = n; i <= 6 * n; ++i){
            ans.push_back(dp[n][i] * 1.0 / all);
        }
        return ans;
    }
};
```