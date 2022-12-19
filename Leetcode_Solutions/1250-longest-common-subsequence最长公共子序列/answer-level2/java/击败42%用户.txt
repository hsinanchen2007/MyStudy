### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        if(n1 == 0 || n2 == 0){
            return 0;
        }
        // dp[i][j]记录text1前i个字符与text2前n2个字符 的最长公共子序列
        int[][] dp = new int[n1+1][n2+1];
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(text1.charAt(i-1) == text2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];

    }
}
```