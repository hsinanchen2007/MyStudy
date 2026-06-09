### 解题思路
经典的BFS题型，新颖之处在于：**由于站点范围很大，使用路线作为遍历的节点**，这里给出C语言的接法。

c语言的难点在于邻接表的实现，本题选择了固定长度数组实现，给定合适的数组范围。

1.将原有线路的站点进行排序，便于后续快速查找

2.构建邻接表

3.根据邻接表，按照层序进行遍历

4.如果再某条线路中找到对应站点，遍历结束；否则返回-1

![image.png](https://pic.leetcode-cn.com/8f64dafb63dbaf6b2fd89b7083626695f66f6b7fefcd3bc11d4d4a8031388b11-image.png)


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

#define QUE_LEN     1000
#define ADJ_LEN     500
#define ADJ_WIDTH   300

typedef struct _adj_st {
    int ids[ADJ_WIDTH];
    int num;
}adj_st;

adj_st adj[ADJ_LEN];

int que0_[QUE_LEN];
int que1_[QUE_LEN];

int *que0;
int *que1;

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

//【算法思路】BFS + 排序 + 双指针。站点范围极大，因此以路线为单位进行广度遍历。
// 1.构建路线的邻接表
// 2.基于路线邻接表进行广度遍历
// 3.两路线是否相交的判定，使用排序+双指针
int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int S, int T){
    if(routesSize == 0 || routesColSize[0] == 0) {
        return -1;
    }

    //站点数据排序
    for(int i = 0; i < routesSize; i++) {
        qsort(routes[i], routesColSize[i], sizeof(int), compare);
    }

    //初始化邻接表
    for(int i = 0; i < routesSize; i++) {
        adj[i].num = 0;
    }

    //构建临接矩阵
    for(int i = 0; i < routesSize; i++) {
        for(int j = i + 1; j < routesSize; j++) {
            //双指针判断两条路线是否存在链接关系
            int p1 = 0;
            int p2 = 0;

            bool find = false;
            while(p1 < routesColSize[i] && p2 < routesColSize[j]) {
                if(routes[i][p1] == routes[j][p2]) {
                    find = true;
                    break;
                } else if(routes[i][p1] > routes[j][p2]) {
                    p2++;
                } else {
                    p1++;
                }
            }

            if(find) {
                adj[i].ids[adj[i].num++] = j;
                adj[j].ids[adj[j].num++] = i;
            }
        }
    }
/*
    for(int i = 0; i < routesSize; i++) {
        printf("%d: ", i);
        for(int j = 0; j < adj[i].num; j++) {
            printf("%d   ", adj[i].ids[j]);
        }
        printf("\n");
    }
*/
    //bfs遍历链接关系
    int *flags = (int *)calloc(routesSize, sizeof(int));

    que0 = que0_;
    que1 = que1_;
    int qsize0 = 0;
    int qsize1 = 0;

    //初始化队列
    bool find = false;
    for(int i = 0; i < routesSize; i++) {
        for(int j = 0; j < routesColSize[i]; j++) {
            if(routes[i][j] == S) {
                find = true;
                que0[qsize0++] = i;
                flags[i] = 1;
                break;
            } else if(routes[i][j] > S) {
                break;
            }
        }
    }

    if(find == false) {
        return -1;
    }

    if(S == T) {
        return 0;
    }

    //初始查找que0内部的线路
    for(int i = 0; i < qsize0; i++) {
        int id = que0[i];
        for(int j = 0; j < routesColSize[id]; j++) {
            if(routes[id][j] == T) {
                return 1;
            } else if(routes[id][j] > T) {
                break;
            }
        }
    }

    //BFS,注意已经检查过que0内的线路了
    int step = 1;
    while(qsize0 > 0) {
        step++;
/*
        for(int i = 0; i < qsize0; i++) {
            printf("%d   ", que0[i]);
        }
        printf("\n");
*/
        for(int i = 0; i < qsize0; i++) {
            int cid = que0[i];

            for(int j = 0; j < adj[cid].num; j++) {
                int nid = adj[cid].ids[j];

                if(flags[nid] == 0) {
                    //检查要放到que1的线路
                    for(int k = 0; k < routesColSize[nid]; k++) {
                        if(routes[nid][k] == T) {
                            return step;
                        }
                    }

                    que1[qsize1++] = nid;
                    flags[nid] = 1;
                }
            }
        }

        int *tmpq = que0;
        que0 = que1;
        que1 = tmpq;
        qsize0 = qsize1;
        qsize1 = 0;
    }

    return -1;
}
```