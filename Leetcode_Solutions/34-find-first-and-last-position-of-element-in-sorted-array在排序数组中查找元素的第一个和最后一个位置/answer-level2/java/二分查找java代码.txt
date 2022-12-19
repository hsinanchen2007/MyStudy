二分法，找到目标值之后，左右查找边界



class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] targetRange = {-1, -1};
        if (nums == null || nums.length == 0) {
            return targetRange;
        }
        int start = 0;
        int end = nums.length - 1;
        int mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                int pre = mid;
                int after = mid;
                while (pre >=0  && nums[pre] >= target){
                     pre--;
                }
                while (after <= nums.length - 1 && nums[after] <= target ){
                     after = after +1;
                }
                targetRange[0] = pre+1;
                targetRange[1] = after-1;
                return targetRange;
            }
            //前半部分有序,注意此处用小于等于
            if (nums[start] <= nums[mid]) {
                //target在前半部分
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target <= nums[end] && target > nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return targetRange;
    }
}
