### 解题思路
先生成相应的矩阵，然后dp求解矩阵最长对角线

### 代码

```java
class Solution {
   
 
    // 相等的 就是二维数组的对角线，求最大的对角线数目即可
    public int findLength(int[] A, int[] B) {
        int[][] matrix = new int[A.length][B.length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B.length; j++) {
                if (A[i] == B[j]) {
                    matrix[i][j] = 1;
                } else {
                    matrix[i][j] = -1;
                }
            }
        }

        // DP 求解矩阵中对角线连续长度最大
        // 当a[i][j]==1 时dp[i][j] =dp[i-1][j-1]+1;
        // 当a[i][j]!=1 dp[i][j]=0;
        int[][] dp = new int[A.length + 1][B.length + 1];
        int max = 0;
        for (int i = 1; i <= A.length; i++) {
            for (int j = 1; j <= B.length; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max = Math.max(dp[i][j], max);
                }
            }
        }

        return max;

    }
}
```