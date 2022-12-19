### 解题思路
典型的DFS问题，对于C语言而言，实现非常繁琐，这里给出具体实现。

1.首先构造邻接矩阵。
(1)使用hash表构建起始节点.
(2)起始节点对应的多个目标节点，按照字典序链接。这一点通过双链表插入实现。

2.开始DFS迭代。
(1)迭代参数为HASH表，当前起始节点，使用过的票数，票总数
(2)返回为是否完成串联。
(3)结果通过全局数组维护，写在对应的票数位置上。

这里有几点需要注意：
(1)返回结果个数为票数+1
(2)邻接矩阵中目标节点个数对应票数，在目标节点上标志该票是否已经使用。
(3)重复票
(4)无法记忆化加速，某一票的状态完全有其它票状态决定，而非只有唯一状态。
(5)实现时，没有释放节点内存，而是依赖leetcode环境处理。

总之，思路上本题为中等难度，实现上对于C语言而言，是属于困难级别的。

![image.png](https://pic.leetcode-cn.com/5c77ccf30a413bb83cc2c9f1d70abe83c10bce898576c43f5b53e289e1c4122e-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define RET_SIZE    1000

typedef struct _info_st {
    char *ap;
    int used;
    struct _info_st *pre;
    struct _info_st *nxt;
}info_st;

typedef struct _hash_st {
    char *key;
    info_st head;
    UT_hash_handle hh;
}hash_st;

char *ret[RET_SIZE];

//返回结果以双链表头节点指针形式表示，如果为NULL，则无法完成路线
//根据tar从head的邻接表中，向后递归。
//根据已经访问的机场和总机场数的关系判断是否已经完成路线
bool helper(hash_st *head, char *tar, int cnt, int total) {
    //printf("cnt = %d, total = %d\n", cnt, total);
    if(cnt == total) {
        //已经将所有票排序
        ret[cnt] = tar;
        return true;
    }

    hash_st *tmph;
    HASH_FIND(hh, head, tar, strlen(tar), tmph);

    //遍历目标站点，递归调用
    info_st *cur = tmph->head.nxt;

    while(cur != &tmph->head) {
        if(cur->used == 0) {
            cur->used = 1;

            //printf("%s:%s\n", tar, cur->ap);

            bool tmpr = helper(head, cur->ap, cnt + 1, total);
            if(tmpr == true) {
                ret[cnt] = tar;

                return true;
            }

            cur->used = 0;
        }

        cur = cur->nxt;
    }
    return false;
}



//【算法思路】HASH + 邻接表 + DFS。本题的难点在于邻接表的构建和结果的返回。
// 1.由于找到一条符合路径即可完成递归，因此使用DFS。
// 2.使用HASH表构建邻接表，将目的以双链表的形式串接
// 3.访问过的位置在链表节点中记录，链表节点与每张票相对应
char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize){
    if(ticketsSize == 0) {
        *returnSize == 0;
        return NULL;
    }

    hash_st *head = NULL;

    // 构建邻接表，机场按照字典序链接
    for(int i = 0; i < ticketsSize; i++) {
        char *key = tickets[i][0];
        char *tar = tickets[i][1];

        hash_st *tmph;
        HASH_FIND(hh, head, key, strlen(key), tmph);
        if(tmph == NULL) {
            tmph = (hash_st *)calloc(1, sizeof(hash_st));
            tmph->key = key;
            tmph->head.pre = &tmph->head;
            tmph->head.nxt = &tmph->head;

            HASH_ADD_KEYPTR(hh, head, tmph->key, strlen(tmph->key), tmph);
        }

        //按照字典序添加机场信息，利用cur查找第一个字典序大于tar的位置，需要插入在其之前
        info_st *cur = tmph->head.nxt;

        while(cur != &tmph->head) {
            int tmpr = strcmp(tar, cur->ap);

            if(tmpr <= 0) {
                break;
            } else {
                cur = cur->nxt;
            }
        }

        info_st *new = (info_st *)calloc(1, sizeof(info_st));
        new->ap = tar;

        new->nxt = cur;
        new->pre = cur->pre;
        cur->pre->nxt = new;
        cur->pre = new;

        //添加目标站点
        HASH_FIND(hh, head, tar, strlen(tar), tmph);
        if(tmph == NULL) {
            tmph = (hash_st *)calloc(1, sizeof(hash_st));
            tmph->key = tar;
            tmph->head.pre = &tmph->head;
            tmph->head.nxt = &tmph->head;

            HASH_ADD_KEYPTR(hh, head, tmph->key, strlen(tmph->key), tmph);
        }
    }
/*
    hash_st *hp0, *hp1;
    HASH_ITER(hh, head, hp0, hp1) {
        printf("%s: ", hp0->key);
        info_st *cur = hp0->head.nxt;

        while(cur != &hp0->head) {
            printf("%s   ", cur->ap);
            cur = cur->nxt;
        }
        printf("\n");
    }
    printf("\n");
*/
    // 开始递归查找
    helper(head, "JFK", 0, ticketsSize);

    *returnSize = ticketsSize + 1;
    return ret;
}
```