### 解题思路
我来写个最简洁的版本。
### 代码

```java
class Solution {
    public boolean isMatch(String str, String pattern) {
        char[] s = str.toCharArray();
        char[] p = pattern.toCharArray();
        int m = s.length;
        int n = p.length;
        boolean[][] dp = new boolean[m+1][n+1];
        dp[0][0] = true;
        for(int j = 1; j < n+1; j++){
            if(j > 1 && p[j-1] == '*'){
               dp[0][j] = dp[0][j-2]; 
            }
        }
        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                if(p[j-1] != '*'){
                    dp[i][j] = isMatch(s[i-1],p[j-1]) && dp[i-1][j-1];
                }else{//*可以匹配0个和多个
                    dp[i][j] = dp[i][j-2] || (isMatch(s[i-1],p[j-2]) && dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
    private boolean isMatch(char a,char b){
        return (a == b || b == '.');
    }
}
```