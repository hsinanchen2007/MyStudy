    
    class Solution {
        public int[] maxSlidingWindow(int[] nums, int k) {
            if(nums.length <= 1) {
                return nums;
            }
            int[] left = new int[nums.length];
            int[] right = new int[nums.length];
            for(int i = 0;i < nums.length;i++) {
                left[i] = i % k == 0 ? nums[i] : Math.max(left[i - 1], nums[i]);
            }
            right[nums.length - 1] = nums[nums.length - 1];
            for(int i = nums.length - 2;i >= 0;i--) {
                right[i] = i % k == k - 1 ? nums[i] : Math.max(right[i + 1], nums[i]);
            }
            int[] res = new int[nums.length - k + 1];
            for(int i = 0;i < res.length;i++) {
                res[i] = Math.max(right[i], left[i + k - 1]);
            }
            return res;
        }
    }