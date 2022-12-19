排序后，取中间的数。因为超过一半，那么位于中间的一定有这个数字。
```
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
```
