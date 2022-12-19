 自顶而下比自底而上快，因为自底而上，需要算出每个子问题，而自顶而下，只需要算出需要的。

1. 自顶而下
int myMin(int a, int b){
    return ((a)<(b))?(a):(b);
}

int coinRemain(int* coins, int coinsSize, int remain, int* dp){
    if(remain<0) return -1;
    if(remain==0) return 0;
    if(dp[remain] != INT_MAX) return dp[remain];

    int min = INT_MAX;
    for(int j=0;j<coinsSize;j++){
        int res=coinRemain(coins, coinsSize, remain - coins[j], dp);
        if(res>=0){
            min = myMin(min, res);
        }
    }
    if(min == INT_MAX){
        dp[remain] = -1;
    }else{
        dp[remain] = min+1;
    }
    return dp[remain];
}
int coinChange(int* coins, int coinsSize, int amount){
    if(amount < 0) return -1;
    int *dp = (int*)malloc((amount+1)*sizeof(int));
    for(int i=0;i<(amount +1);i++){
        dp[i] = INT_MAX;
    }
    int result =  coinRemain(coins, coinsSize, amount, dp); 
    free(dp);
    return result;
}

2. 自底而上
int myMin(int a, int b){
    return ((a)<(b))?(a):(b);
}


int coinChange(int* coins, int coinsSize, int amount){
    
    int *dp = (int*)malloc((amount+1)*sizeof(int));
    
    dp[0] = 0;
    for(int i=1;i<=amount;i++){
        dp[i] = amount+1;
        for(int j=0;j<coinsSize;j++){
            if((i-coins[j]) >= 0){
                dp[i] = myMin(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    
    int result = (dp[amount]>amount)?-1:dp[amount];
    free(dp);
    return result;
    
}