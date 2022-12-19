### 解题思路
典型的棋类问题，判断能否到达某状态或步数，通常使用BFS或DFS+memo解决。

本题使用编程更为友好的BFS解决。

另外对于已经使用的状态或无法到达的状态，使用HASH表组织。

编程时注意，hash使用的地址为实际比对数据的地址，本题无需再加&。

![image.png](https://pic.leetcode-cn.com/8ca8fb2589f5832966df855674c4d22ed60ccf785caa15192050c48d92a4aee7-image.png)


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

#define QUE_LEN     10000

#define TURN_UP(c)  ((c) == '9'? '0' : (c) + 1)
#define TURN_DW(c)  ((c) == '0'? '9' : (c) - 1)

typedef struct _hash_st {
    char *key;
    //int val;
    UT_hash_handle hh;
}hash_st;

char start[] = "0000";

char *que0_[QUE_LEN];
char *que1_[QUE_LEN];

char **que0;
char **que1;

//【算法思路】BFS+HASH。探路类问题，使用BFS解决。
// 本题中，"一步移动"对应为调整一次锁密码。
int openLock(char ** deadends, int deadendsSize, char * target){
    if(strcmp(start, target) == 0) {
        return 0;
    }

    hash_st *head = NULL;
    //添加deadends到hash表
    for(int i = 0; i < deadendsSize; i++) {
        if(strcmp(start, deadends[i]) == 0) {
            return -1;
        }
        
        hash_st *new = (hash_st *)calloc(1, sizeof(hash_st));
        new->key = deadends[i];

        //注意这里的长度使用strlen
        HASH_ADD_KEYPTR(hh, head, new->key, strlen(new->key), new);
    }

    //初始化队列
    que0 = que0_;
    que1 = que1_;
    int qsize0 = 0;
    int qsize1 = 0;

    que0[qsize0++] = start;

    int step = 0;
    while(qsize0 > 0) {
        step++;
/*
        for(int i = 0; i < qsize0; i++) {
            printf("%s   ", que0[i]);
        }
        printf("\n");
*/
        for(int i = 0; i < qsize0; i++) {
            char *cur = que0[i];

            //遍历8个调整方式
            for(int j = 0; j < 4; j++) {
                //判断向上拨动
                char nxt[5];
                strncpy(nxt, cur, 5);

                nxt[j] = TURN_UP(nxt[j]);
                //printf("%s\n", nxt);
                if(strcmp(nxt, target) == 0) {
                    return step;
                }
                
                hash_st *tmph;
                HASH_FIND(hh, head, nxt, strlen(nxt), tmph);
                if(tmph == NULL) {
                    hash_st *new = (hash_st *)calloc(1, sizeof(hash_st));
                    new->key = (char *)calloc(5, sizeof(char));
                    strncpy(new->key, nxt, 5);

                    HASH_ADD_KEYPTR(hh, head, new->key, strlen(new->key), new);

                    que1[qsize1++] = new->key;
                }

                //判断向下拨动
                strncpy(nxt, cur, 5);
                nxt[j] = TURN_DW(nxt[j]);
                //printf("%s\n", nxt);
                if(strcmp(nxt, target) == 0) {
                    return step;
                }

                HASH_FIND(hh, head, nxt, strlen(nxt), tmph);
                if(tmph == NULL) {
                    hash_st *new = (hash_st *)calloc(1, sizeof(hash_st));
                    new->key = (char *)calloc(5, sizeof(char));
                    strncpy(new->key, nxt, 5);

                    HASH_ADD_KEYPTR(hh, head, new->key, strlen(new->key), new);

                    que1[qsize1++] = new->key;
                }
            }
        }

        char **tmpq = que0;
        que0 = que1;
        que1 = tmpq;

        qsize0 = qsize1;
        qsize1 = 0;
    }

    return -1;
}
```