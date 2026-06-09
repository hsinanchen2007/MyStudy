题解里少有这种解法，将已遍历的元素num[i]作为索引所在的值置为负数，如果置为负数时发现已经是负数，则说明这个数是第二次出现
```
class Solution {
    public int findDuplicate(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[Math.abs(nums[i])] > 0) {
                nums[Math.abs(nums[i])] *= -1;
            } else {
                return Math.abs(nums[i]);
            }
        }
        return 0;
    }
}
```
