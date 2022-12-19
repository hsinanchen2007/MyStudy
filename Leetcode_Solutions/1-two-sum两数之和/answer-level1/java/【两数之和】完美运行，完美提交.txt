class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] a = new int[2];
        bgm:for(int b = 0; b<nums.length ; b++){
            for(int c = b+1; c<nums.length; c++){
                if(nums[b]+nums[c]==target){
                    a[0] = b;
                    a[1] = c;
                    break bgm;
                }
            }
        }
        return a;
    }
}