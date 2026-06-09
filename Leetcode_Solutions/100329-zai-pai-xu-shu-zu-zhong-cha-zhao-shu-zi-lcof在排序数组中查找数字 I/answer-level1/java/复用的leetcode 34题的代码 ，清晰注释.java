```
class Solution {
    public int search(int[] nums, int target) {
        int a = searchLowerBound(nums,target,0,nums.length-1);
        int b = searchUpperBound(nums,target,0,nums.length-1);
        if(a == -1 || b == -1){
            return 0;
        }else{
            return b + 1 - a;
        }
    }
     private int searchUpperBound(int[] nums,int target,int low,int high) {
        if (low > high) {
            return -1;
        }

        int middle = low + (high - low) / 2;

        //判断是否是上边界时，先看看 middle 的数是否为 target，并判断该数是否已为数组的最后一个数，或者，它右边的数是不是比它大，如果都满足，即为上边界。    
        if (nums[middle] == target && (middle == nums.length - 1 || nums[middle + 1] > target)) {
            return middle;
        }

        if (target < nums[middle]) {
            return searchUpperBound(nums, target, low, middle - 1);
        } else {
            return searchUpperBound(nums, target, middle + 1, high);
        } //不满足时，需判断搜索方向。
    }

    private int searchLowerBound(int[] nums,int target,int low,int high){
        if (low > high) {
            return -1;
        }

        int middle = low + (high - low) / 2;
        //判断是否是下边界时，先看看 middle 的数是否为 target，并判断该数是否已为数组的第一个数，或者，它左边的一个数是不是已经比它小，如果都满足，即为下边界。
        if (nums[middle] == target && (middle == 0 || nums[middle - 1] < target)) {
            return middle;
        }

        if (target <= nums[middle]) {
            return searchLowerBound(nums, target, low, middle - 1);
        } else {
            return searchLowerBound(nums, target, middle + 1, high);
        } //不满足，如果这个数等于 target，那么就得往左边继续查找。
    }
}
```
