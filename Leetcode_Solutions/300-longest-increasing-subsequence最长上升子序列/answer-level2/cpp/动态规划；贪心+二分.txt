### 代码

```cpp
class Solution {
public:
    //动态规划
    int dpLength(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        vector<int> dp;
        for(int i = 0; i < nums.size(); i++)
        {
            dp.push_back(1);
            for(int j = 0; j < i; j++)
                if(nums[j]<nums[i]) dp[i] = max(dp[i], dp[j]+1);
        }   
        return *max_element(dp.begin(), dp.end());
    }
    //贪心+二分查找
    int gaLength(vector<int>& nums)
    {
        vector<int> increase;
        for(int val : nums)
        {
            if(increase.empty() || val > increase.back())
                increase.push_back(val);
            else
            {
                auto it = lower_bound(increase.begin(), increase.end(), val);
                *it = val;
            }
        }
        return increase.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        //动态规划
        // return dpLength(nums);

        //贪心+二分查找
        return gaLength(nums);
    }
};
```