思路：直接原地修改nums数组，令nums[i]表示包含此元素的最大连续数列之和, 结果返回最大值即可。
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int max = nums[0];
        for(decltype(nums.size()) i = 1; i < nums.size(); ++i)
        {   
            if(nums[i-1] > 0)
                nums[i] += nums[i-1];   
            if(nums[i] > max)
                max = nums[i];
        }
        return max;
    }
};

时间O(N), 空间O(1)

