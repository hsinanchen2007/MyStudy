### 解题思路
1. 参考别人的题解，两种动态规划的写法，殊途同归。

### 代码

```java
class Solution {
    
    public int countSubstrings(String s) {
            int res = 0;
        boolean dp[][] = new boolean[s.length()][s.length()];
        for (int j = 0; j < s.length(); j++) {
            for (int i = j; i >= 0; i--) {
                if (s.charAt(i) == s.charAt(j) && ((j - i < 2) || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
}

 public int countSubstrings(String s) {
        if(s == null || s.length() == 0) return 0;
        int length = s.length(), count = 0;
        boolean[][] dp = new boolean[length][length];
        char[] sChar = s.toCharArray();
        for(int i = 0; i < length; i++){
            dp[i][i] = true;
            count++;
        }
        for(int i = 1; i < length; i++)
            for(int j = 0; j < length - i; j++){
                int row = j, col = i + j;
                boolean cur = sChar[row] == sChar[col];
                if(cur && (i == 1 || dp[row+1][col-1])){
                    dp[row][col] = true;
                    count++;
                }                    
            }
        return count;
    }

```