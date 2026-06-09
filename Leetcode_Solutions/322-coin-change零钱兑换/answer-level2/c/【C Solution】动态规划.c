### 解题思路
此处撰写解题思路

### 代码

```c

int coinChange(int* coins, int coinsSize, int amount){
    if(coinsSize <= 0 || amount < 0 ){
        return -1;
    }
    int* dp = (int*)malloc(sizeof(int)*amount);
    memset(dp,0,sizeof(int)*amount);
    return dpSolution(coins, coinsSize , amount , dp);
}

int dpSolution(int* coins, int coinsSize, int amount, int* dp){
    if(amount == 0){
        return 0;
    }
    if(amount < 0 ){
        return  -1;
    }
    if(dp[amount-1] != 0) {
        return dp[amount-1];
    }
    int min_v = INT_MAX;
    for(int i = 0 ; i < coinsSize; i++ ){
        int res = dpSolution(coins , coinsSize, amount - coins[i], dp);
        if(res >= 0 && res < min_v){
            min_v = res + 1;
        }
    }
    dp[amount-1] = (min_v == INT_MAX ) ? -1 : min_v;
    return dp[amount-1];
}
```