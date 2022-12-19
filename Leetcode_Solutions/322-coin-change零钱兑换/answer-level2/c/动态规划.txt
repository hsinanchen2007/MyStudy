```
/*
这是一道最经典的动态规划问题，核心思想就是子问题的划分。记f(11)为问题的解，那么这个零钱面额coins[i] = {1, 2, 5}可以划分成f(11-5), f(11-2), f(11-1)三个子问题，子问题找到了，目标就是寻找递归的结束条件。易知f(0) = 0, f(coins[i]) = 1, f(amount < min(coins[i])) = -1，即子问题划分到n=0， 或者刚好等于零钱面额时返回， 当小于最小面额时进行错误处理。

即状态转移方程为f(0)= 0, f(n) = 1 + min(f(n - coins[i])), n>0。

*/
int min(int a, int b) {
    return a <= b ? a : b;
}
int coinChange(int* coins, int coinsSize, int amount){
    int* dp = (int *)malloc((amount + 1) * sizeof(int)) ; //当金额为下标值时，组合而成的最少的硬币的个数。
    int max = amount + 1;
    for(int i = 0; i < amount + 1; i++) {
        dp[i] = max;
    }
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coinsSize; j++) {
            if(i >= coins[j]) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
    
    
    
}
```
