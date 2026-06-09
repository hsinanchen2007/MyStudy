### 解题思路
dp[i][j]代表的是扎破i+1~j-1号气球，最多获得的金币数。

### 代码

```java
class Solution {
    public int maxCoins(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int[] A = new int[nums.length + 2];
        int n = A.length;
        A[0] = 1;
        A[n - 1] = 1;
        for (int i = 0; i < nums.length; i++) {
            A[i + 1] = nums[i];
        }


        int[][] dp = new int[n][n];
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
                }
            }
        }

        return dp[0][n - 1];
    }
}
```