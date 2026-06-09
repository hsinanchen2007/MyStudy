class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0 || k ==1) {
            return nums;
        }
        int[] res = new int[nums.length - (k-1)];
        int maxNum = nums[0];
        for (int i = 0; i < res.length; i++) {
            if (i == 0 || nums[i-1] == maxNum) {
                maxNum = nums[i];
                for (int j = i + 1; j < k + i; j++) {
                    if (nums[j] > maxNum) {
                        maxNum = nums[j];
                    }
                }
                res[i] = maxNum;
                continue;
            }
            if (nums[i+(k-1)]>maxNum) {
                maxNum = nums[i+(k-1)];
            }
            res[i] = maxNum;
        }
        return res;
    }
}