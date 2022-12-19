public int[] countBits(int num) {
        int k = 0;
        int[] dp  = new int[num + 1];
        for (int i = 1; i <= num; i++) {
            if (i <= 2 * k + 1) {
                dp[i] = 1 + dp[i - k - 1];
            } else {
                dp[i] = 1;
                k = i - 1;
            }
        }
        return dp;
}