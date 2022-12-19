    
    class Solution {
        public int findMin(int[] nums) {
            if(nums.length == 1) {
                return nums[0];
            }
            int left = 0;
            int right = nums.length - 1;
            while(left < right) {
                int mid = (left + right) / 2;
                if(mid > 0 && nums[mid - 1] > nums[mid]) {
                    return nums[mid];
                }
                if(nums[mid] >= nums[left] && nums[mid] < nums[right]) {        // 严格递增
                    right = mid - 1;
                }else if(nums[mid] <= nums[left] && nums[mid] > nums[right]) {  // 严格递减
                    left = mid + 1;
                }else if(nums[mid] > nums[left] && nums[mid] > nums[right]){    // 数组有旋转，在旋转点左侧
                    left = mid + 1;
                }else {                                                         // 在旋转点右侧
                    right = mid - 1;
                }
            }
            return nums[left];     // 数组严格递增或递减时的最小值
        }
    }