public class Solution {
    public int RemoveElement(int[] nums, int val) {
                    var index = 0;
            foreach (var elem in nums)
            {
                if (elem != val)
                {
                    nums[index++] = elem;
                }
            }

            return index;
    }
}