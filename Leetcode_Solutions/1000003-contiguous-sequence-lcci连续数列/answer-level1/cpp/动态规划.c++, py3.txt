动态规划差不多都是这样的套路。用变量或数组来不断记录最优选择。
```cpp []
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        int pre = nums[0], cur, ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (pre < 0) cur = nums[i];
            else cur = pre + nums[i];
            ans = max(ans, cur);
            pre = cur;
        }
        return ans;
    }
};
```
```python3 []
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return nums[0]
        dp = [0]*len(nums)
        dp[0] = nums[0]
        ans = dp[0]
        for i in range(1, len(nums)):
            if dp[i - 1] < 0:
                dp[i] = nums[i]
            else:
                dp[i] = nums[i] + dp[i - 1]
            ans = max(ans, dp[i])
        return ans
```

