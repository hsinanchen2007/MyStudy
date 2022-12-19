### 解题思路
两个游标 分别从s，p开头到结尾

dp[i][j] = dp[i+1][j+1] if p.(pi) == DOT ||  s.(si) == p.(pi)
dp[i][j] = dp[i][pi+2]||dp[i+1][pi+2]||dp[i+1][pi] 当遇上.* a*等，字母匹配

递归+数组记忆

### 代码

```java
class Solution {
    public static final char DOT='.';
    public static final char STAR='*';
    public boolean isMatch(String s, String p) {
        // 参数检查
        short[][] dp = new short[s.length()+1][p.length()+1];
        return match(0,0,s,p, dp);
    }
    boolean match(int si, int pi, String s, String p, short[][] dp) {
        if (si == s.length() && pi == p.length()) {
            return true;
        } else if (pi<p.length()) {
            if (si<s.length() && dp[si][pi]!=0) {
                return dp[si][pi]>0;
            }
            boolean res =false;
            // * 后追*处理
            if (pi+1<p.length() && p.charAt(pi+1)==STAR) {//*可以是0个或者多个

                res |= match(si, pi+2, s, p, dp); // 0个 s''  p 'c*'
                if (si<s.length()&&(p.charAt(pi)==DOT||s.charAt(si) == p.charAt(pi))) {
                    res |= match(si+1, pi+2, s, p, dp); //匹配1个 'a' 'a*'
                    res |= match(si+1, pi, s, p, dp); //匹配多个 a ''
                }
            } else {
                if (si<s.length()&&(p.charAt(pi) == DOT ||  s.charAt(si) == p.charAt(pi))) {
                    res = match(si+1, pi+1, s, p, dp);
                }
            }
            if (res) {
                dp[si][pi] = 1;
            } else {
                dp[si][pi] = -1;
            }
            return res;
        }
        if (si<=s.length()&&pi<=p.length()) {
            dp[si][pi] = -1;
        }
        return false;
    }
}
```