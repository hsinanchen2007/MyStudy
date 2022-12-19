![image.png](https://pic.leetcode-cn.com/f136a4f2a8466b5c697e0807cb8b3f7ff40c613816dff6dbcb0db9b14ce76e4b-image.png)

```
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[] dp, lastdp;
        int i, j, ls, lp;
        char c;
        
        ls = s.length();
        lp = p.length();
        dp = new boolean[1+ls];
        lastdp = new boolean[1+ls];
        dp[0] = true;
        for(i = 0; i < lp; i++){
            for(j = 0; j < ls + 1; j++)
                lastdp[j] = dp[j];
            c = p.charAt(i);
            if(c == '*')
                dp[0] = lastdp[0];
            else
                dp[0] = false;
            for(j = 0; j < ls; j++)
                if(c == '*')
                    dp[j+1] = lastdp[j+1] || dp[j];
                else if(c == '?' || c == s.charAt(j))
                    dp[j+1] = lastdp[j];
                else
                    dp[j+1] = false;
                    
        }
        return dp[ls];
    }
}

```
