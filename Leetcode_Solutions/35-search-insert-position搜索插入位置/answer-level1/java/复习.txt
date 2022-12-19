    
    class Solution {
        // 其实就是找第一个大于target数的位置
        public int searchInsert(int[] nums, int target) {
            if(nums[nums.length - 1] < target) {
                return nums.length;
            }
            int left = 0;
            int right = nums.length - 1;               // 也可以是right = nums.length，这样就省了上面的判断
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(nums[mid] == target) {
                    return mid;
                }else if(nums[mid] > target) {
                    right = mid;
                }else {
                    left = mid + 1;
                }
            }
            return left;
        }
    }