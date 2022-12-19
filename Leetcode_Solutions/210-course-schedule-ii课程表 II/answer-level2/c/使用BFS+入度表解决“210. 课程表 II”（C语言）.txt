### 解题思路
经典的top排序问题，使用BFS解决。这里给出C语言的解法。

1.建立数组，存储各个节点入度表。

2.根据课程依赖关系，建立各个节点的邻接表

3.遍历入度表，将入度为0的节点入队

4.开始BFS，遍历队列中的节点，从邻接表查找其下一个节点

5.将下一个节点入度减一，如果入度为零，则入队

6.重复BFS过程，直至队列为空。

![image.png](https://pic.leetcode-cn.com/02f6d2442ca5045a5907caf5815731ec48ba20971a06a824ef86e0f68c8830f1-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QUE_LEN     1000
#define MAX_LEN     2000
#define MAX_SIZE    100

int que0_[QUE_LEN];
int que1_[QUE_LEN];

int *que0;
int *que1;

int adj[MAX_LEN][MAX_SIZE];
int adj_col[MAX_LEN];

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//【算法思路】BFS+图。从图的出度和入度考虑，进行层序遍历。
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    if(numCourses == 0) {
        goto FAIL;
    }

    int *ret = (int *)calloc(numCourses, sizeof(int));
    int rsize = 0;

    int *in_degree = (int *)calloc(numCourses, sizeof(int));

    for(int i = 0; i < numCourses; i++) {
        adj_col[i] = 0;
    }

    //初始化出入度表，和邻接表
    for(int i = 0; i < prerequisitesSize; i++) {
        int pre = prerequisites[i][1];
        int nxt = prerequisites[i][0];

        //更新入度表
        in_degree[nxt]++;

        //加入邻接表
        adj[pre][adj_col[pre]++] = nxt;
    }

    //准备bfs遍历
    que0 = que0_;
    que1 = que1_;
    int qsize0 = 0;
    int qsize1 = 0;

    //初始化序列
    for(int i = 0; i < numCourses; i++) {
        if(in_degree[i] == 0) {
            que0[qsize0++] = i;

            //生成结果
            ret[rsize++] = i;
        }
    }

    while(qsize0 > 0) {
        for(int i = 0; i < qsize0; i++) {
            int pre = que0[i];

            for(int j = 0; j < adj_col[pre]; j++) {
                int nxt = adj[pre][j];

                //处理对应nxt节点
                if(in_degree[nxt] != 0) {
                    in_degree[nxt]--;

                    if(in_degree[nxt] == 0) {
                        que1[qsize1++] = nxt;

                        //生成结果
                        ret[rsize++] = nxt;
                    }
                }
            }
        }

        int *tmpq = que0;
        que0 = que1;
        que1 = tmpq;
        qsize0 = qsize1;
        qsize1 = 0;
    }

    if(rsize < numCourses) {
        goto FAIL;
    }

    *returnSize = rsize;
    return ret;

FAIL:
    *returnSize = 0;
    return NULL;
}
```