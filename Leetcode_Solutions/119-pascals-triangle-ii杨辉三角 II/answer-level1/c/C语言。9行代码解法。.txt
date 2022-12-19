```
int* getRow(int rowIndex, int* returnSize) {
    int* dp = (int*)malloc(sizeof(int) * (rowIndex+1));
    *returnSize = rowIndex + 1;
    for(int i = 0; i <= rowIndex; i++){
        dp[i] = 1;
        for(int j = i - 1; j > 0; j--){
            dp[j] = dp[j] + dp[j-1];
        }
    }
    return dp;
}
```
