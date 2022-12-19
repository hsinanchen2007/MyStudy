```java
class Solution {
    private int[][] dp;

    private void kmp(String pat) {
        int m = pat.length();
        dp = new int[m][256];
        dp[0][pat.charAt(0)] = 1;
        int X = 0;
        for (int j = 1; j < m; j++) {
            for (int c = 0; c < 256; c++) {
                if (pat.charAt(j) == c)
                    dp[j][c] = j + 1;
                else
                    dp[j][c] = dp[X][c];
            }
            X = dp[X][pat.charAt(j)];
        }
    }

    public int strStr(String a, String b) {
        if (b.equals(""))
            return 0;
        if (a.length() < b.length())
            return -1;
        int n = a.length();
        int m = b.length();
        kmp(b);
        int j = 0;
        for (int i = 0; i < n; i++) {
            j = dp[j][a.charAt(i)];
            if (j == m)
                return i - j + 1;
        }
        return -1;
    }

}
```
