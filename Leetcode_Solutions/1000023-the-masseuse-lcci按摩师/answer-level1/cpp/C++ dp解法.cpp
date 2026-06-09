### 解题思路
![image.png](https://pic.leetcode-cn.com/6cf918eb15b0916eca73e9eabf0a290159e35637c98439f441b05237e139fbeb-image.png)

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
        dp[1][0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = dp[0][i-1] + nums[i];
        }
        return max(dp[0][nums.size()-1], dp[1][nums.size()-1]);
    }
};
```