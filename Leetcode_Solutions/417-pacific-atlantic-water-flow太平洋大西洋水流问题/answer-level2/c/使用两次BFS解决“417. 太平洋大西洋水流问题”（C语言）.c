### 解题思路
经典的BFS题型。采用左上到右下，右下到左上两遍BFS解决，这里给出C语言的解法。

这里flags要设置两个值，从左上出发，设置为1

从右下出发，设置为2。过程中如果碰到1，则存入结果。

注意，如果使用DFS，由于相等高度可以回流，因此无法使用记忆化加速，会超时。

![image.png](https://pic.leetcode-cn.com/e8aa8ade2814f19f3ff4775b2fb691228f610fd412d189057e3369c8d97536b7-image.png)


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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define QUE_LEN     10000
#define MAX_LEN     150
#define RET_LEN     10000

typedef struct _pos_st {
    int y;
    int x;
}pos_st;

pos_st que0_[QUE_LEN];
pos_st que1_[QUE_LEN];

pos_st *que0;
pos_st *que1;

int qsize0;
int qsize1;

int flags[MAX_LEN][MAX_LEN];

int ret_[RET_LEN][2];
int *ret[RET_LEN];
int ret_col[RET_LEN];
int rsize;

//【算法思路】BFS。两遍BFS，先从topleft开始正序遍历，判断下右两个方向；再从bottemright开始逆序遍历，判断左上两个方向。
// 注意：由于相邻等于的情况存在，因此DFS无法加速，容易超时。
int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    if(matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int row = matrixSize;
    int col = matrixColSize[0];

    //初始化
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            flags[i][j] = 0;
        }
    }

    //从左上到右下，第一次遍历
    que0 = que0_;
    que1 = que1_;
    qsize0 = 0;
    qsize1 = 0;

    //放入初始数据
    for(int i = 0; i < col; i++) {
        que0[qsize0].y = 0;
        que0[qsize0].x = i;
        qsize0++;

        flags[0][i] = 1;
    }

    for(int i = 1; i < row; i++) {
        que0[qsize0].y = i;
        que0[qsize0].x = 0;
        qsize0++;

        flags[i][0] = 1;
    }

    while(qsize0 > 0) {
        for(int i = 0; i < qsize0; i++) {
            int y = que0[i].y;
            int x = que0[i].x;

            //上
            if(y > 0 && flags[y - 1][x] != 1 && matrix[y][x] <= matrix[y - 1][x]) {
                flags[y - 1][x] = 1;

                que1[qsize1].y = y - 1;
                que1[qsize1].x = x;
                qsize1++;
            }

            //左
            if(x > 0 && flags[y][x - 1] != 1 && matrix[y][x] <= matrix[y][x - 1]) {
                flags[y][x - 1] = 1;

                que1[qsize1].y = y;
                que1[qsize1].x = x - 1;
                qsize1++;
            }

            //下
            if(y < row - 1 && flags[y + 1][x] != 1 && matrix[y][x] <= matrix[y + 1][x]) {
                flags[y + 1][x] = 1;

                que1[qsize1].y = y + 1;
                que1[qsize1].x = x;
                qsize1++;
            }

            //右
            if(x < col - 1 && flags[y][x + 1] != 1 && matrix[y][x] <= matrix[y][x + 1]) {
                flags[y][x + 1] = 1;

                que1[qsize1].y = y;
                que1[qsize1].x = x + 1;
                qsize1++;
            }
        }

        pos_st *tmpq = que0;
        que0 = que1;
        que1 = tmpq;
        qsize0 = qsize1;
        qsize1 = 0;
    }
/*
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("flags[%d][%d] = %d   ", i, j, flags[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/
    //放入初始数据
    int rsize = 0;

    que0 = que0_;
    que1 = que1_;
    qsize0 = 0;
    qsize1 = 0;

    for(int i = 0; i < col; i++) {
        que0[qsize0].y = row - 1;
        que0[qsize0].x = i;
        qsize0++;

        if(flags[row - 1][i] == 1) {
            ret[rsize] = ret_[rsize];
            ret[rsize][0] = row - 1;
            ret[rsize][1] = i;
            ret_col[rsize] = 2;
            rsize++;
        }

        flags[row - 1][i] = 2;
    }

    for(int i = 0; i < row - 1; i++) {
        que0[qsize0].y = i;
        que0[qsize0].x = col - 1;
        qsize0++;

        if(flags[i][col - 1] == 1) {
            ret[rsize] = ret_[rsize];
            ret[rsize][0] = i;
            ret[rsize][1] = col - 1;
            ret_col[rsize] = 2;
            rsize++;
        }

        flags[i][col - 1] = 2;
    }

    while(qsize0 > 0) {
        for(int i = 0; i < qsize0; i++) {
            int y = que0[i].y;
            int x = que0[i].x;

            //上
            if(y > 0 && flags[y - 1][x] != 2 && matrix[y][x] <= matrix[y - 1][x]) {
                if(flags[y - 1][x] == 1) {
                    ret[rsize] = ret_[rsize];
                    ret[rsize][0] = y - 1;
                    ret[rsize][1] = x;
                    ret_col[rsize] = 2;
                    rsize++;
                }

                flags[y - 1][x] = 2;

                que1[qsize1].y = y - 1;
                que1[qsize1].x = x;
                qsize1++;
            }

            //左
            if(x > 0 && flags[y][x - 1] != 2 && matrix[y][x] <= matrix[y][x - 1]) {
                if(flags[y][x - 1] == 1) {
                    ret[rsize] = ret_[rsize];
                    ret[rsize][0] = y;
                    ret[rsize][1] = x - 1;
                    ret_col[rsize] = 2;
                    rsize++;
                }

                flags[y][x - 1] = 2;

                que1[qsize1].y = y;
                que1[qsize1].x = x - 1;
                qsize1++;
            }

            //下
            if(y < row - 1 && flags[y + 1][x] != 2 && matrix[y][x] <= matrix[y + 1][x]) {
                if(flags[y + 1][x] == 1) {
                    ret[rsize] = ret_[rsize];
                    ret[rsize][0] = y + 1;
                    ret[rsize][1] = x;
                    ret_col[rsize] = 2;
                    rsize++;
                }

                flags[y + 1][x] = 2;

                que1[qsize1].y = y + 1;
                que1[qsize1].x = x;
                qsize1++;
            }

            //右
            if(x < col - 1 && flags[y][x + 1] != 2 && matrix[y][x] <= matrix[y][x + 1]) {
                if(flags[y][x + 1] == 1) {
                    ret[rsize] = ret_[rsize];
                    ret[rsize][0] = y;
                    ret[rsize][1] = x + 1;
                    ret_col[rsize] = 2;
                    rsize++;
                }

                flags[y][x + 1] = 2;

                que1[qsize1].y = y;
                que1[qsize1].x = x + 1;
                qsize1++;
            }
        }

        pos_st *tmpq = que0;
        que0 = que1;
        que1 = tmpq;
        qsize0 = qsize1;
        qsize1 = 0;
    }
/*
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("flags[%d][%d] = %d   ", i, j, flags[i][j]);
        }
        printf("\n");
    }
*/
    *returnSize = rsize;
    *returnColumnSizes = ret_col;
    return ret;
}
```