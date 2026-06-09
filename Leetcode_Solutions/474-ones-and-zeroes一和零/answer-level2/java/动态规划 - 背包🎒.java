### 解题思路
开始练习动态规划的时候，一个很好的思路就是**题目要求什么，就可以将 dp 数组设为什么**。
该题有两个变量 0 和 1，都给了容量限制，可以看作两个背包，那么就变成了将字符串放进两个背包中可以产生的最大价值。

背包问题：将输入的字符串看做物品，每个数字的个数作为容量
- 定义 dp 数组，`dp[i][j][k]` : 选择前 i 个字符串，在 0 的个数为 j, 1 的个数为 k 的条件下可以获得的最大字符串个数
- 状态转移：`dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j - curr(0))][k - curr(1))] + 1)`
     * 选择与不选择当前字符串的最大值, 选择的话，0 背包的容量变成了 `j - 当前字符串中 0 的个数`, 1 背包的容量为 `k - 当前字符串中 1 的个数`
- base case ：`dp[0][j][k] = 0`

先写出一个三维 dp 代码，然后再进行空间优化，压缩为二维 dp

### 代码

```java
class Solution {
    // 三维 dp 数组
    public int findMaxForm1(String[] strs, int m, int n) {
        if (strs == null || strs.length == 0) return 0;
        int[][][] dp = new int[strs.length + 1][m + 1][n + 1];
        // base case 为第一行0，不用特意赋值
        for (int i = 1; i <= strs.length; i++) {
            int curr0 = findZeroAndOne(strs[i - 1])[0];
            int curr1 = findZeroAndOne(strs[i - 1])[1];

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= curr0 && k >= curr1)
                        dp[i][j][k] = Math.max(dp[i-1][j][k], dp[i-1][j - curr0][k - curr1]+1);
                    else dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        return dp[strs.length][m][n];
    }

    // 二维 dp
    public int findMaxForm(String[] strs, int m, int n) {
        if (strs == null || strs.length == 0) return 0;
        int[][] dp = new int[m + 1][n + 1];
        
        for (int i = 1; i <= strs.length; i++) {
            int curr0 = findZeroAndOne(strs[i-1])[0];
            int curr1 = findZeroAndOne(strs[i-1])[1];
            // 这里做了优化，不用进行特判了，当前背包容量必须大于当前字符串中0和1的数量
            for (int j = m; j >= curr0; j--) {
                for (int k = n; k >= curr1; k--) {
                    dp[j][k] = Math.max(dp[j][k], dp[j - curr0][k - curr1] + 1);
                }
            }
        }
        return dp[m][n];
    }
    public int[] findZeroAndOne(String s){
        int num0 = 0, num1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0') num0++;
            else num1++;
        }
        return new int[]{num0, num1};
    }
}
```