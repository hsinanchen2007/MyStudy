dp[i][j]表示打印从i到j位置的子串，需要的最少的打印次数。
状态转移方程是
dp[i][j] = min{dp[i+1][nextIndex-1] +  dp[nextIndex][j], nextIndex是指与s[i]相同的下一个字符的index，遍历所有这样的位置}
所以我们需要预先计算好一个next数组

实际编程中有一个小trick，就是我们可以先找到第一个与s[i]不同的字符，以它作为起点进行遍历操作

```
  public int strangePrinter(String s) {
    if (s == null || s.length() == 0) {
      return 0;
    }
    if (s.length() == 1)
      return 1;
    int n = s.length();

    int[] next = new int[n];
    Arrays.fill(next, -1);
    Map<Character, Integer> map = new HashMap<>();
    for (int i = n-1; i >= 0; i--) {
      if (map.containsKey(s.charAt(i))) {
        next[i] = map.get(s.charAt(i));
      }
      map.put(s.charAt(i), i);
    }

    int[][] dp = new int[n][n];
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n-len; i++) {
        int j = i + len - 1;
        int iter = i+1;
        // find the first index that is different from the i-th char
        while (iter <= j && s.charAt(iter) == s.charAt(iter-1)) {
          iter++;
        }
        if (iter > j) {
          dp[i][j] = 1;
          continue;
        }
        int res = 1 + dp[iter][j];
        int nextIndex = next[iter-1];
        while (nextIndex <= j && nextIndex != -1) {
          res = Math.min(res, dp[iter][nextIndex-1] + (nextIndex <= j ? dp[nextIndex][j] : 0));
          nextIndex = next[nextIndex];
        }
        dp[i][j] = res;
      }
    }
    return dp[0][n-1];
  }
```
