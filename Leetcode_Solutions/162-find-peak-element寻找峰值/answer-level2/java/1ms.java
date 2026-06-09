class Solution {
    public int findPeakElement(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        if (nums.length == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            } else {
                return 1;
            }
        }
        for (int i=0;i<nums.length;i++) {
            int preNum = i == 0 ? 0 : nums[i-1];
            int aftNum = i == nums.length-1 ? 0 : nums[i+1];
            if (nums[i] > preNum && nums[i] > aftNum) {
                    return i;
            }
        }
        return -1;
    }
}