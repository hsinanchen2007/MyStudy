

按摩师前一天只有两种状态:**有预约和没预约**。

1. 无预约：直接加上新的数值
2. 有预约：取消前一天的预约换成当前的新预约，或者不取消

```
    public static int massage(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        boolean last = true; // 前一天的预约状态
        for (int i = 2; i <= nums.length; i++) {
            if (!last) {
                // 无预约直接预约
                dp[i] = dp[i-1] + nums[i - 1];
                last = true;
            } else {
                if (dp[i - 2] + nums[i - 1] > dp[i - 1]) {
                    // 取消前一天的预约换成新的
                    dp[i] = dp[i - 2] + nums[i - 1];
                } else {
                    // 不取消预约，今天状态修改为无预约
                    dp[i] = dp[i - 1];
                    last = false;
                }
            }
        }
        return dp[nums.length];
    }
```
