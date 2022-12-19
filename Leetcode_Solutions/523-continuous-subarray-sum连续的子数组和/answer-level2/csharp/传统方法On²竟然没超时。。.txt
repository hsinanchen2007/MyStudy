













public static  bool CheckSubarraySum(int[] nums, int k)
        {//min(len)==2  且和为k倍数
            for (int i = 0; i < nums.Length - 1;i++)
            {
                int sum = nums[i];
                for(int j=i+1;j<nums.Length;j++)
                {
                    sum += nums[j];
                    if((k==0 && sum==0)||(k!=0)&&(sum%k==0)) 
                        return true;
                }
            }
            return false;
        }