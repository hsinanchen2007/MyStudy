* 1. 時間： 2ms, 100%; 內存： 38.6MB，96.19%
     * 2. 和之前一道题很相似，就是正反两次遍历。正向遍历是最小，反向再最小的基础上加上，还是最小。
     * 3. 只要是和身边的对比，利用这种方法就很好。
```
public int candy(int[] ratings) {
        int[] dp = new int[ratings.length];
        dp[0] = 1;
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }

        dp[0] = 1;
        for (int i = dp.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && dp[i] <= dp[i + 1]) {
                dp[i] = dp[i + 1] + 1;
            }
        }
        int amount = 0;
        for (int i = 0; i < ratings.length; i++) {
            // System.out.print(dp[i] + " ");
            amount += dp[i];
        }
        // System.out.println();
        return amount;
    }
```
