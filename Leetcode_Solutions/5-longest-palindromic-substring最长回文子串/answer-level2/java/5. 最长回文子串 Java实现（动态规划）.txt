### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.equals("")) {
            return s;
        }
        boolean[][] dp = new boolean[s.length()][s.length()];
        String ans = "";
        int front = 0;
        int rear = 0;
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
            if (i + 1 < s.length()) {
                if (s.charAt(i) == s.charAt(i + 1)) {
                    dp[i][i + 1] = true;
                    front = i;
                    rear = i + 1;
                }
            }
        }
        for (int len = 2; len < s.length(); ++len) {
            for (int i = 0; i + len < s.length(); i++) {
                int end = i + len;
                int r = i + 1;
                int c = end - 1;
                if (s.charAt(i) == s.charAt(end) && dp[r][c]) {
                    dp[i][end] = true;
                    front = i;
                    rear = end;
                }
            }
        }
        return s.substring(front, rear + 1);
    }
}
```