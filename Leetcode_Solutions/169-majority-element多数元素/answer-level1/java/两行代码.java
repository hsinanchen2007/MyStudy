class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];//仔细想想为什么是nums.length/2
    }
}