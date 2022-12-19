dp[i][j]表示左手右手的最后一个字母为word的第i位和第j位。由此可以将过程表示在nxn的方格中，从而变成找寻路径的问题。
i不能等于j因为左右手不能在同一个按键上。
由问题的对称性，不妨假设i > j，可以减少一半的时间。
若i > j + 1, dp[i][j] = dp[i - 1][j] + distance(i, i - 1); 因为必须要经历上一个字母才能到达当前字母。
若i == j + 1，则 i 可以取到所有小于j值，因为有了j作为最大值的保证，i可以往后跳很多。又犹豫对称性，其实等价于 i = i - 1, j 取到小于等于i所有值。再在所有的这些值里面取最小，完成动态规划。dp[i][j] = min(dp[i - 1][k <= j] + distance(i, k));
代码如下：
```
public Solution {
    public int minimumDistance(String word) {
        int n = word.length();
        int[][] dp = new int[n + 1][n + 1];
        dp[0][0] = 0; dp[1][0] = 0;
        for (int i = 2; i < n + 1; i++) {
            for (int j = 0; j < i; j++) {
                if (j != i - 1) dp[i][j] = dp[i - 1][j] + distance(word.charAt(i - 1), word.charAt(i - 2));
                else {
                    int minDis = Integer.MAX_VALUE;
                    for (int col = 0; col < j; col++) {
                        int rightDist = (col == 0) ? 0 : (distance(word.charAt(i - 1), word.charAt(col - 1)));
                        int dist = dp[i - 1][col] + rightDist;
                        if (dist < minDis) minDis = dist;
                    }
                    dp[i][j] = minDis;
                }
            }
        }
        int minDis = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            minDis = Math.min(minDis, dp[n][j]);
        }
        return minDis;
    }

    private int distance(char i, char j) {
        int[] posI = cordi(i);
        int[] posJ = cordi(j);
        return Math.abs(posI[0] - posJ[0]) + Math.abs(posI[1] - posJ[1]);
    }

    private int[] cordi(char c) {
        int[] pos = new int[2];
        pos[0] = (c - 'A') / 6;
        pos[1] = (c - 'A') % 6;
        return pos;
    }
}

```
