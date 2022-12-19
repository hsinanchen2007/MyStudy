### 解题思路
不会优化，直接dp的思路
分析一下：

* 状态有：

    * 房子
    * 颜色

* dp数组含义：

    所以设一个二维dp数组dp\[i][j]，代表0~i号房子且第i号房子粉刷为j颜色的最小成本，其中j取值为[0,k]

* 状态转移方程：

    容易想到：

    $dp[i][j] = min\{dp[i - 1][r] | r\in[0,k]\&r\neq j\}$


* base case:

    显而易见：$dp[0][j] = costs[0][j](j\in [0,k])$

    
### 代码

```cpp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;  //trick
        int k = costs[0].size();
        vector<vector<int>> dp(n, vector<int>(k)) ;
        //边界
        for(int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
        }
        //方程
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < k; j++) {
                int temp = INT_MAX;
                for(int q = 0; q < k; q++) {
                    if(q != j) temp = min(dp[i - 1][q], temp);
                }
                dp[i][j] = temp + costs[i][j];
            }
        }
        int ans = dp[n - 1][0];
        for(int i = 1; i < k; i++) {
            ans = min(dp[n - 1][i], ans);
        }
        return ans;
    }
};


```