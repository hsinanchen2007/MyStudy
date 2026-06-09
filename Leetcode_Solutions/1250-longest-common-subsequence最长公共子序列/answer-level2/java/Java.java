### 解题思路
先确定string长度，循环不需要减去1
如果先扩展了字符串，再取长度和没扩展效果一样

### 代码

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        
        //i?j
        //dp[i][j] 表示ij结尾的公共子序列集合
        int m = text1.length();
        int n = text2.length();

        text1 = ' ' + text1;
        text2 = ' ' + text2;

        System.out.println(text1 + ""+m);
        int[][] dp = new int[m + 1][n + 1];
        for(int i =1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                if(text1.charAt(i) == text2.charAt(j))dp[i][j] = Math.max(1 + dp[i -1][j - 1], dp[i][j]);
            }
        }
        return dp[m][n];

    }

    /*
    public int longestCommonSubsequence(String text1, String text2) {
        
        //i?j
        //dp[i][j] 表示ij结尾的公共子序列集合
        int m = text1.length();
        int n = text2.length();


        System.out.println(text1 + ""+m);
        int[][] dp = new int[m + 1][n + 1];
        for(int i =1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                if(text1.charAt(i - 1) == text2.charAt(j - 1))dp[i][j] = Math.max(1 + dp[i -1][j - 1], dp[i][j]);
            }
        }
        return dp[m][n];

    }
    */
}
```