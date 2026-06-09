```java
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] dp = new int[n];
        dp[0] = 1;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < primes.length; ++i) {
            map.put(primes[i], 0);
        }

        for (int j = 1; j < n; ++j) {
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < primes.length; ++i) {
                min = Math.min(dp[map.get(primes[i])] * primes[i], min);
            }
            dp[j] = min;
            for (int i = 0; i < primes.length; ++i) {
                while (dp[map.get(primes[i])] * primes[i] <= dp[j]) {
                    map.put(primes[i], map.get(primes[i]) + 1);
                }
            }
        }
        return dp[n-1];
    }
}
```