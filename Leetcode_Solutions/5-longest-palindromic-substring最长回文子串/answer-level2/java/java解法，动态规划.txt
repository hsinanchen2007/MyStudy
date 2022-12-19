### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if (s== null || s.length() <2) return s;
        
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        int start = 0;
        int maxLenth = 1;
        for(int i = 1;i < len;i++) {
            for (int j=0;j<i;j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    if (i - j < 3) {
                        dp[i][j]=true;
                    } else {
                        dp[i][j]=dp[i-1][j+1];
                    }
                } else {
                    dp[i][j]=false;
                }
              
                if (dp[i][j]) {
                    int currLenth = i - j + 1;
                    if (currLenth > maxLenth) {
                        maxLenth =  currLenth;
                        start = j;
                    }
                }
            }
                    
        }
        return s.substring(start, start + maxLenth);
    }
}
```