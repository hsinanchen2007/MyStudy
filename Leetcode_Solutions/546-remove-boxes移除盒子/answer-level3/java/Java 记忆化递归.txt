### 解题思路
dp[i][j][k] 表示消除从i - j之间的box能得到的最大分数

其中k表示在i之前有k个和boxes[i] 一样的box

### 代码

```java
class Solution {
    int[][][] dp;
    int[] boxes;
    public int removeBoxes(int[] boxes) {
        int n = boxes.length;
        dp = new int[n][n][n];
        this.boxes = boxes;
        return removingbox(0, n - 1, 0);
    }
    private int removingbox(int i, int j, int k) {
        if (i > j) return 0;
        if (dp[i][j][k] > 0) return dp[i][j][k];
        while (i < j && boxes[i + 1] == boxes[i]) {
            i ++;
            k ++;
        }
        int res = (k + 1) * (k + 1) + removingbox(i + 1, j, 0);
        for (int m = i + 1; m <= j; m ++) {
            if (boxes[m] == boxes[i]) {
                res = Math.max(res, removingbox(i + 1, m - 1, 0) + removingbox(m, j, 1 + k));
            }
        }
        return dp[i][j][k] = res;
    }
}
```