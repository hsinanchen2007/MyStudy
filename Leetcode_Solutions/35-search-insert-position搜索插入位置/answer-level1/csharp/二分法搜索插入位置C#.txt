```
public static int SearchInsert(int[] nums, int target)
        {
            int length = nums.Length;
            if (nums[0] > target)
            {
                return 0;
            }
            else if (nums[length - 1] < target)
            {
                return length;
            }
            return searchNum(0, length, nums, target);
        }

        public static int searchNum(int begin,int end,int[] nums,int target)
        {
            
            if (nums[begin]==target)
            {
                return begin;
            }
            if (end<nums.Length&&nums[end] == target)
            {
                return end;
            }
            if (begin + 1 == end)
            {
                return end;
            }
            if (nums[(end+begin)/2]<target)
            {
                return searchNum((end + begin) / 2, end, nums, target);
            }
            else //if (nums[(end + begin) / 2] > target)
            {
                return searchNum(begin, (end + begin) / 2, nums, target);
            }
        }
```
