### 解题思路
- 当匹配串的第 j+1个元素为 "*" 的时候：dp[i][j] = dp[i][j+2] || (temp && dp[i+1] [j])
- 否则：dp[i][j] = temp && dp[i+1][j+1]


### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        if(p.isEmpty()) return s.isEmpty();
        
        int sLen = s.length(), pLen = p.length();
        boolean[][] dp = new boolean[sLen+1][pLen+1];
        dp[sLen][pLen] = true;
        for(int i=sLen; i>=0; i--){
            for(int j=pLen-1; j>=0; j--){
                boolean temp = i < sLen && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
                if(j < pLen-1 && p.charAt(j+1) == '*'){
                    dp[i][j] = dp[i][j+2] || (temp && dp[i+1][j]);
                }else{
                    dp[i][j] = temp && dp[i+1][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
}
```