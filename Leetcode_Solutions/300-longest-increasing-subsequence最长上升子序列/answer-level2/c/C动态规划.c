### 解题思路
上代码

### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    if (numsSize <= 0) {
        return 0;
    }
    int* dp = (int *) malloc (sizeof(int) * numsSize);
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        int left = 0, right = ret;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < nums[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (right >= ret) {
            dp[ret++] = nums[i];
        } else {
            dp[right] = nums[i];
        }
    }
    free(dp);
    return ret;
}
```