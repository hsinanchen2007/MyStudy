public class Solution {
    public int SearchInsert(int[] nums, int target) {
          if (target <= nums[0])
            {
                return 0;
            }

            if (target > nums[nums.Length - 1])
            {
                return nums.Length;
            }

            var start = 0;
            var end = nums.Length - 1;
            while (start <= end)
            {
                var middle = (start + end) / 2;
                if (target == nums[middle]) 
                {
                    return middle;
                }

                if (target > nums[middle]) // 目标比中间数大，从中间往后找
                {
                    start = middle + 1;
                }
                else
                {
                    end = middle - 1; // 目标比中间数大，从中间往签找
                }
            }

            return start;  // 因为已经mid +1, 所以直接return start
    }
}