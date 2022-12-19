 int j = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] != val)
                {
                    nums[j] = nums[i];
                    if (i != j)
                        nums[i] = val;
                    j++;
                }
            }

            return j;