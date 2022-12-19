# DP
**状态定义:** 
用dp[i][]表示以i结尾的乘积, dp[i][0]存储最小值, dp[i][1]存储最大值

**状态转移方程:**

`dp[i + 1][0] = Math.min(dp[i][0] * num, dp[i][1] * num, num);`
`dp[i + 1][1] = Math.max(dp[i][0] * num, dp[i][1] * num, num);`

# 代码
```
class Solution {
    public int maxProduct(int[] nums) {
        int[][] dp = new int[nums.length][2];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int max = nums[0];

        for (int i = 1; i < nums.length; ++i) {
            dp[i][0] = Math.min(Math.min(dp[i-1][0] * nums[i], dp[i-1][1] * nums[i]), nums[i]);
            dp[i][1] = Math.max(Math.max(dp[i-1][0] * nums[i], dp[i-1][1] * nums[i]), nums[i]); 
            max = Math.max(max, dp[i][1]);
        }
        return max;        
    }
}
```
时间复杂度: O(n)
空间复杂度: O(n)
# 空间优化
**由于dp[n+1]每次只需要用到dp[n], 可以采用2x2的数组实现**
```
class Solution {
    public int maxProduct(int[] nums) {
        int[][] dp = new int[2][2];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int max = nums[0];

        for (int i = 1; i < nums.length; ++i) {
            int x = i % 2;
            int y = (i - 1) % 2;
            dp[x][0] = Math.min(Math.min(dp[y][0] * nums[i], dp[y][1] * nums[i]), nums[i]);
            dp[x][1] = Math.max(Math.max(dp[y][0] * nums[i], dp[y][1] * nums[i]), nums[i]); 
            max = Math.max(max, dp[x][1]);
        }
        return max;        
    }
}
```
时间复杂度: O(n)
空间复杂度: O(1)