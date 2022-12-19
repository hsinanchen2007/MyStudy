### 解题思路
经典的字符串dp，类型为解决1或2个字串的动态规划问题。这里给出C语言解法。

1.dp[i][j]表示word1的0~i和word2的0~j对应的解。

2.当word1[i] == word2[j]时，dp[i][j] = dp[i - 1][j - 1]

3.当word1[i] != word2[j]时，dp[i][j] = MMIN(dp[i - 1][j], MMIN(dp[i][j - 1], dp[i - 1][j - 1])) + 1;

![image.png](https://pic.leetcode-cn.com/8aa77a971bdb7e57ad3bb21f22598dbacb0557315b3744d2aaf5a218a42f7fe6-image.png)


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

//【算法思路】字符串DP。
int minDistance(char * word1, char * word2){
    int wlen1 = strlen(word1);
    int wlen2 = strlen(word2);

    if(wlen1 == 0 || wlen2 == 0) {
        return MMAX(wlen1, wlen2);
    }

    for(int i = 0; i <= wlen1; i++) {
        for(int j = 0; j <= wlen2; j++) {
            dp[i][j] = 0;
        }
    }

    //从word1获得空字串，删除i
    for(int i = 0; i <= wlen1; i++) {
        dp[i][0] = i;
    }

    //从空字串获得word2，插入i
    for(int i = 0; i <= wlen2; i++) {
        dp[0][i] = i;
    }

    for(int i = 1; i <= wlen1; i++) {
        for(int j = 1; j <= wlen2; j++) {
            int id1 = i - 1;
            int id2 = j - 1;
            if(word1[id1] == word2[id2]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = MMIN(dp[i - 1][j], MMIN(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
/*
    for(int i = 0; i <= wlen1; i++) {
        for(int j = 0; j <= wlen2; j++) {
            printf("dp[%d][%d] = %d   ", i, j, dp[i][j]);
        }
        printf("\n");
    }
*/
    return dp[wlen1][wlen2];
}
```