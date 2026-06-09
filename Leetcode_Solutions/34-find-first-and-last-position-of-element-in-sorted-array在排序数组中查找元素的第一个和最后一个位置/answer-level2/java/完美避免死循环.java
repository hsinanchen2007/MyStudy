```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = getLeft(nums,target);
        int right = getRight(nums,target);
        return new int[]{left,right};
    }
    private int getLeft(int[] nums,int target) {
        int left = 0;
        int right = nums.length-1;
        if(right<left) return -1; 
        while(left<right-1) {
            //放宽循环跳出条件，当剩下两个元素就跳出，这样一定会避免死循环
            int mid = left+right>>1;
            if(nums[mid]>target) right=mid-1;
            else if(nums[mid]==target) right = mid;
            else left = mid+1;
        }
        if(nums[left] == target) return left;
        //最后对两个元素单独判断
        if(nums[right]==target) return right;
        return -1;
    }
    private int getRight(int[] nums,int target) {
        int left = 0;
        int right = nums.length-1;
        if(right<left) return -1;
        while(left<right-1) {
            int mid = left+right>>1;
            if(nums[mid]>target) right=mid-1;
            else if(nums[mid]==target) left = mid;
            else left = mid+1;
        }
        if(nums[right]==target) return right;
        if(nums[left] == target) return left;
        return -1;
    }
}
```