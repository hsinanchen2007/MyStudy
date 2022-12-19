```
class Solution 
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        else if (nums.size() == 1)
            return nums[0];

        else
        {
            int mcb[nums.size()];
            mcb[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
                mcb[i] = max(nums[i], mcb[i - 1] + nums[i]);
            
            int opt[nums.size()];
            opt[0] = mcb[0];
            for (int j = 1; j < nums.size(); j++) 
                opt[j] = max(max(opt[j - 1], nums[j]), nums[j] + mcb[j - 1]);
            
            return opt[nums.size() - 1];
        }
    }
};
```
