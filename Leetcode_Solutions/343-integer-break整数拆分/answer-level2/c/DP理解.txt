### 解题思路

 * DP两个思路
 * 定义D[i]表示：和为i的整数乘积的最大值

 * 一 定义j为不大于i的点的位置
 *  D[i] = MAX(D[i], (j - i) * 下一级状态)
    这里长度用j - i表示，下一级状态一定要用MAX求D[i]和i的最大，反例比如D[3]
    得到：
    D[i] = MAX(D[i], (j - i) * MAX(D[j], j));

* 二 定义j为不大于i的距离
    D[i] = MAX(D[i], 长度的代价 * 下一级状态)
    长度代价应该是MAX(D[j], j)
    下一级状态 MAX(D[i - j], i - j)
    得到：
    D[i] = MAX(D[i], MAX(D[j], j) * MAX(D[i - j], i - j));


### 代码

```c


#include <stdlib.h>
#include <stdio.h>
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
int integerBreak(int n){
    int *D = (int *)malloc(sizeof(int) * (n + 1));
    if (D == NULL) {
        return -1;
    }
    memset(D, 0x0, sizeof(D));
    D[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            D[i] = MAX(D[i], MAX(D[j], j) * MAX(D[i - j], i - j));
        }
    }

    int ret = D[n];
    free(D);
    return ret;
}
```