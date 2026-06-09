```
public int minRefuelStops(int target, int startFuel, int[][] stations) {
    int n = stations.length;
    // dp[i][j]表示经过i站加油j次能够到达的最远距离
    int[][] dp = new int[n + 1][n + 1];

    if (startFuel >= target)
        return 0;
    for (int i = 0; i < n; i++)
        dp[i][0] = startFuel;

    for (int i = 1; i <= n; i++) {
        int currStationPos = stations[i - 1][0];
        int currStationGas = stations[i - 1][1];
        for (int j = 1; j <= i; j++) {
            // 因为dp[i][j]表示经过前i站，一共加油j次。要么第i站加油，1~i-1站加j-1次；要么第i站不加油，前面1~i-1加j次
            // 前i-1站加j次，本站不加油
            if (dp[i - 1][j] >= currStationPos) {
                dp[i][j] = dp[i - 1][j];
            }
            // max(前i-1站加j次，本站不加油, 前i-1站加j-1次，本站加油)
            if (dp[i - 1][j - 1] >= currStationPos) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + currStationGas);
            }
        }
    }

    // 此时走完了n站，看看最少加油几次能达到target
    for (int refuelTimes = 0; refuelTimes <= n; refuelTimes++)
        if (dp[n][refuelTimes] >= target)
            return refuelTimes;
    return -1;
}
```
