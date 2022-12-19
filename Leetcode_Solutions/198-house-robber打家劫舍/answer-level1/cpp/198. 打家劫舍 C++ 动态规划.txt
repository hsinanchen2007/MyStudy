### 解题思路
dp[i] 表示第i个房屋的最大值
转移矩阵：
dp[i] = max(dp[i-1],dp[i-2]+num[i]),i从0 开始

为了方便处理边界条件，我们设置dp[0] = 0

### 代码

```cpp
class Solution {
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty()) {
            return 0;
        }

        vector<int> dp = vector<int>(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }

        return dp[nums.size()];
    }
};
```