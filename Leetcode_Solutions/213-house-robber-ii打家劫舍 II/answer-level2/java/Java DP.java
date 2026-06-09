DP方程：
第一家偷的情况下，最后一家就不能偷：
dp1[0] = nums[0]
dp1[1] = dp1[0];
dp1[i] = i < lastIndex ? Math.max(dp1[i - 1], dp1[i - 2] + nums[i]) : dp1[i - 1]
第一家不偷的情况下，最后一家就能偷：
dp2[0] = 0
dp2[1] = nums[1]
dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + nums[i])

```java
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];

        int[] dp1 = new int[nums.length], dp2 = new int[nums.length];
        dp1[0] = nums[0];
        dp1[1] = dp1[0];
        dp2[1] = nums[1];
        int lastPos = nums.length - 1;

        for (int i = 2; i < nums.length; i++) {
            dp1[i] = i < lastPos ? Math.max(dp1[i - 1], dp1[i - 2] + nums[i]) : dp1[i - 1];
            dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return Math.max(dp1[lastPos], dp2[lastPos]);
    }
}
```

当然也可以换个思路：
max(job(nums, 0, nums.length - 1), job(nums, 1, nums.length))
```java
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        return Math.max(robHelper(nums, 0, nums.length - 1), robHelper(nums, 1, nums.length));
    }

    public int robHelper(int[] nums, int start, int end) {
        int prevMax = 0, currMax = 0, tmp;
        for (int i = start; i < end; i++) {
            tmp = currMax;
            currMax = Math.max(currMax, prevMax + nums[i]);
            prevMax = tmp;
        }
        return currMax;
    }
}
```
