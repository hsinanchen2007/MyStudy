```
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        sort(nums.begin(),nums.end());
        int idx1 = 0, idx2 = 0, res = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums[idx2])
            {
                if(nums[idx2] - nums[idx1] == 1 && i - idx1 > res) 
                    res = i - idx1;
                idx1 = idx2;
                idx2 = i;
            }
        }
        if(nums[idx2] - nums[idx1] == 1 && nums.size() - idx1 > res) 
            res = nums.size() - idx1;
        return res;
    }
};
```