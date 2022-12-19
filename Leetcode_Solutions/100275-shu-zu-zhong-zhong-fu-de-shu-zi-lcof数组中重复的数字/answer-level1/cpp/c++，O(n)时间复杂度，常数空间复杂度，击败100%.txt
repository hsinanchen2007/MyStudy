    int findRepeatNumber(vector<int>& nums) 
    {
        //算法思路见剑指offer,P39-40
        if(nums.empty())
            return -1;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] != i)
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                else
                    swap(nums[i], nums[nums[i]]);
            }
        }
        
        return -1;
    }