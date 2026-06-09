### 解题思路
采用动态规划的思想，用dp[i]表示以i节点结尾的子序列和的最大值。其中`dp[i] = max(nums[i], dp[i - 1] + nums[i])`

然后再找出dp[i]中的最大值，即为最终结果。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        int dp[len] = {0};  // p[i]表示以i节点结尾的子序列和的最大值
        int maxNum = nums[0];   // 用第一个节点初始化最大值
        dp[0] = nums[0];        
        for(int i = 1; i < len; ++i){
            // 两种情况：1.当前节点i的值 2.上一个节点i-1结尾的最大序列和加上当前节点
            // 如果上一个节点结尾的最大序列和小于0,那么dp[i] = nums[i]
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            if(dp[i] > maxNum){
                // 保存最大的值
                maxNum = dp[i];
            }
        }

        return maxNum;
    }
};
```

### 简化代码
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        int dp = nums[0];  // dp表示当前节点结尾的子序列和的最大值
        int maxNum = nums[0];   // 用第一个节点初始化最大值        
        for(int i = 1; i < len; ++i){
            // 两种情况：1.当前节点i的值 2.上一个节点i-1结尾的最大序列和加上当前节点
            // 如果上一个节点结尾的最大序列和小于0,那么dp = nums[i]
            dp = max(nums[i], dp + nums[i]);
            if(dp > maxNum){
                // 保存最大的值
                maxNum = dp;
            }
        }

        return maxNum;
    }
};
```