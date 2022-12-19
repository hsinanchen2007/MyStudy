### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        if(nums.length == 2) return nums[0] > nums[1]? nums[0] : nums[1];
        if(nums.length == 3) return nums[0] + nums[2] > nums[1]? nums[0] + nums[2] : nums[1];
        int[][] dp = new int[nums.length][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        int max = 0;
        for(int i = 1; i < nums.length; i++){
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);//今天没预约
            dp[i][1] = dp[i - 1][0] + nums[i];////今天有预约
        }
        for(int i = 0; i < dp.length; i++){
            if(max < dp[i][0]) max = dp[i][0];
            if(max < dp[i][1]) max = dp[i][1];
        }
        return max;
    }
}
```