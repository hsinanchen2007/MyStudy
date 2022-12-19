## 分析：
- 这道题与另一道动态规划题打家劫舍几乎一模一样，状态转移方程基本没差。
- 首先，我们应当使用一个计数方法把相同值放在一起。
- 如果你不了解计数，可以看leet1122题，以及我写的一篇题解。
- > https://leetcode-cn.com/problems/relative-sort-array/solution/ji-shu-pai-xu-fei-chang-jian-dan-gao-ding-by-rippl/
- 我们先来看最通俗版本，我们用两个状态，在当前第i位时拿或不拿，拿为0，不拿为1。
    - 如果当前位置拿，那么要么是前一个位置没拿，要么是前两个位置拿了现在再拿。
    - 如果当前位置不拿，那么要么是前一个位置拿了，要么是前一个位置不拿现在依然不拿。
- 再来看看优化后的版本，我们发现不管拿或不拿，我们都要判断前一个位置不拿的情况。因此我们可以直接判断出最优情况，也就是说，拿与不拿的状态可以省略，可以直接比较拿或不拿找到当前位置的最优解。

## 代码：
- 初始版本：
```java
class Solution {
    public int deleteAndEarn(int[] nums) {
        int len = nums.length;
        if (len == 0) return 0;
        int max = nums[0];
        for (int i = 0; i < len; i++) if (max < nums[i]) max = nums[i];max++;
        int[] arr = new int[max];
        int[][] dp = new int[max][2];
        for (int i = 0; i < len; i++) arr[nums[i]]++;
        // 0 获取 1 不获取
        dp[1][0] = arr[1];
     // dp[1][1] = 0;
        for (int i = 2; i < max; i++) {
            // 这两句代码中的其中一个比较是相同的。
            dp[i][0] = Math.max(dp[i-2][0] , dp[i-1][1]) + arr[i] * i;
            dp[i][1] = Math.max(dp[i-1][0], dp[i-1][1]);
        }
        return Math.max(dp[max-1][0], dp[max-1][1]);
    }
}
```
- 优化后：
```java
class Solution {
    public int deleteAndEarn(int[] nums) {
        int len = nums.length;
        if (len == 0) return 0;
        int max = nums[0];
        for (int i = 0; i < len; i++) if (max < nums[i]) max = nums[i];max++;
        int[] arr = new int[max];
        int[] dp = new int[max];
        for (int i = 0; i < len; i++) arr[nums[i]]++;
        dp[1] = arr[1];
        for (int i = 2; i < max; i++) {
            dp[i] = Math.max(dp[i-2] + arr[i] * i, dp[i-1]);
        }
        return dp[max-1];
    }
}
```