### 解题思路

完全背包问题, 使用滚动数组既省空间又省时间. 正常来讲, 01背包问题使用滚动数组优化到一维时, 第二层循环需要逆序枚举, 否则会出错. 而对于每种物品无限个点完全背包问题, 恰好需要正序枚举.

*这里的滚动数组的用法可能难以理解, 可以先学习 01背包 以及 01背包 的滚动数组优化, 进一步再学习完全背包这个模型.*

### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        // 动态规划
        // 定义状态: f[i][j] 表示前 i 种硬币凑出金额 j 最少需要多少枚, INF 表示无法凑出
        // 状态转移: f[i][j] = min{ f[i-1][j-k*coins[i-1]]+k } (f[i-1][j-...] >= 0)
        //         (决策 k 表示第 i 种硬币使用多少枚, f 数组为 1-indexed, coins 数组为 0-indexed)
        // 边界状态: f[0][0] = 0, other = INF (j > 0)
        // 优化: 滚动数组, 时间复杂度 o(nm), 空间复杂度 o(m)
        final int INF = 0x3f3f3f3f;
        int[] f = new int[amount + 1];
        Arrays.fill(f, INF);
        f[0] = 0;
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                f[j] = Math.min(f[j], f[j - coin] + 1);
            }
        }
        return f[amount] < INF ? f[amount] : -1;
    }
    private int coinChangeNoRolling(int[] coins, int amount) {
        // 未使用滚动数组, 时间复杂度 o(nm^2), 空间复杂度 o(nm)
        final int INF = 0x3f3f3f3f;
        int n = coins.length;
        int[][] f = new int[n + 1][amount + 1]; 
        for (int i = 0; i <= n; i++) {
            Arrays.fill(f[i], INF);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                for (int k = 0; k * coins[i - 1] <= j; k++) {
                    f[i][j] = Math.min(f[i][j], f[i - 1][j - k * coins[i - 1]] + k);
                }
            }
        }
        return f[n][amount] < INF ? f[n][amount] : -1;
    }
}
```