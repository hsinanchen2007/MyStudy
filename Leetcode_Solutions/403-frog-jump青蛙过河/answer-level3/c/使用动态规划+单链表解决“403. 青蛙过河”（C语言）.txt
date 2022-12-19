### 解题思路
典型的二维动态规划题目，这里给出C语言的解法。

原始的dp含义为:dp[i][j] == true表示在位置i可以通过跳跃j步到达.

因此dp[i][j] 为遍历0~i所有位置，每个位置需要跳跃的距离为step = stones[i] - stones[j].

如果dp[j][step - 1],dp[j][step],dp[j][step + 1]有一个为true，表明可以跳跃到dp[i][step],则dp[i][step]为true。

但是步数的范围很大，因此实现的时候，将j维度变为单链表进行处理。

PS：结束时不进行节点的释放，用C刷题的同学应该理解。

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

typedef struct _node_st {
    long long jump;
    struct _node_st *nxt;
}node_st;

//【算法思路】二维dp+单链表。dp[i][j]表是第i个石头，通过前面的石头是否能够跳跃j步到达。
// 由于j范围过大，因此使用单链表结构。
bool canCross(int* stones, int stonesSize){
    node_st **dp = (node_st **)calloc(stonesSize, sizeof(node_st*));

    dp[0] = (node_st *)calloc(1, sizeof(node_st));
    dp[0]->jump = 0;

    for(int i = 1; i < stonesSize; i++) {
        for(int j = 0; j < i; j++) {
            long long  step = stones[i] - stones[j];

            //判断是否可以从之前步数跳跃过来，step-1，step，step+1
            node_st *cur = dp[j];

            while(cur != NULL) {
                if(cur->jump == step - 1 || cur->jump == step || cur->jump == step + 1) {
                    //可以跳跃过来
                    node_st *new = (node_st *)calloc(1,sizeof(node_st));
                    //printf("stones[%d] = %d, stones[%d] = %d, jump %d form %d to %d\n", i, stones[i], j, stones[j], step, j, i);
                    new->jump = step;
                    new->nxt = dp[i];
                    dp[i] = new;
                    break;
                }

                cur = cur->nxt;
            }
        }
    }
/*
    for(int i = 0; i < stonesSize; i++) {
        node_st *cur = dp[i];

        while(cur != NULL) {
            printf("dp[%d]:%d    ", i, cur->jump);
            cur = cur->nxt;
        }
        printf("\n");
    }
*/
    return dp[stonesSize - 1] != NULL;
}
```