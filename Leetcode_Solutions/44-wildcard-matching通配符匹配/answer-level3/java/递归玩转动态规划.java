
思路分析： 这题和第10题是一样的，只是'*'可以匹配的范围变简单了一点。下图是暴力递归的分析思路.
![通配符匹配](https://pic.leetcode-cn.com/4d4563897d92ad9e79b32fa3878f2420b6fd04054e9184d52ea4854ea6346d33.png)

暴力递归代码如下：
```
class Solution {    
    public boolean isMatch(String s, String p) {
        return getRes(s,s.length(),p,p.length());
    }

    private boolean getRes(String s, int cs, String p, int cp) {
        if(cp == 0) return cs == 0;
        if(cs == 0) {
            return p.charAt(cp - 1) == '*' && getRes(s,cs,p,cp - 1);
        }
        if(s.charAt(cs - 1) == p.charAt(cp - 1) || p.charAt(cp - 1) == '?'){
            return getRes(s,cs - 1,p,cp - 1);
        }
        if(p.charAt(cp - 1) == '*'){
            return getRes(s,cs - 1,p,cp) || getRes(s,cs,p,cp - 1) || getRes(s,cs - 1,p,cp- 1);
        }
        return false;
    }
}
```
使用二维数组进行优化，代码如下：
```
    // 动态规划优化
    public boolean isMatch(String s, String p) {
        if(p.equals("")) return s.equals("");
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= p.length(); j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                }else if(j == 0) {
                    dp[i][j] = false;
                }else if(i == 0) {
                    dp[i][j] = p.charAt(j - 1) == '*' && dp[i][j - 1];
                }else if(s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p.charAt(j - 1) == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
                }
            }
        }
        return dp[s.length()][p.length()];
    } 
```