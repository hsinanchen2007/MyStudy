class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int i = 0;
        for(i; i < nums.size(); i++)
        {
            if(target == nums[i])
            {
                return i;
            }
            if(target <= nums[i])
            {
                return i;
            }
        }
        return i;
        
    }
};