该题要找到连续子数组的最大和，可用动态寻找
即定义两个变量presum、maxsum
一个动态选择的做加法
一个记录最大值

```
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        int presum = nums[0];
        int maxsum = presum;
        for(int i = 1; i < nums.size(); i++)
        {
            presum = presum > 0 ? presum += nums[i] : nums[i]; 
            maxsum = max(maxsum,presum); 
        }
        return maxsum;
    }
};
```
