在题#33的基础上加一行代码，避免左区间的最小值等于右区间的最大值，对数组进行划分的条件仍然成立，这样原来的代码还能使用，复杂度与重合元素的数量有关，最坏情况下所有元素都一样复杂度是O(n)。
```
class Solution {
    public boolean search(int[] nums, int target) {
        if(nums == null || nums.length == 0) return false;
        int left = 0;
        int right = nums.length - 1;

        while(left <= right){
            
            // 避免左区间的最小值等于右区间的最大就还能使用#33的代码
            while(nums[left] == nums[right] && left < right) left++;

            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return true;
            // 区分 mid 落在那个区间
            if(nums[left] <= nums[mid]){
                // mid 落在左边的递增区间
                
                // 要查询的目标值在左区间 && 目标值小于 mid
                if( target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
                
            }else{
                // mid 落在右边的递增区间
                
                // 要查询的目标值在右区间 && 目标值大于 mid
                if(target <= nums[right] && target > nums[mid]){
                    left = mid + 1;
                }else{
                    right = mid -1;
                }
            }
        }
        return false;
    }
}
```
