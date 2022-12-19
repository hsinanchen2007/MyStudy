```
class Solution {
    public int missingNumber(int[] nums) {
        int low = 0;
        int high = nums.length-1;
        while(low<=high){
            int mid = (low+high)>>>1;
            if(nums[mid]==mid){
                low=mid+1;
            }else if(nums[mid]>mid){ // 根据当前位置元素值和下标做比较
                high=mid-1;
            }
        }
        return low;
    }
}
```
