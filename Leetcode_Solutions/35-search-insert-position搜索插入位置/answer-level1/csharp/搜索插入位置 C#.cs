public class Solution {
    public int SearchInsert(int[] nums, int target) {
         if (nums.Length == 1) // when array only has one number
            {
                if (target <= nums[0])
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                for (var start = 0; start < nums.Length - 1; start++)
                {
                    if (target < nums[start]) // compare with first one
                    {
                        return 0;
                    }

                    if (target == nums[start]) // compare with first one
                    {
                        return start;
                    }
                    else if (target == nums[nums.Length - 1]) // compare with last one
                    {
                        return nums.Length - 1;
                    }
                    else if (target > nums[start] && target < nums[start + 1]) // compare with previous one and next one
                    {
                        return start + 1;
                    }
                }
            }
            
            return nums.Length;
    }
}