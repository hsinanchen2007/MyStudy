评论区也没看见个讲为什么的，题目用动态规划解（解题去很多，就不细讲了），就是填一个二维表格。每个格子对应两种状态：
    首先搞清楚dp[i][j]、dp[i][j-1]、dp[i-1][j-1]的含义；说白了，i,j就是代表t，s两个字符串的长度，即t[0:i],s[0:j]
1.t[i]==s[j]   dp[i][j] = dp[i][j-1]+dp[i-1][j-1]
    现在是两个字符相等，dp[i][j-1]的意思就是看一下t[i]与s[j] 不相匹配（不是说不相等），
    dp[i-1][j-1]就是扩展的时候喽，把t[i]固定的匹配s[j].看之前有几种情况，
    两种不会出现交集的，因为s长度不同；
2.t[i]≠ s[j]   dp[i][j] = dp[i][j-1]
    不相等就相当于 s没添加字符一样，所以就等于s[j-1]的情况
```
class Solution {
    public int numDistinct(String s, String t) {
        int[][] dp = new int[t.length()+1][s.length()+1];
        for(int i =0;i<s.length()+1 ; i++)
            dp[0][i] = 1;
        for(int i=1;i<t.length()+1;i++){
            for(int j=i;j<s.length()+1;j++){
                if(t.charAt(i-1) == s.charAt(j-1)){
                    dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];//说明S加一个字符不起作用
                }
            }
        }
        return dp[t.length()][s.length()];
    }
}
```