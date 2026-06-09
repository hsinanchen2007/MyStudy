### 解题思路
看大佬们建议从后往前，觉得从前往后也可以，就试了一把
DP思路:

dp[i] = max(dp[i-1], num[i] + dp[i-2])
解释：
    当前打劫，则要求 i-1 不打劫，为 num[i]+dp[i-2]
    当前不打劫，i-1可以打劫，为 dp[i-1]

注意初始化即可

### 代码

```cpp
class Solution {
public:
int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return nums.back();
        }

        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp.back();
    }
};
```