这道题的想法其实很简单，就是针对每个点的上下左右四个方向分别算最大能延伸多少，取最小值，每个方向用一次dp，
当然某方向用完之后，dp数组就不需要再用了，所以可以复用这个dp数组，每次使用之前reset一下。

```
  public int orderOfLargestPlusSign(int N, int[][] mines) {
    int[][] dp = new int[N][N];
    reset(N, dp, mines);
    for (int i = 1; i < N-1; i++) {
      for (int j = 1; j < N-1; j++) {
        if (dp[i][j] != 0) {
          dp[i][j] = dp[i-1][j]+1;
        }
      }
    }
    int[][] dp2 = new int[N][N];
    reset(N, dp2, mines);
    for (int i = N-2; i >= 1; i--) {
      for (int j = 1; j < N-1; j++) {
        if (dp2[i][j] != 0) {
          dp2[i][j] = dp2[i+1][j]+1;
          dp[i][j] = Math.min(dp[i][j], dp2[i][j]);
        }
      }
    }
    reset(N, dp2, mines);
    for (int j = 1; j < N; j++) {
      for (int i = 1; i < N-1; i++) {
        if (dp2[i][j] != 0) {
          dp2[i][j] = dp2[i][j-1]+1;
          dp[i][j] = Math.min(dp[i][j], dp2[i][j]);
        }
      }
    }
    reset(N, dp2, mines);

    for (int j = N-2; j >= 1; j--) {
      for (int i = 1; i < N-1; i++) {
        if (dp2[i][j] != 0) {
          dp2[i][j] = dp2[i][j+1]+1;
          dp[i][j] = Math.min(dp[i][j], dp2[i][j]);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        res = Math.max(res, dp[i][j]);
      }
    }
    return res;
  }

  private void reset(int N, int[][] dp, int[][] mines) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j] = 1;
      }
    }
    if (mines != null && mines.length > 0 && mines[0].length > 0) {
      for (int[] mine : mines) {
        dp[mine[0]][mine[1]] = 0;
      }
    }
  }
```
