### 代码

从起点开始递归
```java
class Solution {
    int[][] memo;
    int row, column;

    public int uniquePaths(int m, int n) {
        memo = new int[m][n];
        row = m;
        column = n;
        return calcTotal(0, 0);
    }

    public int calcTotal(int i, int j) {
        if (i == row - 1 || j == column - 1) {
            return 1;
        }
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        memo[i][j] = calcTotal(i + 1, j) + calcTotal(i, j + 1);
        return memo[i][j];
    }
}
```

从终点开始递归
```java
class Solution {
   int[][] memo;

    public int uniquePaths(int m, int n) {
        memo = new int[m][n];
        return calcTotal(m - 1, n - 1);
    }

    public int calcTotal(int i, int j) {
        if (i == 0 || j == 0) {
            return 1;
        }
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        memo[i][j] = calcTotal(i - 1, j) + calcTotal(i, j - 1);
        return memo[i][j];
    }
}
```