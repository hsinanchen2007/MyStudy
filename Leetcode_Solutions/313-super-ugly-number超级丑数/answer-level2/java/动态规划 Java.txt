只使用动态规划思想解决这道题的话，其实这道题和264题丑数II的思想是一致的。
dp保存按序排列的丑数，每个指针分别乘对应位置的素数找出下一个丑数。
```
public int nthSuperUglyNumber(int n, int[] primes) {

    int[] dp = new int[n];
    dp[0] = 1;

    int k = primes.length;
    int[] index = new int[k];

    for (int i = 1; i < n; i++) {
        int min = Integer.MAX_VALUE;
        for (int j = 0; j < k; j++) {
            if (min > dp[index[j]] * primes[j]) {
                min = dp[index[j]] * primes[j];
            }
            dp[i] = min;
        }
        for (int j = 0; j < k; j++) {
            if (min == dp[index[j]] * primes[j]) {
                index[j]++;
            }
        }
    }
    return dp[n - 1];
}
```
