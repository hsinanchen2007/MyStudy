```
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
}
```

执行用时 :4 ms, 在所有 Java 提交中击败了91.84%的用户
内存消耗 :38.4 MB, 在所有 Java 提交中击败了89.07%的用户
