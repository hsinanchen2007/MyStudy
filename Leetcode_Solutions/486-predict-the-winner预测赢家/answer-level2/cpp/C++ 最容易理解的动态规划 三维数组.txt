C++ 看的一头雾水，发一个最容易理解的动态规划，三维数组

```c++
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return true;

        // dp[i][j] = {first, second}表示区间[i,j]中，前者最高得first分数，后者最高得second分
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = {nums[i], 0};        // 区间内只有一个可选，前者得分nums[i]，后者0
        }

        /* 因为每次取数从两端任意取，即从外向内，所以这里循环先算最小两个数的区间dp[0][1]
           (只有一个数的区间已经初始化算过了)， 然后由内向外逐渐扩大区间：
           k=1:dp[0][1],dp[1][2]..dp[n-2][n-1]
           k=2:dp[0][2],dp[1][3]..dp[n-3][n-1]
           ...
           k=n-1:dp[0][n-1]
         */
        for (int k = 1; k < n; k++) {
            for (int i = 0; i + k < n; i++) {   
                int j = i + k;

                // 前者选nums[i],后者定选dp[i+1][j].first,因为它优于dp[i+1][j].second
                int s1 = nums[i] + dp[i + 1][j].second; 
                int s2 = nums[j] + dp[i][j - 1].second; 
                if (s1 >= s2) {
                    // 为什么pair后者直接用first就好了呢？因为这个值在上一轮循环中已经计算过了
                    dp[i][j] = {s1, dp[i + 1][j].first}; 
                } else {
                    dp[i][j] = {s2, dp[i][j - 1].first};
                }
            }
        }
        return dp[0][n - 1].first >= dp[0][n - 1].second;
    }
};
```

