没Java的，写一个。
解题思路是参考了上一篇帖子。
转移方程：
dp[2][n] = max(dp[2][n-1], dp[1][n-k] + sumRange(n, n -k+1))

易错点是当k=1的时候，边界条件需要处理一下。
```
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int[][] dp = new int[3][nums.length];
        int[] cummulative = new int[nums.length];
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            cummulative[i] = sum;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (j < (i + 1) * k - 1) {
                    dp[i][j] = 0;
                } else {
                    if (i == 0) {
                        // 易错点: 当k=1的时候，边界条件需要处理一下。
                        dp[i][j] = Math.max(j > 0 ? dp[i][j - 1] : 0, rangeSum(cummulative, j - k + 1, j));
                    } else {
                        dp[i][j] = Math.max(j > 0 ? dp[i][j - 1]: 0, rangeSum(cummulative, j - k + 1, j) + dp[i - 1][j - k]);
                    }
                }

            }
        }
        int[] ans = new int[3];
        int length = dp[2].length - 1;
        for (int i = 2; i >= 0; i--) {
            int[] row = dp[i];
            for (int j = length - 1; j >= 0; j--) {
                if (row[j] != row[length]) {
                    ans[i] = j - k + 2;
                    length = j - k + 1;
                    break;
                }
            }
        }
        return ans;
    }

    private int rangeSum(int[] cummulative, int left, int right) {
        if (left == 0) {
            return cummulative[right];
        } else {
            return cummulative[right] - cummulative[left - 1];
        }
    }
```
