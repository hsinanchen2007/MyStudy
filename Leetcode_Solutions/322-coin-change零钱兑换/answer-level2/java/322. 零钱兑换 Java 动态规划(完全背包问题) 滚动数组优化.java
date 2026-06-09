### 代码

```java
/**
 * 动态规划 完全背包
 * f[i][j] 表示前 i 种硬币最少多少枚能够凑出 j 的面额
 * f[i][j] = min(f[i][j-w[i]], f[i-1][j-w[i]]) + 1
 * 可以使用滚动数组优化
 */
class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[] f = new int[amount + 1];
        Arrays.fill(f, 0x3f3f3f3f);
        f[0] = 0;
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                f[j] = Math.min(f[j], f[j - coin] + 1);
            }
        }
        return f[amount] == 0x3f3f3f3f ? -1 : f[amount];
    }
}
```