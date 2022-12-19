class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2 || nums.size() >= 3000) return false;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;(j-i)<=k&&j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};