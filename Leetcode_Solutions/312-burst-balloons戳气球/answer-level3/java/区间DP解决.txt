**想法**
最值问题，容易联想到用DP解决,定义区间内戳破气球的收益，然后取最大值

**算法**
- 定义状态，定义2个变量i，j，dp[i][j]表示区间内的气球戳破的最大收益
- 选取i < k < j内的气球最后戳破，那么递推公式就是dp[i][j] = max(dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j])

**代码**
```
class Solution {
    public int maxCoins(int[] nums) {
        int size = nums.length + 2;
        int[] newNums = new int[size];
        int[][] dp = new int[size][size];
        for (int i = 0; i < nums.length; i++) {
            newNums[i + 1] = nums[i];
        }
        newNums[0] = 1;
        newNums[size - 1] = 1;
        
        for (int i = 2; i < size; i++) {
            for (int j = 0; j < size - i; j++) {
                for (int k = j + 1; k < j + i; k++) {
                    dp[j][j + i] = Math.max(dp[j][j + i], dp[j][k] + dp[k][i + j] + newNums[j] * newNums[k] * newNums[i + j]);
                    // System.out.println(dp[j][j + i]);
                }
            }
        }
        
        return dp[0][size - 1];
    }
}
```
