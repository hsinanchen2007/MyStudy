```C++ []
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int len = nums.size();
        int dp_pre_2 = 0;
        int dp_pre_1 = nums[0];
        int dp = 0;
        if(len == 1)
            return nums[0];
        for(int i=2; i<=len; i++)
        {
            dp = max(nums[i-1]+dp_pre_2, dp_pre_1);
            dp_pre_2 = dp_pre_1;
            dp_pre_1 = dp;
        }
            
        return dp;

    }
};
```

