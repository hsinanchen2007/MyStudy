![image.png](https://pic.leetcode-cn.com/26f5b5054a239b4fd91aa6df2d09006a7eb9faf2608bf53f6ae39b83cca5c076-image.png)

```
class Solution {
    public int findMin(int[] nums) {
        if(nums[0] <= nums[nums.length-1])
            return nums[0];
        return findMinHelper(nums, 0, nums.length);
    }

    private int findMinHelper(int[] nums, int start, int end){
        int mid;

        mid = (start + end) / 2;
        if(nums[mid] < nums[mid-1])
            return nums[mid];
        if(nums[start] < nums[mid])
            return findMinHelper(nums, mid, end);
        return findMinHelper(nums, start, mid);
    }
}
```
