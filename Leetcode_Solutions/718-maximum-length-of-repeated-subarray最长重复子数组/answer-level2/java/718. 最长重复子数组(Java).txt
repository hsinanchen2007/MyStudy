### 解题思路
当A[i] == B[j],dp[i][j] = dp[i-1][j-1] + 1,
当A[i] != B[j]时，dp[i][j] = 0,因为子数组是要连续的，一旦不匹配了，就不能再增加长度了。
### 代码

```java
class Solution {
    public int findLength(int[] A, int[] B) {
        int result = 0;
        int n = A.length + 1;
        int m = B.length + 1;
        int[][] dp = new int[n][m];
        for (int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(A[i - 1] == B[j - 1]){
                    dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
                    result = Math.max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
}
```
###
空间和时间复杂度 O（m x n）;
