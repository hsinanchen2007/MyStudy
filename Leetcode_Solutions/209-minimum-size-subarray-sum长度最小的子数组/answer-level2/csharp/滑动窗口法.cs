```
public static int MinSubArrayLen(int[] nums, int s)
        {
            int left = 0, right = -1; 
            int sum = 0;
            int res = nums.Length + 1;

            while (left < nums.Length)
            {   

                if (right + 1 < nums.Length && sum < s)
                    sum += nums[++right];
                else
                    sum -= nums[left++];

                if (sum >= s)
                    res = res > right - left + 1 ? right - left + 1 : res;
            }

            if (res == nums.Length + 1)
                return 0;
            return res;
        }
```
