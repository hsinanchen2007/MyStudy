### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);    // dp[i] 表示以 A[i]结尾的最大连续子序列和
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i < size; i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```