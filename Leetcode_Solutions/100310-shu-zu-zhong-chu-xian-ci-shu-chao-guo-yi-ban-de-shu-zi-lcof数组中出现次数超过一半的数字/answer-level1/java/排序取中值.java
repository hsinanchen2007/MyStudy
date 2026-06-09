用java的内置函数、Arrays.sort进行排序，因为所求数字超过总数的一半，所以最中间的数字即为所求。
```
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
```