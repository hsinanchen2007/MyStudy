
int max=nums[0];
        for (int i = 0; i <nums.length ; i++) {
            {      int sum=0;
                for (int j=i;j<nums.length;j++)
                {
                    sum+=nums[j];
                    if (max<sum)
                    {
                        max=sum;
                    }
                }
            }
        }
        return max;