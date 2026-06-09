```
class Solution {
    public int search(int[] nums, int target) {
        if(nums == null || nums.length == 0) return 0;
        int left1 = 0,right1 = nums.length;
        while(left1 < right1){  //找第一次出现的位置
            int mid = left1 + (right1 - left1) / 2;
            if(nums[mid] < target) left1 = mid + 1;
            else right1 = mid;
        }
        int left2 = 0,right2 = nums.length;
        while(left2 < right2){ //找最后一次出现的位置
            int mid = (left2 + right2) >>> 1;
            if(nums[mid] > target) right2 = mid;
            else left2 = mid + 1;
        }
        return right2 - left1;
    }
}
```
