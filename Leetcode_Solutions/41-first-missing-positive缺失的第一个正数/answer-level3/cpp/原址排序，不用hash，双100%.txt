int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();)
        {
            if(nums[i]>0 && nums[i]<=nums.size() && nums[i]!= (i+1))
            {
                int tmp = nums[i];
				if (nums[tmp - 1] != tmp)
				{
					nums[i] = nums[tmp - 1];
					nums[tmp - 1] = tmp;
					continue;
				}
            }
            i++;
        }
        int i=1;
        for(;i<=nums.size();i++)
        {
            if(i!=nums[i-1])
            {
                break;
            }
        }
        return i;
    }