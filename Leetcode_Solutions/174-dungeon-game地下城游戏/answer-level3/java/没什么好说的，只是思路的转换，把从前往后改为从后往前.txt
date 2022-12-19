### 解题思路
没什么好说的，只是思路的转换，把从前往后改为从后往前

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */
public class Solution {
    public static void main(String[] args) {
        int[][] dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
        int result = calculateMinimumHP(dungeon);
        System.out.println("result = " + result);
    }

    public static int calculateMinimumHP(int[][] dungeon) {
        /**
         * 一眼就能看出建一个三维的矩阵，然后来记录到达每一步的最小值
         * 0表示累计
         * 1表示残余
         * dp[i][j]=min(dp[i-1][j],dp[i][j+1])+a[i][j]
         * 找到最小值
         */
        /**
         * 上面写的从前往后，仔细想了想不行啊，
         * 从后往前可以试试。
         */
        int[][] dp = new int[dungeon.length][dungeon[0].length];
        dp[dungeon.length - 1][dungeon[0].length - 1] = dungeon[dungeon.length - 1][dungeon[0].length - 1] > 0 ? 1 :
                1 - dungeon[dungeon.length - 1][dungeon[0].length - 1];
        for (int i = dungeon.length - 1; i >= 0; i--) {
            for (int j = dungeon[0].length - 1; j >= 0; j--) {
                if (i < dungeon.length - 1 && j < dungeon[0].length - 1) {
                    dp[i][j] = Math.max(1, Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
                } else if (i == dungeon.length - 1 && j < dungeon[0].length - 1) {
                    dp[i][j] = Math.max(1, dp[i][j + 1] - dungeon[i][j]);
                } else if (i < dungeon.length - 1 && j == dungeon[0].length - 1) {
                    dp[i][j] = Math.max(1, dp[i + 1][j] - dungeon[i][j]);
                }
                // System.out.println("i = " + i);
                // System.out.println("j = " + j);
                // System.out.println("dp[i][j] = " + dp[i][j]);
            }
        }
        return dp[0][0];
    }
}

```