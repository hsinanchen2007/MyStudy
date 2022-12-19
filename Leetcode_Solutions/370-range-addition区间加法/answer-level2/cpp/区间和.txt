### 解题思路

区间求和问题

只需要关心区间两端值的变化

### 代码

```cpp
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> dp(length+1, 0);
        vector<int> ans(length, 0);
        for (int i = 0; i < updates.size(); i++){
            dp[updates[i][0]] += updates[i][2];
            dp[updates[i][1] + 1] -= updates[i][2];
        }
        ans[0] = dp[0];
        for (int i =1; i< length; i++){
            ans[i] = ans[i-1] + dp[i];
        }
        return ans;
    }
};
```