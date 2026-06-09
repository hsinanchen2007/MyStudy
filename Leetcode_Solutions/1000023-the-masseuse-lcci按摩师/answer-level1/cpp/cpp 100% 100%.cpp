### 解题思路
dp[i]: 包含nums[i]的最大值
maxValue: i - 1之前的最大dp值
dp[i] = maxValue + nums[i], 结果取dp末尾两个数的较大值

### 代码

```cpp
class Solution 
{
public:
    int massage(vector<int>& nums) 
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return nums[0];
        if (size == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(size, 0);
        int maxValue = 0;
        int i = 2;
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (; i < size; i++)
        {
            maxValue = maxValue < dp[i - 2]? dp[i - 2]: maxValue; 
            dp[i] = maxValue + nums[i];
        }
        return max(dp[size - 2], dp[size - 1]);
    }
};
```