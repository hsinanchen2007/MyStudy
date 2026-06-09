```
class Solution {

    private static final int MOD = (int)1e9 + 7;

    public int numFactoredBinaryTrees(int[] A) {
        Arrays.sort(A);
        int n = A.length;
        long[] dp = new long[n];
        Arrays.fill(dp, 1);
        for(int i = 0; i < n; i++){
            int s = 0, e = i - 1;
            while(s <= e){
                if(A[s] * A[e] == A[i]){
                    dp[i] += dp[s] * dp[e];
                    if(s != e){
                        dp[i] += dp[s] * dp[e];
                    }
                    s++; e--;
                } else if(A[s] * A[e] < A[i]){
                    s++;
                } else {
                    e--;
                }
            }
            dp[i] %= MOD;
        }
        long res = 0;
        for(long sub: dp){
            res += sub;
        }
        res %= MOD;
        return (int)res;
    }
}
```