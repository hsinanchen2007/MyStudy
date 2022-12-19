### 解题思路
典型的hash表问题，需要两次进行映射，C语言使用uthash.h库解决。

1.构建内容->文档id的映射map0

2.遍历每个文档的内容

3.对于每个文档，将map0中查找到的文档id作为key，重合内容数作为val，构建map1

4.遍历map1生成结果

对于C语言来说，这里有两个坑：

(1)浮点精度问题，必须要在结果进行补偿 + 1e-9（这点对于编程题目来说是非常的不合理）
(2)C语言内存申请需要适当。由于C动态添加数据必须构造链表，如果使用数组必须提前申请空间，这里注意不能超出。

PS：用C盘leetcode，说多了都是泪。。。

![image.png](https://pic.leetcode-cn.com/f67a0b7e4476a8e1a7d1f503b48e2d4ba761c59122c57d04e82a8626ccd08b6d-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_IDS     200
#define RET_SIZE    100000
#define RET_STR_LEN 20

typedef struct _hash_c2i_st {
    int key;
    int ids[MAX_IDS];
    int isize;
    UT_hash_handle  hh;
}hash_c2i_st;

typedef struct _hash_icnt_st {
    int key;
    int val;
    UT_hash_handle  hh;
}hash_icnt_st;

char *ret[RET_SIZE];

//【算法思路】hash。
// 1.对文档内容建立hash，记录所属id
// 2.遍历文档id
// 3.对于1个id遍历其所有内容
// 4.根据内容查找hash，并生成结果
char** computeSimilarities(int** docs, int docsSize, int* docsColSize, int* returnSize){
    if(docsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    hash_c2i_st *head_c2i = NULL;

    //遍历所有内容，构建hash表
    for(int i = 0; i < docsSize; i++) {
        for(int j = 0; j < docsColSize[i]; j++) {
            int key = docs[i][j];

            hash_c2i_st *tmph;
            HASH_FIND(hh, head_c2i, &key, sizeof(int), tmph);
            if(tmph == NULL) {
                hash_c2i_st *new = (hash_c2i_st *)calloc(1, sizeof(hash_c2i_st));
                new->key = key;
                new->ids[0] = i;
                new->isize = 1;

                HASH_ADD_KEYPTR(hh, head_c2i, &new->key, sizeof(int), new);
            } else {
                tmph->ids[tmph->isize++] = i;
            }
        }
    }

    //遍历文档生成结果
    int rsize = 0;
    for(int i = 0; i < docsSize; i++) {
        hash_icnt_st *head_icnt = NULL;
        //构建对所有文档的映射统计
        for(int j = 0; j < docsColSize[i]; j++) {
            int key = docs[i][j];

            hash_c2i_st *tmph;
            HASH_FIND(hh, head_c2i, &key, sizeof(int), tmph);

            for(int k = 0; k < tmph->isize; k++) {
                int id = tmph->ids[k];
                
                //printf("id = %d, i = %d\n", id, i);

                //避免输出重复结果
                if(id <= i) {
                    continue;
                }

                hash_icnt_st *tmph_i;
                HASH_FIND(hh, head_icnt, &id, sizeof(int), tmph_i);
                if(tmph_i == NULL) {
                    hash_icnt_st *new = (hash_icnt_st *)calloc(1, sizeof(hash_icnt_st));
                    new->key = id;
                    new->val = 1;
                    
                    HASH_ADD_KEYPTR(hh, head_icnt, &new->key, sizeof(int), new);
                } else {
                    tmph_i->val++;
                }
            }
        }

        //目前已经统计了所有相关文档id，并记录了交集，现在进行结果输出
        hash_icnt_st *cur, *tmph;
        HASH_ITER(hh, head_icnt, cur, tmph) {
            char *str = (char *)calloc(RET_STR_LEN, sizeof(char));
            int id = cur->key;
            sprintf(str, "%d,%d: %.4f", i, id, (double)cur->val / (docsColSize[i] + docsColSize[id] - cur->val) + 1e-9);
            ret[rsize++] = str;
        }
    }

    *returnSize = rsize;
    return ret;
}
```