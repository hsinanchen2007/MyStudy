```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(null==nums || nums.length==0) return new int[]{-1,-1};
        int leftIndex = -1;
        int rightIndex = -1;
        int tempLeft = getIndex(nums,target,true);
        if(nums[tempLeft]==target) {
            leftIndex = tempLeft;
        }else if(tempLeft<nums.length-1 && nums[tempLeft+1]==target) {
            leftIndex = tempLeft + 1;
        }

        int tempRight = getIndex(nums,target,false);
        if(nums[tempRight]==target) {
            rightIndex = tempRight;
        }else if(tempRight>0 && nums[tempRight-1]==target) {
            rightIndex = tempRight - 1;
        }
        return new int[]{leftIndex,rightIndex};
    }

    private int getIndex(int[] nums,int target,boolean left) {
       int start = 0;
       int end = nums.length - 1;
       while(start<end) {
           int mid = start + (end - start)/2;
           if(nums[mid] > target || nums[mid]==target && left) { 
               end = mid - 1;
           }else {
               start = mid + 1;
           }
       }
      return start;
    }
}
```
