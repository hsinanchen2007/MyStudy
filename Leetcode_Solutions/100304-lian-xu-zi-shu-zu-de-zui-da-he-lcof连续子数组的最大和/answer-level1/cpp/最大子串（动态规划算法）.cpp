### 解题思路


### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int dp_last = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
           dp_last = std::max(nums[i],nums[i]+dp_last);
           if (dp_last > max_sum)
           {
               max_sum = dp_last;
           }
        }
        return max_sum;
    }
};
```