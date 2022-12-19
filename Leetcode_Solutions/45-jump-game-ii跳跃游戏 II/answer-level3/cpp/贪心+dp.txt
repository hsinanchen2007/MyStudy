### 解题思路
1. dp数组保存位置i时需要最少步数
2. 对每个nums[i]计算i+nums[i]为从i位置一次跳跃可以覆盖的最远范围。
3. 每个位置i更新当前跳跃可以覆盖的最远位置pre，到从位置i跳跃可以覆盖的最远位置

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp(nums.size(), nums.size());
        dp[0] = 0;
        int end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i + nums[i] <= end) continue;           // 无法更新dp数组的跳跃，直接忽略
            int pre = end;                              // 保存之前跳跃可以到达的最远位置
            end = min(int(nums.size()-1), i + nums[i]); // 计算本次跳跃可以到达的最远位置
            for (int j = pre + 1; j <= end; ++j) {      // 更新本次跳跃可以更新的dp数组
                dp[j] = dp[i] + 1;
                if (j >= nums.size() - 1) return dp[j]; // 如果可到达数组尾，直接退出
            }
        }
        return dp[nums.size() - 1];
    }
};
```

时间复杂度O(n)
空间负责度O(n)