### 解题思路
经典的分组DP题目。

典型的解题思路为，1.从序列中选择一个值，最终结果可以从两边的子问题得到结果；2.求解过程需要遍历移动选择的值。

dp[i][j]表示从i到j的序列，所需的最小资金。

递推公式为dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j])),其中k属于[i, j]

![image.png](https://pic.leetcode-cn.com/3a8535c6166b9d66637ce4493f2b84d3de73a9599798216ceaed8aa78a64214c-image.png)


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

#define MAX_LEN     1000

int dp[MAX_LEN][MAX_LEN];

//【算法思路】分组DP。
int getMoneyAmount(int n){
    if(n == 1) {
        return 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for(int gap = 0; gap < n; gap++) {
        for(int i = 0; i + gap < n; i++) {
            int j = i + gap;

            if(gap == 0) {
                dp[i][j] = 0;
                continue;
            }

            int min = MMIN(i + 1 + dp[i + 1][j], j + 1 + dp[i][j - 1]);

            for(int k = i + 1; k < j; k++) {
                min = MMIN(min, k + 1 + MMAX(dp[i][k - 1], dp[k + 1][j]));
            }

            dp[i][j] = min;
        }
    }
/*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("dp[%d, %d] = %d     ", i, j, dp[i][j]);
        }
        printf("\n");
    }
*/
    return dp[0][n - 1];
}
```