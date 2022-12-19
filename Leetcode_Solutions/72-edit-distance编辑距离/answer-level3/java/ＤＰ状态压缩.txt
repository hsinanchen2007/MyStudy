废话不说了，　直接上代码。


class Solution {
    public int minDistance(String word1, String word2) {
        int M = word1.length();
        int N = word2.length();
        if (M * N == 0) {
            return M + N;
        }

        int[] dp = new int[N + 1];
        for (int j = 0; j <= N; j++) {
            dp[j] = j;
        }
        

        for (int i = 1; i <= M; i++) {
            // 关键代码：此处需要设置初始值，相当于二维ｄｐ的dp[i-1][0]
            dp[0] = i - 1;
            int pre = dp[0];

            for (int j = 1; j <= N; j++) {
                int temp = pre;
                if (word1.charAt(i-1) != word2.charAt(j-1)) {
                    temp += 1;
                }
                pre = dp [j];
                dp[j] = Math.min(temp, Math.min(dp[j], dp[j - 1]) + 1);
            }
        }
        return dp[N];

    }
}