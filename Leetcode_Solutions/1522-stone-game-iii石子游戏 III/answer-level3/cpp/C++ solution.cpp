### 解题思路
动态规划， 从后往前计算

### 代码

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1,0);
        int sum = 0;
        for (int i = n-1; i >= 0; i--) {
            dp[i] = INT_MIN;
            sum += stoneValue[i];
            for (int j = 1; j <= 3; j++) {
                if (i + j <= n) {
                    dp[i] = max(dp[i], sum - dp[i+j]);
                }
            }
        }
        if (dp[0] > sum - dp[0]) {
            return "Alice";
        } else if (dp[0] < sum - dp[0]) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};
```