### 解题思路
参考网上大神的思路

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */
public class Solution {
    public int removeBoxes(int[] boxes) {
        /**
         * violence_complexity_n
         * just_think_of_violence
         */
        /**
         * refer to the ideas of online gods
         * @see https://www.cnblogs.com/grandyang/p/6850657.html
         */
        int n = boxes.length;
        int dp[][][] = new int[n][n][n];
        return helper(boxes, 0, n - 1, 0, dp);

    }

    private int helper(int[] boxes, int i, int j, int k, int[][][] dp) {
        if (j < i) {
            return 0;
        }
        if (dp[i][j][k] > 0) {
            return dp[i][j][k];
        }
        int res = (1 + k) * (1 + k) + helper(boxes, i + 1, j, 0, dp);
        for (int m = i + 1; m <= j; m++) {
            if (boxes[m] == boxes[i]) {
                res = Math.max(res, helper(boxes, i + 1, m - 1, 0, dp) +
                        helper(boxes, m, j, k + 1, dp));
            }

        }
        dp[i][j][k]=res;
        return res;
    }
}

```