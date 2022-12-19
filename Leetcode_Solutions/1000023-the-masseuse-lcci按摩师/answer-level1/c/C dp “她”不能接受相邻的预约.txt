```
#define MAX(a, b) (a > b ? a : b)

int massage(int* nums, int numsSize){

  int *dp = calloc(numsSize, sizeof(int));
  int ret = 0;

  for(int i = 0; i < numsSize; i++)
  {
    if(i - 2 < 0)       dp[i] = nums[i];
    else if(i - 3 < 0)  dp[i] = nums[i] + dp[i - 2];
    else                dp[i] = nums[i] + MAX(dp[i - 2], dp[i - 3]);

    ret = MAX(ret, dp[i]);
  }

  free(dp);

  return ret;
}
```
