### 解题思路
简单动态规划解决   （关注微信公众号'码农黑板报'获取更多题解）
![image.png](https://pic.leetcode-cn.com/1e4d0a6a60b19cd100db4df8fd12019ff413734795203e00ad1d82bf422b31fd-image.png)


### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
            res = std::max(res, dp[i]);
        }
        return res;
    }
};
```