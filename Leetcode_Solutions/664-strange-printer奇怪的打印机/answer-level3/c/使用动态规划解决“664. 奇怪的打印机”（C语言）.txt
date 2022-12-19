### 解题思路
典型的分组DP。

1.DP[i][j]表示s从i到j的打印次数。

2.重点问题需要解决：**当k属于[i,j]，以s[i]==s[k]的k点划分的两部分，如何求解**

3.对于dp[i][k]，可以用dp[i][k] = dp[i][k - 1]解决

4.对于dp[k+1][j],已经由之前的子问题解决。

至此，问题可以分解为自下而上的多个子问题，逐层求解。

### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX_LEN 101

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int dp[MAX_LEN][MAX_LEN];

//【算法思路】分组dp。经典的分组dp模型，重点解决的问题，是切割后左半部分的处理方法。
//          dp[i][j]表示从s[i]到s[j]的打印次数，dp[i][j]可以由k属于i~j中的所有s[i] == s[k]的k点分解
//          表明s[i]和s[k]由一次打印完成
// 1.范围从小到大
// 2.当s[i] == s[k]将问题分解为两部分，分别解决两侧的问题
// 3.处理切割出的两部分，dp[i][k] = dp[i][k-1]（子问题）；dp[k+1][j]已经求出（子问题）
int strangePrinter(char * s){
    int slen = strlen(s);
    if(slen == 0) {
        return 0;
    }

    for(int i = 0; i < slen; i++) {
        for(int j = 0; j < slen; j++) {
            dp[i][j] = 0;
        }
    }

    for(int gap = 0; gap < slen; gap++) {
        for(int i = 0; i + gap < slen; i++) {
            int j = i + gap;

            if(gap == 0) {
                dp[i][j] = 1;
                continue;
            }

            int tmin = INT_MAX;

            for(int k = i; k <= j; k++) {
                if(k == i) {
                    tmin = MMIN(tmin, 1 + dp[i + 1][j]);
                } else if(s[i] == s[k] && k == j) {
                    tmin = MMIN(tmin, dp[i][j - 1]);
                } else if(s[i] == s[k]){
                    tmin = MMIN(tmin, dp[i][k - 1] + dp[k + 1][j]);
                }
            }

            dp[i][j] = tmin;
        }
    }
/*
    for(int i = 0; i < slen; i++) {
        for(int j = 0; j < slen; j++) {
            printf("[%d,%d]%d    ", i, j, dp[i][j]);
        }
        printf("\n");
    }
*/
    return dp[0][slen - 1];
}
```