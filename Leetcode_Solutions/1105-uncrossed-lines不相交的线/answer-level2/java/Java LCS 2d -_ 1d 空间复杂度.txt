2d version：

```java
class Solution1 {
    public int maxUncrossedLines(int[] A, int[] B) {
        int[][] dp = new int[A.length + 1][B.length + 1];
        for (int i = 1; i <= A.length; i ++) {
            for (int j = 1; j <= B.length; j ++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[A.length][B.length];
    }
}
```
1d version： 
注意1d version 内部需要两个for循环，目的是使dp数组是非递减的。
```java
class Solution {
    public int maxUncrossedLines(int[] A, int[] B) {
        int[] dp = new int[B.length + 1];
        for (int i = 0; i < A.length; i ++) {
            for (int j = B.length - 1; j >= 0; j --) {
                if (A[i] == B[j]) {
                    dp[j + 1] = dp[j] + 1; 
                } 
            }
            for (int j = 0; j < B.length; j ++) {
                dp[j + 1] = Math.max(dp[j + 1], dp[j]);
            }
        }
        return dp[B.length];
    }
}
```