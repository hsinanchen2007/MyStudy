public static int RemoveElement(int[] nums, int val)
        {
            int count = 0;
            for(int i=0;i<nums.Length;i++)
            {
                if (nums[i] != val) { count++; continue; }
                int k = i;
                while(i<nums.Length)
                {
                    if(nums[i]!=val)
                    {
                        int temp = nums[i];
                        nums[i] = nums[k];
                        nums[k] = temp;
                        i = k;
                        count++;
                        break;
                    }
                    i++;
                }
            }
            return count;
        }