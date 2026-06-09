```
class Solution {
    
    
    public double largestSumOfAverages(int[] A, int K) {
        int n = A.length;
        int[] prefixSum = new int[n];
        if (n == K) {
            return Arrays.stream(A).sum();
        }
        
        for (int i = 0; i < n; i++) {
            if (i== 0) prefixSum[i] = A[i];
            else {
                prefixSum[i] = prefixSum[i-1] + A[i];
            }
        }
        
        double[][] dp = new double[n+1][K+1];
        
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                dp[i][0] =0.0;
            } else {
                for (int m = 1; m <= Math.min(i, K); m++) {
                    double temp = 0.0;
                    for (int j = m-1; j <( m == 1? 1 : i); j++) {
                        temp = Math.max(temp, 
                                      helper(dp, prefixSum, i, j, m)
                                       );
                    
                    }
                    dp[i][m] = temp;
                }
            }
        }
        return dp[n][K];
    }
    
    double helper(double[][] dp, int[] prefixSum, int i, int j, int m) {
        return dp[j][m-1]  +  (0.0+prefixSum[i-1] - (j == 0? 0 :
                                                         prefixSum[j-1]))/(i-j)
                                      ;
    }
}
```
DP数组代表前i个数字分成m组的最大均值和。


<pre>
执行用时 :15 ms, 在所有 Java 提交中击败了85.58% 的用户
内存消耗 :34.8 MB, 在所有 Java 提交中击败了96.30%的用户</pre>
