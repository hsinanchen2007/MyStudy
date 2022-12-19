dp 数组表示进行当进行到t步的时候，老鼠的位置和猫的位置
当t = 2 * graph.length的时候，意味着老鼠和猫都走了n步，且没有相遇，那么说明平局
dp[t][m][c] = 0 的时候表示该点没有访问过
dp[t][m][c] = 1 的时候表示平局
dp[t][m][c] = 2 的时候表示老鼠赢
dp[t][m][c] = 2 的时候表示猫赢

最后返回值就是dp[0][1][2] 的值 - 1
```java
class Solution {
     int[][][] dp;
     int[][] graph;
     int n;
    public int catMouseGame(int[][] graph) {
        n = graph.length;
        dp = new int[2 * n + 1][n][n];
        this.graph = graph;
        return backtrack(0, 1, 2) - 1;
    }
    // t is timeRound, m is mouce positon, c is cat opsition
    int backtrack(int t, int m, int c) {
        if (t == 2 * n) {
            return dp[t][m][c] = 1;
        } else if (m == 0) {
            return dp[t][m][c] = 2;
        } else if (c == m) {
            return dp[t][m][c] = 3;
        }
        if (dp[t][m][c] != 0) {
            return dp[t][m][c];
        }
        if (t % 2 == 0) {
            boolean catWin = true;
            for (int next : graph[m]) {
                int nextRound = backtrack(t + 1, next, c);
                if (nextRound == 2) {
                    return dp[t][m][c] = 2;
                } else if (nextRound != 3) catWin = false;
            }   
            if (catWin) return dp[t][m][c] = 3;
            else return dp[t][m][c] = 1;
        } else {
            boolean mouceWin = true;
            for (int next : graph[c]) {
                if (next == 0) continue;
                int nextRound = backtrack(t + 1, m, next);
                if (nextRound == 3) {
                    return dp[t][m][c] = 3;
                } else if (nextRound != 2) mouceWin = false;
            }
            if (mouceWin) return dp[t][m][c] = 2;
            else return dp[t][m][c] = 1;
        } 
    }
}
```