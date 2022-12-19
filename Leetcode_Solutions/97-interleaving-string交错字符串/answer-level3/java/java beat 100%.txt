```
public class Solution {
    private boolean[][] dp;
    private char[] s1,s2,s3;

    private boolean helper(int i, int j, int k) {
        if (i == s1.length && j == s2.length) return true;
        if (i > s1.length || j > s2.length || dp[i][j]) return false;
        if (i < s1.length && s1[i] == s3[k] && helper(i + 1, j, k + 1)) {
            return true;
        }
        if (j < s2.length && s2[j] == s3[k] && helper(i, j + 1, k + 1)) {
            return true;
        }
        dp[i][j] = true;
        return false; // s1[i] != s3[k] && s2[j] != s3[k]
    }
    // 1ms 100%(中文) 0ms 100%(英文)
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length()+s2.length() != s3.length()) return false;
        dp = new boolean[s1.length()+1][s2.length()+1];
        this.s1 = s1.toCharArray();
        this.s2 = s2.toCharArray();
        this.s3 = s3.toCharArray();
        return helper(0,0,0);
    }
}
```
如果有帮助请点个赞吧^_^