### 解题思路
动态规划问题。

dp[i][0]表示第0间房屋未被盗，0~i最大收益;
dp[i][1]表示第0间房屋被盗，0~i最大收益;

当i不是最后一间屋子时，
dp[i][0] = MMAX(dp[i - 1][0], dp[i - 2][0] + nums[i]);
dp[i][1] = MMAX(dp[i - 1][1], dp[i - 2][1] + nums[i]);

在最后一间屋子，
dp[numsSize - 1][0] = MMAX(dp[numsSize - 2][0], dp[numsSize - 3][0] + nums[numsSize - 1]);
dp[numsSize - 1][1] = dp[numsSize - 2][1];

最后，结果为MMAX(dp[numsSize - 1][0], dp[numsSize - 1][1])

![image.png](https://pic.leetcode-cn.com/73af47b378118fd948e092727a0852959899bf775c8ea7e4be0c80f0fdd202e0-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

#define MAX_LEN         10000

int dp[MAX_LEN][2];

//【算法思路】动态规划。典型一维dp。
// dp[i][0]表示第一间房屋没被打劫，0~i间房屋的最大收益；
// dp[i][1]表示第一间房屋被打劫，0~i间房屋的最大收益；
// 在最后一间房屋之前递归公式为：
//  dp[i][0] = MMAX(dp[i - 1][0], dp[i - 2][0] + nums[i]);
//  dp[i][1] = MMAX(dp[i - 1][1], dp[i - 2][1] + nums[i]);
// 在最后间房屋，递归公式为：
//  dp[numsSize - 1][0] = MMAX(dp[numsSize - 2][0], dp[numsSize - 3][0] + nums[numsSize - 1]);
//  dp[numsSize - 1][1] = dp[numsSize - 2][1];
int rob(int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    } else if(numsSize == 1) {
        return nums[0];
    } else if(numsSize == 2) {
        return MMAX(nums[0], nums[1]);
    }

    dp[0][0] = 0;
    dp[0][1] = nums[0];

    dp[1][0] = nums[1];
    dp[1][1] = nums[0];

    for(int i = 2; i < numsSize - 1; i++) {
        dp[i][0] = MMAX(dp[i - 1][0], dp[i - 2][0] + nums[i]);
        dp[i][1] = MMAX(dp[i - 1][1], dp[i - 2][1] + nums[i]);
    }

    //单独处理最后一间房屋
    dp[numsSize - 1][0] = MMAX(dp[numsSize - 2][0], dp[numsSize - 3][0] + nums[numsSize - 1]);
    dp[numsSize - 1][1] = dp[numsSize - 2][1];
/*
    for(int i = 0; i < numsSize; i++) {
        printf("dp[%d][0] = %d, dp[%d][1] = %d\n", i, dp[i][0], i, dp[i][1]);
    }
    printf("\n");
*/
    return MMAX(dp[numsSize - 1][0], dp[numsSize - 1][1]);
}
```