```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int i = leftBound(nums,target);
        int j = rightBound(nums,target);
        return new int[]{i,j};

    }
    int leftBound(int[] nums,int target){
        int left =0;
        int right = nums.length-1;
        while(left <= right){
            int mid = left + (right - left )/2;
           if(nums[mid] > target){
               right = mid-1;
           }else if(nums[mid] < target ){
               left = mid+1;
           }else {
               if(mid ==0||nums[mid-1]!=target){
                   return mid;
               }else{
                   right = mid -1;
               }
           }
        }
        return -1;
       
    }

    int rightBound(int[] nums,int target){
        int left = 0;
        int right = nums.length-1;
        while(left <= right){
            int mid = left + (right - left )/2;
            if(nums[mid] > target){
                right = mid-1;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                if(mid == nums.length-1 || nums[mid+1] != target){
                    return mid;
                }else{
                    left = mid +1;
                }
            }
        }
       return -1;
    }
}
```
