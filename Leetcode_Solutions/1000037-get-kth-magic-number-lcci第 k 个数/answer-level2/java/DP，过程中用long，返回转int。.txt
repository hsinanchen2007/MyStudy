### 解题思路
这里用动态规划来实现，但是对于java语言有一个地方需要注意，就是越界问题。在计算过程中需要用long来装，返回结果时，需要用Integer进行一次安全转换。不可直接强转。
后一个结果是前面所有值分别乘以3,5,7最小的那一个。

### 代码

```java
class Solution {
    public int getKthMagicNumber(int k) {
        long[] dp = new long[k];
        Arrays.fill(dp, Long.MAX_VALUE);
        dp[0] = 1;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < i; j++) {
                // 乘积中最小的
                if (dp[j] * 3 > dp[i - 1]) {
                    dp[i] = Math.min(dp[i], dp[j] * 3);
                }
                if (dp[j] * 5 > dp[i - 1]) {
                    dp[i] = Math.min(dp[i], dp[j] * 5);
                }
                if (dp[j] * 7 > dp[i - 1]) {
                    dp[i] = Math.min(dp[i], dp[j] * 7);
                }
            }
        }
        return Integer.parseInt(String.valueOf(dp[k - 1]));
    }
}
```