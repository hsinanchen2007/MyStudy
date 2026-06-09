### 解题思路
动态规划求出每一种和总共有多少种出现方式，然后除以总共的方式数目求得概率。

### 代码

```cpp
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(6*(n+1), 0));
        
        for (int i=1; i<=6; i++) {
            dp[1][i] = 1;
        }
        for (int i=2; i<=n; i++) {
            for (int j=i; j<=6*i; j++) {
                for (int cur=1; cur<=6; cur++) {
                    if (j-cur >0) dp[i][j] += dp[i-1][j-cur];
                }
            }
        }
        long all = pow(6, n);
        vector<double> res;
        for (int j=n; j<=6*n; j++) {
            if (dp[n][j] > 0) res.emplace_back(double(dp[n][j])/all);
        }
        return res;
    }
};
```