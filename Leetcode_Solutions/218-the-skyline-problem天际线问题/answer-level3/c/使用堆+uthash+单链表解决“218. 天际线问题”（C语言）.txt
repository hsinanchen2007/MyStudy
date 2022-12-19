### 解题思路
本题解使用的思路是类似公交站问题的思路（其他题解叫做扫描），左边缘类似上车，右边缘类似下车，维护的信息位最高高度。

对于C语言而言，本题编程难度很大，主要用到：

1.uthash维护离散的边界信息；

2.单链表维护每个位置出现的边界位置（假设楼的边界会重合）

3.双链表实现大顶堆，用于维护高度信息

解题步骤为：

1.遍历各个楼，将边界信息记录到hash表中，以单链表形式记录

2.将hash表进行排序

3.遍历hash表，根据边界信息维护大顶堆

4.如果最高值发生变化，则输出一条结果信息

PS:本题没有进行内存节点释放，用C刷题的同学应该能理解。

### 代码

```c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define RET_LEN     10000

//用于记录每个站点的高度
typedef struct _node_st {
    int high;
    bool is_left;
    struct _node_st *nxt;
}node_st;

//用于记录离散站点
typedef struct _hash_st {
    int key;
    node_st *node_head;
    UT_hash_handle hh;
}hash_st;

//用于记录高度队列
typedef struct _que_st {
    int high;
    struct _que_st *pre;
    struct _que_st *nxt;
}que_st;

int compare(hash_st *a, hash_st *b) {
    return a->key > b->key? 1 : 
        (a->key == b->key? 0 : -1);
}

int *ret[RET_LEN];
int ret_col[RET_LEN];

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//【算法思路】优先队列+hash。公交站问题的思路，记录所有加入的左边界和清除的右边界，使用优先队列维护边界.
//站点无法用数组维护，使用hash表
int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    hash_st *hash_head = NULL;

    que_st que_head;
    que_head.high = -1;
    que_head.pre = &que_head;
    que_head.nxt = &que_head;

    //第一步，将所有站点上下的信息记录
    for(int i = 0; i < buildingsSize; i++) {
        int start = buildings[i][0];
        int end = buildings[i][1];
        int high = buildings[i][2];

        //加入信息节点
        node_st *new = (node_st *)calloc(1, sizeof(node_st));
        new->is_left = true;
        new->high = high;

        hash_st *tmph;
        HASH_FIND(hh, hash_head, &start, sizeof(int), tmph);
        if(tmph == NULL) {
            hash_st *new_hash = (hash_st *)calloc(1, sizeof(hash_st));
            new_hash->key = start;
            new_hash->node_head = new;

            HASH_ADD_KEYPTR(hh, hash_head, &new_hash->key, sizeof(int), new_hash);
        } else {
            new->nxt = tmph->node_head;
            tmph->node_head = new;
        }

        new = (node_st *)calloc(1, sizeof(node_st));
        new->is_left = false;
        new->high = high;

        HASH_FIND(hh, hash_head, &end, sizeof(int), tmph);
        if(tmph == NULL) {
            hash_st *new_hash = (hash_st *)calloc(1, sizeof(hash_st));
            new_hash->key = end;
            new_hash->node_head = new;

            HASH_ADD_KEYPTR(hh, hash_head, &new_hash->key, sizeof(int), new_hash);
        } else {
            new->nxt = tmph->node_head;
            tmph->node_head = new;
        }
    }
    HASH_SORT(hash_head, compare);
/*
    hash_st *cur, *tmph;
    HASH_ITER(hh, hash_head, cur, tmph) {
        node_st *node = cur->node_head;

        printf("pos %d: ", cur->key);
        while(node != NULL) {
            printf(" %d(%d)  ", node->high, node->is_left);
            node = node->nxt;
        }
        printf("\n");
    }
*/
    int rsize = 0;
    int highest = 0;
    //第二步，遍历路程，记录边界信息
    hash_st *cur_hash, *tmp_hash;
    HASH_ITER(hh, hash_head, cur_hash, tmp_hash) {
        node_st *cur = cur_hash->node_head;
        int pos = cur_hash->key;
        while(cur != NULL) {
            int high = cur->high;

            if(cur->is_left == true) {
                //将边界加入队列，首先找到小于等于该高度的位置
                que_st *tmpq = que_head.nxt;

                while(tmpq != &que_head) {
                    if(tmpq->high <= high) {
                        break;
                    }

                    tmpq = tmpq->nxt;
                }

                //printf("cur->high = %d, tmpq->high = %d\n", cur->high, tmpq->high);

                //建立节点插入之前
                que_st *new = (que_st *)calloc(1, sizeof(que_st));
                new->high = high;

                new->nxt = tmpq;
                new->pre = tmpq->pre;
                tmpq->pre->nxt = new;
                tmpq->pre = new;
            } else {
                //找到对应高度的节点，删除
                que_st *tmpq = que_head.nxt;

                while(tmpq != &que_head) {
                    if(tmpq->high == high) {
                        break;
                    }

                    tmpq = tmpq->nxt;
                }

                tmpq->pre->nxt = tmpq->nxt;
                tmpq->nxt->pre = tmpq->pre;
            }
            
            cur = cur->nxt;
        }
/*
        //刷新天际线
        {
            que_st *tmpq = que_head.nxt;
            
            printf("que:");
            while(tmpq != &que_head) {
                printf("  %d   ", tmpq->high);
                tmpq = tmpq->nxt;
            }
            printf("\n");
        }
*/
        que_st *tmpq = que_head.nxt;
        int new_high = tmpq == &que_head? 0 : tmpq->high;
        if(highest != new_high) {
            highest = new_high;

            ret[rsize] = (int *)calloc(2, sizeof(int));
            ret[rsize][0] = pos;
            ret[rsize][1] = highest;
            ret_col[rsize] = 2;
            rsize++;
        }
    }

    *returnSize = rsize;
    *returnColumnSizes = ret_col;
    return ret;
}

```