### 解题思路
经典的分组DP类型题目，主要思想是，将数据进行拆分，获得各个拆分后的子问题解，然后得到最终结果。

问题的难点在于子问题的解决。这里采用DFS+记忆化的方法，

本题拆解的子问题为：求解从i到j并且尾部附带和j相同的k个盒子的序列的结果。

解决思路为：

1.按照分组动态规划的结构，从底向顶构造子问题序列

2.针对子问题，设计递归函数解决，helper(int s, int d, int tail)表示从s到d，并且结尾附带tail个盒子的序列的结果

3.子问题拆解为，从序列中遍历和d的盒子相同的位置，以该位置为分割点，生成两个子问题。

即：helper(boxes, s, i, tail + 1) + helper(boxes, i + 1, e - 1, 0)

4.求解该子问题时，使用记忆化方法进行加速。

PS：本题个人不喜欢纯DP的解法，虽然纯DP方法速度更快（无函数递归调用），但是还是**DFS+memo的方法更容易理解和掌握**。

![image.png](https://pic.leetcode-cn.com/7a9352cb95f6d050368baaae05a1ddbaff6e679bdf17545c351309a76a527bf2-image.png)


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

int memo[MAX_LEN][MAX_LEN][MAX_LEN];

int helper(int *boxes, int s, int e, int tail) {
    if(memo[s][e][tail] != 0) {
        return memo[s][e][tail] - 1;
    }

    if(s == e) {
        memo[s][e][tail] = (1 + tail) * (1 + tail) + 1;
        return (1 + tail) * (1 + tail);
    }

    int max = helper(boxes, s, e - 1, 0) + (1 + tail) * (1 + tail);

    for(int i = e - 1; i >= s; i--) {
        if(boxes[i] == boxes[e]) {
            max = MMAX(max, helper(boxes, s, i, tail + 1) + (i + 1 < e? helper(boxes, i + 1, e - 1, 0) : 0));
        }
    }

    memo[s][e][tail] = max + 1;

    return max;
}

int removeBoxes(int* boxes, int boxesSize){
    if(boxesSize < 2) {
        return boxesSize;
    }

    for(int i = 0; i < boxesSize; i++) {
        for(int j = 0; j < boxesSize; j++) {
            for(int k = 0; k < boxesSize; k++) {
                memo[i][j][k] = 0;
            }
        }
    }

    for(int gap = 0; gap < boxesSize; gap++) {
        for(int i = 0; i + gap < boxesSize; i++) {
            int j = i + gap;

            int max = helper(boxes, i, j, 0);
        }
    }
/*
    for(int i = 0; i < boxesSize; i++) {
        for(int j = 0; j < boxesSize; j++) {
            for(int k = 0; k < boxesSize; k++) {
                printf("[%d, %d, %d] %d    ", i, j, k, memo[i][j][k]);
            }
            printf("\n");
        }
    }
*/
    return memo[0][boxesSize - 1][0] - 1;
}
```