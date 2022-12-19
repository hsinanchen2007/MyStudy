* dp[i][j]表达从i到j的最长回文序列长度
* 由于是回文串所以要从左右一起判断
* 如果i和j的位置字符相等，则在i+1到j-1的最值上加2.若不相等，则取i+1到j和i到j-1中的最大值
* 从递推式可知，只需要两行l长度的数组即可，通过求余的方式交替使用这两行

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int l = s.length();
        if(l==0){
            return 0;
        }
        int[][] dp = new int[2][l];
        int idx = 0;
        int pre = 0;
        for(int i = l-1;i>=0;i--){
            idx = i % 2;
            pre = 1 - idx;
            dp[idx][i] = 1;
            for(int j = i + 1;j<l;j++){
                if(s.charAt(i) == s.charAt(j)){
                    if(j - i == 1){
                        dp[idx][j] = 2;
                    }
                    else{
                        dp[idx][j] = dp[pre][j-1] + 2;
                    }
                }
                else{
                    dp[idx][j] = Math.max(dp[pre][j], dp[idx][j-1]);
                }
            }
            // for(int k = 0 ;k<l;k++){
            //     System.out.print(dp[idx][k]);
            // }
            // System.out.println();
        }
        return dp[idx][l-1];
    }
}
```