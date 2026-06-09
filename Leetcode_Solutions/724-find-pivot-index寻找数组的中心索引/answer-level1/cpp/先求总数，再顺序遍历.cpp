```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int left_sum = 0;
        if(nums.size() == 0)
            return -1;
        for(auto n:nums)
            sum += n;
        for(int i=0; i<nums.size(); i++)
        {
            if(left_sum * 2 == (sum-nums[i]))
                return i;
            left_sum += nums[i];
        }
        return -1;
    }
};
```
