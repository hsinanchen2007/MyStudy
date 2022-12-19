[091_解码方法 题解](https://github.com/luo-rong/LeetCode/tree/master/src/_091_NumDecodings) / [GitHub 持续更新](https://github.com/luo-rong/LeetCode)

1. 动态规划：`dp[i] = dp[i-1] + dp[i-2]`
2. 合法性判断：若当前解码1位，则该位不可为0；若当前解码2位，则`首位为1`或`首位为2 && 次位<7`
3. tips：dp数组多一位，方便边界条件的处理

```java
public class NumDecodings {
    public int numDecodings(String s) {
        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        dp[1] = s.charAt(0) != '0' ? 1 : 0;
        for (int i = 2; i <= s.length(); ++i) {
            dp[i] = s.charAt(i - 1) != '0' ? dp[i - 1] : 0;
            boolean isLegal = s.charAt(i - 2) == '1' || (s.charAt(i - 2) == '2' && s.charAt(i - 1) < '7');
            dp[i] += isLegal ? dp[i - 2] : 0;
        }
        return dp[s.length()];
    }
}
```