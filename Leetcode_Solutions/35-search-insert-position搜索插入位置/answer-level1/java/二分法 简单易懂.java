```
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length<=0){
            return 0;
        }
        int start = 0;
        int end = nums.length-1;

        while(start <= end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                start = ++mid;
            }else if(nums[mid]>target){
                end = --mid;
            }
        }
        return start;
    }
}
```
