### 解题思路
这道题的难度在状态转移方程，特别是第二种情况，dp[i]保存到第i个符号为结尾的最长长度，第一种情况是（），这种很简单，直接加2就行，难想到的是第二种，）），这种情况要减掉dp[i - 1]，这样就能回到这个最长子串的开头，然后再判断开头前面一个字符是不是（就行了，要注意边界的处理，很巧妙的做法

### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        if (s.length() == 1 || s.length() == 0) return 0;
        int[] dp = new int[s.length()];
        if (s.charAt(0) == '(' && s.charAt(1) == ')') dp[1] = 2;
        int max = dp[1];
        for (int i = 2; i < s.length(); i++) {
            if (s.charAt(i - 1) == '(' && s.charAt(i) == ')') dp[i] = dp[i - 2] + 2;
            else if (s.charAt(i) == ')' && i - dp[i - 1] - 1 >= 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
                dp[i] = dp[i - 1] + 2;
                if (i - dp[i - 1] - 2 >= 0) dp[i] += dp[i - dp[i - 1] - 2];
            }
            else dp[i] = 0;
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
```