### 解题思路

dp[i][j] 代表消除数组i - j之间需要的步数

这个步数的最大值是1 + dp[i+1][j]

当arr[i] = arr[i+1] 的时候，我们需要的步数是1 + dp[i+2][j]

当arr[i] = arr[k] k != i + 1的时候，我们需要的步数是 dp[i][k-1] + dp[k+1][j]

综合上面三个条件可以写出记忆化递归代码如下

### 代码

```java
class Solution {
    int[] arr;
    int n;
    int[][] dp;
    public int minimumMoves(int[] arr) {
        this.arr = arr;
        this.n = arr.length;
        this.dp = new int[n][n];
        return backtrack(0, n - 1);
    }

    int backtrack(int i, int j ) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] > 0) return dp[i][j];
        int res = Integer.MAX_VALUE;
        res = Math.min(res, 1 + backtrack(i + 1, j));
        for (int k = i + 1; k <= j; k ++) {
            if (arr[k] == arr[i]) {
                if (k - i == 1) {
                    res = Math.min(res, 1 + backtrack(k + 1, j));
                } else {
                    int returnValue = backtrack(i + 1, k - 1) + backtrack(k + 1, j);
                    res = Math.min(returnValue, res);
                }
            }
        }
        return dp[i][j] = res;
    }
}
```