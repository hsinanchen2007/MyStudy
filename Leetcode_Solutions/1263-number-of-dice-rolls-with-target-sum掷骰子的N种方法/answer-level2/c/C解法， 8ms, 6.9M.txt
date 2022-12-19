**思路**
动态规划求解即可。
考虑dp[i][j]为i个骰子得到j的总的可能。
```
int dp[31][1001];
int mod = 1000000007;
int CalcTotal(int d, int f, int target) {
    if (dp[d][target] != -1) {
        return dp[d][target];
    }
    if (d == target) {
        dp[d][target] = 1;
    } else if (d > target) {
        dp[d][target] = 0;
    } else if (d * f < target) {
        dp[d][target] = 0;
    } else {
        dp[d][target] = 0;
        for (int i = 1; i <= f; i++) {
            if (target < i) {
                break;
            }
            dp[d][target] += (dp[d - 1][target - i] != -1) ? dp[d - 1][target - i] : CalcTotal(d - 1, f, target - i);
            dp[d][target] %= mod;
        }
    }
    return dp[d][target];
}

/* 用动态规划求解 */
int numRollsToTarget(int d, int f, int target){
    memset(dp, 0xff, sizeof(dp));
    for (int i = 1; i <= f; i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
    } 
    dp[0][0] = 0;
    dp[1][0] = 0;
    int output = CalcTotal(d, f, target);
    return output;
}


```
