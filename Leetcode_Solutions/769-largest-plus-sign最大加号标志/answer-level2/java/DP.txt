```
class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        if (N == 1) return mines.length == 0 ? 1: 0;
        
        int[][][] dp = new int[N][N][4];
        Set<Integer> ban = new HashSet<>();
        for (int[] arr : mines) {
            ban.add(arr[0] * N + arr[1]);
        }

        for (int i = 0 ; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int cur = ban.contains(i * N + j) ? 0 : 1;
                if (i == 0) {
                    dp[i][j][0] = cur;
                } else {
                    dp[i][j][0] = cur == 0? 0 : dp[i-1][j][0] + cur;
                }

                if (j == 0) {
                    dp[i][j][2] = cur;
                } else {
                    dp[i][j][2] = cur == 0? 0 : dp[i][j-1][2] + cur;
                }
            }
        }

        for (int i = N-1; i >=0; i--) {
            for (int j = N-1; j >=0;j--) {
                int cur = ban.contains(i * N + j) ? 0 : 1;
                if (i == N-1) {
                    dp[i][j][1] = cur;
                } else {
                    dp[i][j][1] = cur == 0? 0 : cur + dp[i+1][j][1];
                }

                if (j == N-1) {
                    dp[i][j][3] = cur;
                } else {
                    dp[i][j][3] = cur == 0? 0: cur + dp[i][j+1][3];
                }
            }
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                 int cur = ban.contains(i * N + j) ? 0 : 1;
                 if (cur == 0) continue;
                int value = Math.min(
                    Math.min(getSafe(i-1, j, dp, 0), getSafe(i+1, j, dp, 1)),
                    Math.min(getSafe(i, j-1, dp, 2), getSafe(i, j+1, dp, 3))
                ) + 1;
                res = Math.max(res, value);
            }
        }
        
        return res;

    }

    int getSafe(int i , int j, int[][][] dp, int idx) {
        int n = dp.length;

        if (i < 0 || i >= n || j < 0 || j >= n) return  0;
        return dp[i][j][idx];
    }
}
```
