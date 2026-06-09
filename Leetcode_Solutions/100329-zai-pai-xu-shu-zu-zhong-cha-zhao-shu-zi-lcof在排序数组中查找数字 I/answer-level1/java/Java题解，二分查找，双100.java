```
class Solution {
    public int search(int[] nums, int target) {
        return searchIndex1(nums,target)-searchIndex2(nums,target)+1;
    }
    public int searchIndex1(int[] nums, int target) {
        int low= 0;
        int high = nums.length-1;
        while(low<=high){  // 找出出现的最后一个位置
            int mid = (high+low)/2;
            if(nums[mid]<=target){
                low=mid+1;
            }else {
                high=mid-1; 
            }
        }
        return high;
    }
    public int searchIndex2(int[] nums, int target) {
        int low= 0;
        int high = nums.length-1;
        while(low<=high){ // 找出出现的第一个位置
            int mid = (high+low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }else {
                high=mid-1; 
            }
        }
        return low;
    }
}
```
