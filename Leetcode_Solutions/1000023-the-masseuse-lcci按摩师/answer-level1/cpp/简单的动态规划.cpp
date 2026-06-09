### 解题思路

考虑选中第i个顾客的情况，那么第i-1个顾客一定不能选，只需要考虑上一个顾客是第i-2还是i-3，因为如果上一个顾客选i-4，那么还可以白嫖第i-2的顾客，因此递推公式为
$$
dp[i] = max(dp[i-2], dp[i-3])+nums[i]
$$
最后的答案是$max(dp[n], dp[n-1])$，即选最后一个顾客或者不选最后一个顾客，再处理一些特殊情况和边界条件即可。

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(nums[1]);
        
        int maxValue;
        for (int j = 2; j < nums.size(); j++)
        {
            maxValue = 0;
            for(int i = j - 2; i >= max(j-3, 0); i--)
            {
                maxValue = max(maxValue, nums[j] + dp[i]);
            }
            dp.push_back(maxValue);
        }

        return max(dp[dp.size()-1], dp[dp.size()-2]);
        
    }
};
```