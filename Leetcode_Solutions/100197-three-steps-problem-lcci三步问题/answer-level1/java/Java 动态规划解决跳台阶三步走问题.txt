### 解题思路
为了解决溢出问题，采用long类型避免多种情况进行假发计算时已经溢出，导致为负数或者不符合预期。
动态规划：dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
第i台阶的方法数等于从上一层跳一下或者从上2层跳一下或者从上3层跳一下！！！！

### 代码

```java
class Solution {
    public int waysToStep(int n) {
        if (n <= 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++) {
            dp[i] = (long)((dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000007);
        }

        return (int)dp[n];
    }
}
```