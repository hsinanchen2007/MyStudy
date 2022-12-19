```
#define MAX_SIZE 1000
int maxCoins(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int num[MAX_SIZE] = {0};
    num[0] = 1;
    num[numsSize + 1] = 1;
    for (int i = 0; i < numsSize; i++) {
        num[i + 1] = nums[i];
    }
    int dp[MAX_SIZE][MAX_SIZE] = {0};
    int size = numsSize + 2;
    for (int i = size - 2; i >= 0; i--) {
        for (int j = i + 2; j < size; j++) {
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = fmax(dp[i][j], dp[i][k] + dp[k][j] + num[i] * num[k] * num[j]);
            }
        }
    }
    return dp[0][size - 1];    
}
```
