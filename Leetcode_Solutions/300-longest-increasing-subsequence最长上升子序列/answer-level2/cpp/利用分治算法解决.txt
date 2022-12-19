**利用分治算法，将数组分为三个状态，数组最大值左面的子数组，数组最大值右面的子数组以及没有用到这个最大值的数组**
```
class Solution {
public:
    int lengthL(vector<int> nums)
    {
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return 1;
        vector<int> tem=nums;
        sort(tem.begin(),tem.end());
        if(tem==nums)
            return nums.size();
        reverse(tem.begin(),tem.end());
        if(tem==nums)
            return 1;
        auto max_iter=max_element(nums.begin(),nums.end());
        vector<int> left(nums.begin(),max_iter);
        vector<int> right(max_iter+1,nums.end());
        nums.erase(max_iter);
        int num_left=lengthL(left)+1;
        int num_right=lengthL(right);
        int mid=lengthL(nums);
        return max(mid,max(num_left,num_right));
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> tem;
        tem.push_back(nums.front());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else
                tem.push_back(nums[i]);
        }
        return lengthL(tem);
    }
};
```
