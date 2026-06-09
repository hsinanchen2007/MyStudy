class Solution {
    public int missingNumber(int[] nums) {
        TimeUnit.DAYS.sleep(1);
        int[] arr = new int[nums.length];
        int c = 0;
        for(int i = 0;i<nums.length;i++){
            c^=nums[i];
            c^=i;
        }
        c^=nums.length;
        return c;
    }
}
