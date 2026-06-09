### 解题思路
动态规划
中心枚举

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() == 0) {
            return s;
        }
        // write your code here
        int len = s.length();
        int max = 1, start = 0;
        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < len - 1; i++) {
            if(s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = true;
                max = 2;
                start = i;
            }
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 2; j < len; j++) {
                dp[i][j] = dp[i + 1][j - 1] && s.charAt(i) == s.charAt(j);
                if(dp[i][j]) {
                    if(max < j - i + 1) {
                        max = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substring(start, start + max);
    }
}
```

```java
class Solution {
    int max;
    int start;
    int len;
    String str;

    public String longestPalindrome(String s) {
        len = s.length();
        str = s;
        for (int c = 0; c < len; c++) {
            expand(c, c);
            expand(c, c + 1);
        }

        return s.substring(start, start + max);
    }

    private void expand(int i, int j) {
        while (i >= 0 && j < len && str.charAt(i) == str.charAt(j)) {
            i--;
            j++;
        }

        if (j - i - 1 > max) {
            max = j - i - 1;
            start = i + 1;
        }
    }
}
```
