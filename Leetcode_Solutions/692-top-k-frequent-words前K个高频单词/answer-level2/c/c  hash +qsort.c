### 解题思路
hash + 排序， 单词作为key。

### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#inlcude <uthash.h>

#define MAX_SIZE 27

typedef struct hash {
    char name[MAX_SIZE];
    int cnt;
    UT_hash_handle hh;
}my_hash;


my_hash *users = NULL;


int cmp(void *a, void *b){
    my_hash *_a = (my_hash *)a;
    my_hash *_b = (my_hash *)b;
    if (_a->cnt == _b->cnt)
        return strcmp(a, b);
    return _b->cnt - _a->cnt;

}


void add_hash_list(char ** words, int wordsSize){
    int i;
    my_hash *node = NULL;

    for (i = 0 ; i < wordsSize; i++) {
        HASH_FIND_STR(users, words[i], node);
        if (node == NULL) {
            node = (my_hash *)malloc(sizeof(my_hash));
            strcpy(node->name, words[i]);
            node->cnt++;
            HASH_ADD_STR(users, name, node);            
        } else {
            node->cnt++;            
        }
    }
    HASH_SORT(users, cmp);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    int i;
    my_hash *node = NULL;
    my_hash *tmp = NULL;
    char **ret = NULL;

     if (words == NULL || wordsSize == 0 || k == 0 )
        return NULL;
    
    add_hash_list(words, wordsSize);

    ret = (char **)malloc(sizeof(char *) * k);
    for(i = 0 ; i < k; i++){
        ret[i] = (char *)malloc(sizeof(char) * MAX_SIZE);
        memset(ret[i], 0, MAX_SIZE);    
    }
    i = 0;
    HASH_ITER(hh, users, node, tmp){
        if (i < k) 
            strcpy(ret[i], node->name);    
        i++;
        HASH_DEL(users, node);
        free(node);
    }

    *returnSize = k;
    return ret;
}


```