int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        //for(int i = 0; i < nums.size(); ++i)//逻辑错误
        int i = 0;
        while(i < nums.size() - 1)
        {
            if(nums[i] == nums[i + 1])
                i += 3;
            else if(nums[i] != nums[i + 1])//&& (i+1) != nums.size()
                return nums[i];
        }
        return nums[nums.size() - 1];
}