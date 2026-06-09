#### 在写这道题目之前，我们需要知道：每个元素上方所能容纳的雨水的量为该元素的左右两侧最大高度的较小者减去此元素的高度
```java
class Solution {
    public int trap(int[] height) {
        //动态规划，时间O(N) 空间O(N)
        if (height.length == 0) return 0;
        //状态转移方程，每个值分别代表该元素的左边的最大高度和右边的最大高度
        int[][] dp = new int[height.length][2];
        //初始值
        //第一个元素左边的最大高度为0
        dp[0][0] = 0;
        //最后一个元素左边的最大高度为0
        dp[height.length - 1][1] = 0;
        //填状态转移方程
        //从左往右填每个元素左边的最大高度
        for (int i = 1; i < height.length; i ++ ) dp[i][0] = Math.max(height[i - 1], dp[i - 1][0]);
        //从右往左填每个元素右边的最大高度
        for (int i = height.length - 2; i >= 0; i -- ) dp[i][1] = Math.max(height[i + 1], dp[i + 1][1]);
        int ans = 0;
        //遍历累加每个元素上方所能容纳的雨水的容量：Math.min(dp[i][0], dp[i][1]) - height[i]，即左边和右边的最大高度的更小的那个减去当前元素的高度
        for (int i = 0; i < height.length; i ++ ) {
            if (dp[i][0] < height[i] || dp[i][1] < height[i]) continue;    //如果左边或者右边的最大高度比当前值还要小，则该元素上方没有雨水
            ans += Math.min(dp[i][0], dp[i][1]) - height[i];
        }
        return ans;
    }
}
```