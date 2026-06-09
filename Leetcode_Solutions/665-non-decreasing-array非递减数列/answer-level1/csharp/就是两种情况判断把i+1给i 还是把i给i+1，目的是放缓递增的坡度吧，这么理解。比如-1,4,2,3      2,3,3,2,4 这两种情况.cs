 int change = 0;
            for(int i=0;i<nums.Length-1;i++)
            {
                if (i == 0)
                {
                    if (nums[i] > nums[i + 1])
                    {
                        nums[i] = nums[i + 1];
                        change++;
                    }
                }
                else
                {
                    if (nums[i] > nums[i + 1] && nums[i+1]<nums[i-1])
                    {
                        nums[i + 1] = nums[i];
                        change++;
                    }
                    else if(nums[i] > nums[i + 1] && nums[i+1]>=nums[i-1])
                    {
                        nums[i] = nums[i+1];
                        change++;
                    }
                }
            }
            return change == 0 || change == 1;