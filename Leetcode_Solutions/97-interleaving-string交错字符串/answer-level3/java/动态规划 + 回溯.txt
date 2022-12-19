*经典动态规划*
- dp[i][j] 表示s1的前i个字符和s2的前j个字符能够组成s3的前（i + j）个字符
- 对dp[i][j] 初始化 : dp[0][0] = true, dp[i][0] 以及dp[0][j];
- dp[i][j] = (dp[i-1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[i][j-1] && s2.charAt(j - 1) == s3.charAt(i + j - 1))
```
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1 + len2 != len3) return false;
        boolean[][] dp = new boolean[len1 + 1][len2 + 1];
        dp[0][0] = true;
        for(int i = 1 ; i <= len1 ; i ++){
            if(dp[i-1][0]) dp[i][0] = s1.charAt(i - 1) == s3.charAt(i - 1);
            else break;
        }
        for(int j = 1 ; j <= len2 ; j ++){
            if(dp[0][j-1]) dp[0][j] = s2.charAt(j - 1) == s3.charAt(j - 1);
            else break;
        }
        for(int i = 1 ; i <= len1 ; i ++){
            for(int j = 1 ; j <= len2 ; j ++){
                dp[i][j] = (dp[i-1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[i][j-1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
            }
        }
        return dp[len1][len2];
    }
}
```
*回溯*
- isMatch(s1, s2, s3, l1, l2, l3) 表示s1 的前 l1 个字符，s2的前 l2个字符能否组成 s3的前l3个字符
- 超时
```
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        return isMatch(s1, s2, s3, 0, 0, 0);
    }
    public boolean isMatch(String s1, String s2, String s3, int l1, int l2, int l3){      
        if(l3 == s3.length()){
            return true;
        }
        char c1 = l1 == s1.length() ? ' ' : s1.charAt(l1);
        char c2 = l2 == s2.length() ? ' ' : s2.charAt(l2);
        char c3 = s3.charAt(l3);
        if(c1 != c3 && c2 != c3){
            return false;
        }
        if(c1 != c2){
            if(c1 == c3){
                return isMatch(s1, s2, s3, l1 + 1, l2, l3 + 1);
            }
            if(c2 == c3){
                return isMatch(s1, s2, s3, l1, l2 + 1, l3 + 1);
            }
        }
        else{
            if(c1 == c3){
                return isMatch(s1, s2, s3, l1 + 1, l2, l3 + 1) || isMatch(s1, s2, s3, l1, l2 + 1, l3 + 1);
            }
        }
        return false;
    }
}
```
