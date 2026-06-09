### 解题思路
标准的动态规划，每一个数字向前找，如果比前面的数字大，则此时的递增序列为dp(i) = max(dp(i), dp(j) + 1);

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int size = nums.size();
        if (size == 0)
            return 0;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        sort(dp.begin(), dp.end());
        return dp.back() + 1;
    }
};
```