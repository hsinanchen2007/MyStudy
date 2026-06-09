```
class Solution {
    public int coinChange(int[] arr, int aim) {
        if (arr == null || arr.length == 0 || aim < 0) {
            return -1;
        }

        int N = arr.length;
        //dp[i][j]-->任意使用arr[i...N]的货币组成j的最少张数
        int[][] dp = new int[N + 1][aim + 1];
        // 设置最后一排的值，除了dp[N][0]为0之外，其他都是-1
        for (int col = 1; col <= aim; col++) {
            dp[N][col] = -1;
        }

        //对于每张货币都有两个选择
        //选择这个货币：dp[i][j] = dp[i][j-arr[i]]+1
        //不选择：dp[i][j] = dp[i+1][j]
        //dp[i][j] = min(dp[i+1][j],dp[i][j-arr[i]+1)
        for (int i = N - 1; i >= 0; i--) { // 从底往上计算每一行
            for (int rest = 0; rest <= aim; rest++) { // 每一行都从左往右
                dp[i][rest] = -1; // 初始时先设置dp[i][rest]的值无效
                if (dp[i + 1][rest] != -1) { // 下面的值如果有效
                    dp[i][rest] = dp[i + 1][rest]; // dp[i][rest]的值先设置成下面的值
                }
                // 左边的位置不越界并且有效
                if (rest - arr[i] >= 0 && dp[i][rest - arr[i]] != -1) {
                    if (dp[i][rest] == -1) { // 如果之前下面的值无效
                        dp[i][rest] = dp[i][rest - arr[i]] + 1;
                    } else { // 说明下面和左边的值都有效，取最小的
                        dp[i][rest] = Math.min(dp[i][rest],
                                dp[i][rest - arr[i]] + 1);
                    }
                }
            }
        }
        return dp[0][aim];
    }
}
```