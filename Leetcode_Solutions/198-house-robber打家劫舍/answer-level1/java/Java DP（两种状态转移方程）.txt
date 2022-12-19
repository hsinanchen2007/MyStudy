分析：
每个房屋，都分偷或不偷两种情况：
那么可以定义一个二维数组dp[i][0,1]，第二纬表示状态，用1、0分别为偷或不偷。
对于当前房屋偷的情况，金额就是前一房屋不偷+当前房屋偷的金额：dp[i][1]=dp[i - 1][0]+nums[i]
对于当前房屋不偷的情况，有分两种情况，要么前一房屋也没偷，要么前一房屋偷了，取较大值，所以dp[i][0]=max(dp[i-1][0],dp[i-1][1])
DP方程：
dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1])
dp[i][1] = dp[i - 1][0] + nums[i]
```java
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int[][] dp = new int[nums.length][2];
        dp[0][1] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return Math.max(dp[nums.length - 1][0], dp[nums.length - 1][1]);
    }
}
```
简化
```java
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int robMax = nums[0], notRobMax = 0, tmp;
        for (int i = 1; i < nums.length; i++) {
            tmp = notRobMax;
            notRobMax = Math.max(robMax, notRobMax);
            robMax = tmp + nums[i];
        }
        return Math.max(robMax, notRobMax);
    }
}
```
分析：
每个房屋，都分偷或不偷两种情况：
对于不偷的情况，当前房屋没有任何进账，所以金额直接就是前一家房屋的金额，即dp[i]=dp[i-1]
对于偷的情况，当前房屋要偷，那必然前一家房屋不能偷，而前一家不偷的情况即上一种情况，换成表达式就是dp[i-1]=dp[i-2]，那么对于当前房屋偷的情况，就是dp[i]=dp[i-1][不偷]+nums[i]=dp[i-2]+nums[i]
DP方程：
dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i])
```java
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];

        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(dp[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.length - 1];
    }
}
```
简化
```java
class Solution {
    public int rob(int[] nums) {
        int prevMax = 0, currMax = 0, tmp;
        for (int num : nums) {
            tmp = currMax;
            currMax = Math.max(currMax, prevMax + num);
            prevMax = tmp;
        }
        return currMax;
    }
}
```

