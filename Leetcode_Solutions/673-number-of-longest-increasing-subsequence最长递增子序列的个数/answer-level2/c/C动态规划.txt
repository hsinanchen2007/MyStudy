int findNumberOfLIS(int* nums, int numsSize){
    if ( numsSize <= 1) {
        return numsSize;
    }
    int dp[numsSize];
    int count[numsSize];
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        count[i] = 1;
    }
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++){
            if (nums[i] > nums[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }else if (dp[i] == dp[j] + 1){
                    count[i] += count[j];
                }
            }
        }
    }
    int max = 0;
    int num = 0;
    for (int i = 0; i < numsSize; i++) {
        if (dp[i] > max) {
            max = dp[i];
            num = count[i];
        }else if (dp[i] == max) {
            num += count[i];
        }
    }
    return num;
}