### 解题思路
经典的字符串DP，这里给出C语言的解法。

dp[i][j]表示从i到j子串中，回文长度。

如果s[i] == s[j]则dp[i][j] = dp[i + 1][j - 1] + 2;

否则，dp[i][j] = MMAX(dp[i][j - 1], dp[i + 1][j])。

注意，自底向上的动态规划，dp数组无需初始化。

![image.png](https://pic.leetcode-cn.com/d50c8668a1ff014b403c8961efc8e40914d35ac4dea77b12538b2206ba49377d-image.png)


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

//【算法思路】字符串dp。
int longestPalindromeSubseq(char * s){
    if(s == NULL || strlen(s) == 0) {
        return 0;
    }

    int slen = strlen(s);
/*
    for(int i = 0; i < slen; i++) {
        for(int j = 0; j < slen; j++) {
            dp[i][j] = 0;
        }
    }
*/
    int max = 1;
    for(int gap = 0; gap < slen; gap++) {
        for(int i = 0; i + gap < slen; i++) {
            int j = i + gap;

            if(gap == 0) {
                dp[i][j] = 1;
                continue;
            }

            if(s[i] == s[j]) {
                dp[i][j] = gap == 1? 2 : dp[i + 1][j - 1] + 2;
            } else {
                //找到子序列中和j相等的字符
                dp[i][j] = MMAX(dp[i][j - 1], dp[i + 1][j]);
            }

            max = MMAX(max, dp[i][j]);
        }
    }
/*
    for(int i = 0; i < slen; i++) {
        for(int j = 0; j < slen; j++) {
            printf("[%d, %d] = %d    ", i, j, dp[i][j]);
        }
        printf("\n");
    }
*/
    return max;
}
```