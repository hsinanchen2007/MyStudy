```
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int mid = nums.length/2;
        return target == nums[mid]&&target==nums[mid-1] ? true:false;
    }
}
```
