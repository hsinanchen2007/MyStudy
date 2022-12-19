```
class Solution {
    public int findMin(int[] nums) {
        if(nums==null||nums.length<1){
            return -1;
        }
        if(nums.length==1){
            return nums[0];
        }
        int start = 0;
        int end = nums.length-1;
        if(nums[start]<nums[end]){
            return nums[start];
        }
        
        while (start<=end){
            int mid = (start+end)/2; 
            if(mid<nums.length-2&&nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            if(mid>1&&nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            if(nums[start]<nums[mid]){
                start=mid+1;
            }else if(nums[start]>nums[mid]){
                end = mid-1;
            }else{
                int min = nums[start];
                for(int i = start+1;i<=end;i++){
                    min=Math.min(nums[i],min);
                }
                return min;
            }
        }
        return -1;
        
    }
}
```
