在打家劫舍1的基础上稍微修改加几行代码即可，分两种情况，第一种，第一家不偷，偷到最后一家，第二种情况，偷第一家，但最后一家不偷，用两个dp数组分别保存这两种情况的结果，然后取两者的较大值即可，直接上代码：
```
    public static int rob(int[] nums) {
        int len = nums.length;
        if(len == 0) {
            return 0;
        }
        if(len == 1) {
            return nums[0];
        }
        if(len == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int[] dp = new int[len];
        int[] dp2 = new int[len];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int r=2; r<len; r++) {
            dp[r] = Math.max(dp[r-1], dp[r-2] + nums[r]);
            dp2[r] = Math.max(dp2[r - 1], dp2[r-2] + nums[r]);
        }
        return Math.max(dp[len - 2], dp2[len - 1]);
    }
```
