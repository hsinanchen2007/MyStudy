### 解题思路
本题为经典的分组DP，这里给出C语言的解法。

分组DP基本思路为“所有元素分为m组”变为“分为m-1组”和“剩下的1组”。

需要注意的是，设定好遍历的边界，将无意义的状态排除。

为了加速剩下元素求和，使用前缀和进行加速。

具体解法：
0.定义dp[i][m]表示从0到下标i，分成m组的最大值。

1.外层循环 i 从0~numsSize

2.中层循环 j 从dp[i][1]求解到dp[i][min(i+1, m)]

3.内存循环 k 从j-1遍历到i-1

4.dp[i][j] = MMIN(dp[i][j], MMAX(dp[k][j - 1], prefix[i] - prefix[k]));

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

long long dp[1000][51];

//【算法思路】分组dp。典型的分组dp问题。
// 从底向顶逐步遍历
// 将m组分解为m - 1组和1组
// 将遍历起止点限制在合理的范围
int splitArray(int* nums, int numsSize, int m){
    if(numsSize == 1) {
        return nums[0];
    }

    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    long long *prefix = (long long *)calloc(numsSize, sizeof(long long));
    long long sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
        prefix[i] = sum;
    }

    //遍历所有的点
    for(int i = 0; i < numsSize; i++) {
        //遍历所有可能的分组，即分为1组到分为MMIN(元素个,m个)组
        for(int j = 1; j <= MMIN(i + 1, m); j++) {
            //j为1，需要单独处理
            if(j == 1) {
                dp[i][1] = prefix[i];
                continue;
            }
            
            int min = INT_MAX;
            //查找所有可能的分组,组数大于元素数不考虑
            for(int k = j - 2; k < i; k++) {
                min = MMIN(min, MMAX(dp[k][j - 1], prefix[i] - prefix[k]));
            }
            
            dp[i][j] = min;
        }
    }
/*
    for(int i = 0; i < numsSize; i++) {
        for(int j = 1; j <= m; j++) {
            printf("[%d, %d]:%d   ", i, j, dp[i][j]);
        }
        printf("\n");
    }
*/
    return dp[numsSize - 1][m];
}
```