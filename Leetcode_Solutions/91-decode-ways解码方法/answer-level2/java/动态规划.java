### 解题思路
dp[i] = dp[i - 1](如果不为0) + dp[i - 2](如果在10-26之间)

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int size = s.length() + 1;
        int[] dp = new int[size];
        dp[0] = 1;
        for (int i = 1; i < size; i++) {
            if (s.charAt(i - 1) != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && (s.charAt(i - 2) - '0') * 10 + (s.charAt(i - 1) - '0') >= 10 && (s.charAt(i - 2) - '0') * 10 + (s.charAt(i - 1) - '0') <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[size - 1];
    }
}
```