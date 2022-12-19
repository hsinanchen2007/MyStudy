将大问题分析成小问题。
接或不接，成为一个关键突破点：
1：接，0：不接

```
我不接第i位客人有两种情况：1. 第 i - 1 位客人已经接了，当前这个客人不能接了，会累死俺 2. 第 i - 1 位客人，不好看俺也不接
dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]) 
我接第i位客人有两种情况：1. 第 i - 1 位客人没接，休息好了，能接了。 2. 第 i - 1 位客人，太好看俺接了。
dp[i][1] = max(dp[i - 1][0] + nums[i], dp[i - 1][1])
// 计算最大值
ans = ax(dp[i][0], dp[i][1])
```

```
class Solution {
    public int massage(int[] nums) {
        // 常规判断
        int n = nums.length;
        if(n == 0) {
            return 0;
        }
        int[][] dp = new int[nums.length][2];
        // 初始化状态定义
        dp[0][0] = 0;        
        dp[0][1] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i][0] = Math.max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = Math.max(dp[i - 1][0] + nums[i], dp[i - 1][1]);
            ans = Math.max(dp[i][0], dp[i][1]);
        }
        return ans;
    }
}
```
