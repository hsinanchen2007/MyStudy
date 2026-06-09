![image.png](https://pic.leetcode-cn.com/bdd78ace91cb5b4aa35d383547af60fea2e5e234a11249fd615c449cf3d0b6d4-image.png)

```
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp;
        int i, j, ls, lp;
        char c;

        ls = s.length();
        lp = p.length();
        dp = new boolean[lp+1][ls+1];
        //对空字符串的匹配
        dp[0][0] = true;
        for(i = 0; i < lp; i++)
            if(p.charAt(i) == '*')
                dp[i+1][0] = dp[i-1][0];
        for(i = 0; i < lp; i++){
            c = p.charAt(i);
            for(j = 0; j < ls; j++){
                if(c == '*')
                    //匹配          0个前字符       1个前字符      多个前字符      (s当前字符和p中*前字符一样    或者  *前是.  )
                    dp[i+1][j+1] = dp[i-1][j+1] || dp[i][j+1] || dp[i+1][j] && (s.charAt(j) == p.charAt(i-1) || p.charAt(i-1) == '.');
                else if(c == '.' || c == s.charAt(j))
                    dp[i+1][j+1] = dp[i][j];
                else
                    dp[i+1][j+1] = false;
            }
        }
        return dp[lp][ls];
    }
}
```
