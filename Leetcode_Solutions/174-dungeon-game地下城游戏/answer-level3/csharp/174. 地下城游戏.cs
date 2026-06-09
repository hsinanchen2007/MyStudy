```
/**
    动态规划
        dp[i][j] 表示在 i, j 位置最少需要的血量，即剩余的最小血量

        // 剩余血量要大于 1 才能生存 (每一步生命值都大于 0, dp剩余值 + 默认值 >= 1)
        1、dp[i][j] + dungeon[i][j] >= 1 
        
        // dp[i + 1][j]  dp[i][j + 1] 只要剩余血量能满足任意一个就代表有通道 取最小值 (如剩余5, 10 只要不小于 5 就可以走下去)
        2、dp[i][j] + dungeon[i][j] = Math.Min(dp[i + 1][j], dp[i][j + 1]);
        
        // 合并 1、2
        dp[i][j] + dungeon[i][j] = Math.Max(Math.Min(dp[i + 1][j], dp[i][j + 1]), 1);

        // 先确定最后一个位置的剩余最小血量，再倒叙求值
        3、dp[rows - 1][columns - 1] = 1 - dungeon[rows - 1][columns - 1];

        // 骑士的初始健康点数为一个正整数 >= 1
        4、return Math.Max(dp[0, 0], 1);
*/
public class Solution {
    public int CalculateMinimumHP(int[][] dungeon) {
        int lowHealth = 0;
        int rows = dungeon.Length;
        if (rows == 0) {
            return lowHealth;
        }
        int columns = dungeon[0].Length;
        if (columns == 0) {
            return lowHealth;
        }
        int[,] dp = new int[rows, columns];
        // 先确定最后一个位置的剩余最小血量，再倒叙求值
        for (int i = rows - 1; i >= 0 ; i--) {
            for (int j = columns - 1; j >= 0; j--) {
                int rowValue = 0;
                // 越界时只取 column 值，row 值赋 int 最大值
                if (i == rows - 1) {
                    rowValue = int.MaxValue;
                } else {
                    rowValue = dp[i + 1, j];
                }
                int columnValue = 0;
                // 越界时只取 row 值，column 值赋 int 最大值
                if (j == columns - 1) {
                    columnValue = int.MaxValue;
                } else {
                    columnValue = dp[i, j + 1];
                }
                if (i == rows - 1 && j == columns - 1) {
                    dp[i, j] = 1 - dungeon[i][j];
                } else {
                    dp[i, j] = Math.Max(Math.Min(rowValue, columnValue), 1) - dungeon[i][j];
                }
            }
        }
        // 骑士的初始健康点数为一个正整数
        return Math.Max(dp[0, 0], 1);
    }
}
// Accepted
//     45/45 cases passed (120 ms)
//     Your runtime beats 88.89 % of csharp submissions
//     Your memory usage beats 25 % of csharp submissions (24.5 MB)
```
