1.添加第一家抢和不抢两种状态
dp[1][0] 抢第一家
dp[1][1] 不抢第一家
2.最后在dp[n][0]与dp[n][1]中求最大值
```
#ifndef __cplusplus
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif

int rob(int* nums, int numsSize)
{
    if (nums == NULL || numsSize <= 0) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    if (numsSize == 2) {
        return max(nums[0], nums[1]);
    }

    int dp[numsSize + 1][2];
    memset(dp, 0, (numsSize + 1) * 2);
    
    dp[0][0] = -1;
    dp[0][1] = -1;
    
    dp[1][0] = nums[0]; // 抢
    dp[1][1] = 0; // 不抢
    
    dp[2][0] = max(nums[0], nums[1]);
    dp[2][1] = nums[1];
    
    for (int i = 3; i <= numsSize; ++i) {
        int roomIndex = i - 1;
        {
            int oneChoice = dp[i - 1][0];
            int money = (roomIndex == numsSize - 1 ? 0 : nums[roomIndex]); // 选择抢，但是不能连续, 第一家已经抢过了
            int anotherChoice = dp[i - 2][0] + money;
            printf("%d,%d\r\n", oneChoice, anotherChoice);
            dp[i][0] = max(oneChoice, anotherChoice);   
        }
        {
            int oneChoice = dp[i - 1][1];
            int money = nums[roomIndex];
            int anotherChoice = dp[i - 2][1] + money;
            printf("%d,%d\r\n", oneChoice, anotherChoice);
            dp[i][1] = max(oneChoice, anotherChoice);   
        }

    }
    int result = max(dp[numsSize][0], dp[numsSize][1]);
    return result;
}

```
