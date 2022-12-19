### 解题思路
1. 递归实现会超时，代码如下：
### 代码
```java
class Solution {
    public int massage(int[] nums) {
        if (nums == null) return 0;
        if (nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        if (nums.length == 2) return Math.max(nums[0], nums[1]);
        return getLongestTime(0, nums);
    }

    private int getLongestTime(int begin, int[] nums) {
        if (begin == nums.length - 1) return nums[begin];
        if (begin > nums.length - 1) return 0;
        int tmp1 = Math.max(nums[begin] + getLongestTime(begin + 2, nums), nums[begin] + getLongestTime(begin + 3, nums));
        int tmp2 = Math.max(nums[begin + 1] + getLongestTime(begin + 3, nums), nums[begin] + getLongestTime(begin + 4, nums));
        return Math.max(tmp1, tmp2);
    }
}
```

2. 利用动态规划实现，dp[i] = max(dp[i-1], dp[i-2] + nums[i]) 
### 代码

```java
class Solution {
   public int massage(int[] nums) {
        if (nums == null) return 0;
        if (nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        if (nums.length == 2) return Math.max(nums[0], nums[1]);

        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return Math.max(dp[nums.length - 2], dp[nums.length - 1]);
    }

}
```