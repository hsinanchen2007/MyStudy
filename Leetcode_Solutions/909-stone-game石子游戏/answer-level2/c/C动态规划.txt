```
bool stoneGame(int* piles, int pilesSize){
    int i, j;
    int*** dp = (int***)malloc(sizeof(int**) * pilesSize);
    for(i = 0; i < pilesSize; i++) {
        dp[i] = (int**)malloc(sizeof(int*) * pilesSize);
        for(j = 0; j < pilesSize; j++) {
            dp[i][j] = (int*)malloc(sizeof(int) * 2);
        }
    }
    
    for(int i = 0; i < pilesSize; i++) {
        dp[i][i][0] = piles[i]; // first
        dp[i][i][1] = 0;        // second
    }
    for(int k = 1; k < pilesSize; k++) { // offset
        for(int i = 0; i + k < pilesSize; i++) { // diag
            int j = i + k;
            int left = dp[i + 1][j][1] + piles[i];
            int right = dp[i][j - 1][1] + piles[j];
            if(left > right) {
                dp[i][j][0] = left;              // first
                dp[i][j][1] = dp[i + 1][j][0];     // second
            } else {
                dp[i][j][0] = right;             // first
                dp[i][j][1] = dp[i][j - 1][0];     // second
            }
        }
    }
    return dp[0][pilesSize - 1][0] > dp[0][pilesSize - 1][1];
}
```
