### 解题思路
典型的BFS问题，注意点为：
（1）使用邻接矩阵加速查找，邻接矩阵更为编程友好
（2）路标记录到达该节点时间，加入访问队列的条件是：a.初次访问该节点；b.再次访问该节点时耗时更短

![image.png](https://pic.leetcode-cn.com/d60877440a87bfb53a17f0f4d410cde119289e393c241ae49784c0b1908391c6-image.png)


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

#define MAX_LEN     100

int matrix[MAX_LEN][MAX_LEN];

#define QUE_LEN     10000

typedef struct _que_st {
    int n;
    int t;
}que_st;

que_st que0_[QUE_LEN];
que_st que1_[QUE_LEN];

que_st *que0;
que_st *que1;

//【算法思路】BFS + 邻接矩阵 + 路标。
// 1.节点数目固定，邻接矩阵更为编程友好
// 2.关键点：BFS遍历会遇到重复访问的节点，这时策略为“如果当前节点比之前访问时更短，则加入到队列中”。
int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K){
    if(N == 1) {
        return 0;
    }

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            matrix[i][j] = 0;
        }
    }

    //建立邻接矩阵,存储为实际时间+1
    for(int i = 0; i < timesSize; i++) {
        int s = times[i][0];
        int d = times[i][1];
        int t = times[i][2];

        matrix[s][d] = t + 1;
    }

    //建立路标数组,存储信息为实际到达时间+1
    int *flags = (int *)calloc(N + 1, sizeof(int));

    //初始化
    que0 = que0_;
    que1 = que1_;
    int qsize0 = 0;
    int qsize1 = 0;

    que0[qsize0].n = K;
    que0[qsize0].t = 0;
    qsize0++;

    flags[K] = 1;

    while(qsize0 > 0) {
        for(int i = 0; i < qsize0; i++) {
            int n = que0[i].n;
            int t = que0[i].t;

            //遍历邻接矩阵
            for(int j = 0; j <= N; j++) {
                if(j == n || matrix[n][j] == 0) {
                    continue;
                }

                //注意包含了+1
                int new_t = t + matrix[n][j];

                //如果之前没有到达过j或者到达j的时间比当前长，则将j放入队列
                if(flags[j] == 0 || flags[j] > new_t) {
                    que1[qsize1].n = j;
                    //去掉+1
                    que1[qsize1].t = new_t - 1;
                    qsize1++;

                    //更新路标
                    flags[j] = new_t;
                }
            }
        }

        que_st *tmpq = que0;
        que0 = que1;
        que1 = tmpq;

        qsize0 = qsize1;
        qsize1 = 0;
    }
/*
    for(int i = 1; i <= N; i++) {
        printf("<%d> %d    ", i, flags[i]);
    }
    printf("\n");
*/
    int max = 0;
    for(int i = 1; i <= N; i++) {
        if(flags[i] == 0) {
            //无法到达当前节点
            return -1;
        }

        max = MMAX(max, flags[i] - 1);
    }

    return max;
}
```