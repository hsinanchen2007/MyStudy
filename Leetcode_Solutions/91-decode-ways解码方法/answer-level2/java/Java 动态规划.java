### 解题思路
最后一位组合，可以是当前数字（1个），也可以是当前数字和前一个数字的组合（2个）。


### 代码

```java
class Solution {

    public int numDecodings(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            if (s.charAt(i - 1) != '0') dp[i] += dp[i - 1]; // 最后一位是一个数字
            if (i >= 2) {                                   // 最后一位是两个数字：如果i >= 2 计算两位数字是否在10-26之间，将它们看做一个组合，并且加上dp[i - 2] 的状态
                int t = (s.charAt(i - 2) - '0') * 10 + s.charAt(i - 1) - '0';
                if (t >= 10 && t <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[n];
    }
}
```

执行用时 :1 ms, 在所有 Java 提交中击败了99.97% 的用户
内存消耗 :34.6 MB, 在所有 Java 提交中击败了45.33%的用户