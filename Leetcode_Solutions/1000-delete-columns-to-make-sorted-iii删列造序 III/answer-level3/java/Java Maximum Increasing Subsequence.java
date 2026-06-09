```java
class Solution {
    public int minDeletionSize(String[] A) {
        int m = A.length;
        int n = A[0].length();
        int res = n - 1;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                int k;
                for (k = 0; k < m; k ++) {
                    if (A[k].charAt(j) > A[k].charAt(i)) break;
                }
                if (k == m) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
                res = Math.min(res, n - dp[i]);
            }
        }
        return res;
    }
}
```