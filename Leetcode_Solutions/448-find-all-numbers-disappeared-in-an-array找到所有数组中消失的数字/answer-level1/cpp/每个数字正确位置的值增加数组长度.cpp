```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for(int i=0; i<nums.size(); i++)
        {
            nums[(nums[i]-1)%nums.size()] += nums.size();
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<=nums.size())
            {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
```
