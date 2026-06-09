二分法
```
class Solution {
    public int searchInsert(int[] nums, int target) {
        int len = nums.length;
        int start = 0, end = len-1;
        int mid =0;
        if(target>nums[end]) return end+1;
        else if(target<nums[start]) return start;
        else{while(start<=end){
               mid = start+(end-start)/2;
               if(target > nums[mid]) start = mid+1;
               else if(target < nums[mid]) end = mid-1;
               else if(target == nums[mid]) return mid;
               }
             if(target>nums[mid]) return mid+1;
             else return mid;
        }
    }
}
```
