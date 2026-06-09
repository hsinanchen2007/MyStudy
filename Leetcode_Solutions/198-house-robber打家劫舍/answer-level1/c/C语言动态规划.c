![image.png](https://pic.leetcode-cn.com/aea71e8b6edcf5bd70eb7a3719c6fe2dc8198a5c35e947f2321be9db87d23040-image.png)
动态规划方程：dp[n] = MAX( dp[n-1], dp[n-2] + num )
```
#define MAX(A, B) (A) > (B) ? (A) : (B)
int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return MAX(nums[0], nums[1]);

    int *dp = (int *)calloc(1024, sizeof(int));
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= numsSize; i++) {
        dp[i] = MAX(dp[i-2] + nums[i-1], dp[i-1]);
    }
    return dp[numsSize];
}

```
