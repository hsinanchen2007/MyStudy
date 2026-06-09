
```Java []
class Solution {
    public int searchInsert(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            //如果当前元素大于等于目标值，则下标所在位置是目标值或者目标值应插入的位置
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.length;
    }
}
```