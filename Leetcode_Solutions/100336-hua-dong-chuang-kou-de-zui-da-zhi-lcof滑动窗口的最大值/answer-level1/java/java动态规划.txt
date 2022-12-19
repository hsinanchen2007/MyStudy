首先使用的暴力法
```
public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) {return new int[0];}
        int[] ans = new int[nums.length - k + 1];
        Arrays.fill(ans,Integer.MIN_VALUE);
        for (int i = 0; i < k; i++) {
            ans[0] = Math.max(ans[0],nums[i]);
        }
        for (int i = 1; i <ans.length; i++) {
            for (int j = i; j <= i + k - 1 ; j++) {
                ans[i] = Math.max(ans[i],nums[j]);
            }
        }
        return ans;
    }
```

因为暴力法每次都有重复计算数，有重复子问题，所以可以用动态规划优化一下
dp[i]的定义是索引从i到i+k-1这些数中的最大值
比如nums = [1,3,-1,-3,5,3,6,7], 和 k = 3 这题中，
dp[0]代表nums[0],nums[1],nums[2]中的最大值
dp[1]代表nums[1],nums[2],nums[3]中的最大值

状态转移方程：
因为dp[0]的时候已经算过nums[0],nums[1],nums[2]中的最大值了，
dp[1]需要计算的是nums[1],nums[2],nums[3].
然后他们之间的差别是nums[0]跟nums[3].
这时候分两种情况考虑
如果nums[0]就是nums[0],nums[1],nums[2]中的最大值了，也就是nums[0] == dp[0]
那么nums[1]只能重新计算了。
如果nums[0]不是nums[0],nums[1],nums[2]中的最大值， 也就是nums[0] != dp[0],
那么最大值在nums[1]和nums[2]之中，不用管最大值具体是哪个，反正dp[0]可以代表他们
所以
dp[1] = Math.Max(nums[1],nums[2],nums[3]),其中nums[1]和nums[2]可以用dp[0]代表，所以就变成了
dp[1] = Math.max(dp[0],nums[3]);
所以状态转移方程如下
```
if (nums[i-1] == dp[i-1]) {
    for (int j = i; j < i + k ; j++) {
        dp[i] = Math.max(dp[i],nums[j]);
    }
} else {
    dp[i] = Math.max(dp[i-1],nums[i+k-1])
}
```

完整代码如下

```
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) {return new int[0];}
        int[] dp = new int[nums.length - k + 1];
        Arrays.fill(dp,Integer.MIN_VALUE);
        for (int i = 0; i < k; i++) {
            dp[0] = Math.max(dp[0],nums[i]);
        }
        for (int i = 1; i <dp.length; i++) {
            if (dp[i-1] == nums[i-1]) {
                for (int j = i; j < i + k ; j++) {
                    dp[i] = Math.max(dp[i],nums[j]);
                }
            } else {
                dp[i] = Math.max(dp[i-1],nums[i+k-1]);
            }
        }
        return dp;
    }
```
