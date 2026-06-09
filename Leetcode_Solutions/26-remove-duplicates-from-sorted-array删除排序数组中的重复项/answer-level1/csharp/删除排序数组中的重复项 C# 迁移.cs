public class Solution {
    public int RemoveDuplicates(int[] nums) {
         if (nums.Length == 0)
            {
                return 0;
            }

            var index = 0;
            for (var i = 1; i < nums.Length; i++)
            {
                if (nums[index] != nums[i])
                {
                    nums[++index] = nums[i];
                }
            }

            index = index + 1;
            System.Array.Resize(ref nums, index);

            return index;
    }
}