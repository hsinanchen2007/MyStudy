直接用arrays的sort方法进行排序，然后输出nums.length-k位置的值即可，不要打我哈哈

import java.util.Arrays;
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
}