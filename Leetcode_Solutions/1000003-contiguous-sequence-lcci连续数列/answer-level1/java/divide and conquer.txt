    // 分治法
    class Solution {
        public int maxSubArray(int[] nums) {
            return divide(nums, 0, nums.length - 1);
        }

        public int divide(int[] nums, int left, int right) {
            if(left > right) {
                return Integer.MIN_VALUE;
            }
            if(left == right) {
                return nums[left];
            }
            int mid = left + (right - left) / 2;
            int leftnum = divide(nums, left, mid);
            int rightnum = divide(nums, mid + 1, right);
            int midleft = Integer.MIN_VALUE;
            int l = 0;
            for(int i = mid;i >= left;i--) {
                l += nums[i];
                midleft = Math.max(midleft, l);
            }
            int midright = Integer.MIN_VALUE;
            int r = 0;
            for(int i = mid + 1;i <= right;i++) {
                r += nums[i];
                midright = Math.max(midright, r);
            }
            int center = midleft + midright;
            return Math.max(center, Math.max(leftnum, rightnum));
        }
    }