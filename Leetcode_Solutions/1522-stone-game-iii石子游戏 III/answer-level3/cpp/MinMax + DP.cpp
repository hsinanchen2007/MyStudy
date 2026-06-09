### 解题思路

从右向左枚举，Alice先取正的分数，Bob后取负的分数，最后计算得分正负。

### 代码

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--) {
            dp[i] = stoneValue[i] - dp[i+1];
            if(i + 2 <= n) {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] - dp[i+2]);
            }
            if(i + 3 <= n) {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]);
            }
        }
        
        if(dp[0] > 0)
            return "Alice";
        else if(dp[0] == 0)
            return "Tie";
        else
            return "Bob";
    }
};
```