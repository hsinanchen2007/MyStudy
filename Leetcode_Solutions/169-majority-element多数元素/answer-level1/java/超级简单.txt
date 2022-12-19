终于有道题会做了，难受
排完序就剩两种必然情况。。
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int len=nums.length;
        if(nums[len-1]==nums[len/2]){
            return nums[len/2];
        }else {
            return nums[len/2-1];
        }
    }
}