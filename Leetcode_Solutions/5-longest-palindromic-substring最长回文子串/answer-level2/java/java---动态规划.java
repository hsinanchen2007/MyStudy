
动态规划，空间换时间
dp[i][j]表示从i到j的字符是否为回文，状态转移方程为：
dp[i][j] = dp[i + 1][j - 1] && s.charAt(i) == s.charAt[j] st. j - i > 1
一开始的思路是： 两层遍历，i从0开始，j从0开始，但是发现这样会有中间状态没有计算到
故采取步长递增的方式计算

```
    public String longestPalindrome(String s) {
        if (s == null || s.length() <= 1) {
            return s;
        }
        boolean[][] dp = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
        }
        int max = 0;
        int[] dist = new int[2];
        // 步长从1到n
        // 步长为1， 看 0--1, 1--2, ... n-1--n
        // 步长为2， 看 0--2, 1--3, ... n-2--n
        // ...
        // 步长为n-1， 看0--n-1
        // 这样，每一步的状态都能通过状态转移方程计算得到
        for (int i = 1; i < s.length(); i++) {
            for (int j = 0; j + i < s.length(); j++) {
                dp[j][j + i] = i > 1 ?
                        (dp[j + 1][j + i - 1] && s.charAt(j) == s.charAt(j + i)) :
                        s.charAt(j) == s.charAt(j + i);
                if (dp[j][j + i] && i > max) {
                    max = i;
                    dist[0] = j;
                    dist[1] = j + i;
                }
            }
        }
        return s.substring(dist[0], dist[1] + 1);
    }
```