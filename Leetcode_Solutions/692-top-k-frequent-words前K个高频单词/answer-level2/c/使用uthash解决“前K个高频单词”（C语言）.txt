### 解题思路
典型的hash应用，使用uthash的查找，增加，排序，遍历接口。

![image.png](https://pic.leetcode-cn.com/f5ade90ee6cb82695c3c17543fb302c53a3618d60ee1bfa77f6588c206cfca34-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=692 lang=c
 *
 * [692] 前K个高频单词
 */

// @lc code=start

#define POOL_SIZE   10000

typedef struct _info_st
{
    char *key;
    int val;
    UT_hash_handle hh;
}info_st;

int compare(info_st *a, info_st *b)
{
    if(a->val != b->val)
    {
        return b->val - a->val;
    }
    else
    {
        return strcmp(a->key, b->key);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 【算法思路】hash+排序。字符串指针作为key，注意uthash函数的使用
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    if(wordsSize == 0 || k == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    info_st * head = NULL;
    info_st * pool = (info_st *)calloc(POOL_SIZE, sizeof(info_st));
    int psize = 0;

    for(int i = 0; i < wordsSize; i++)
    {
        info_st *cur = &pool[psize];
        cur->key = words[i];
        cur->val = 1;

        //printf("<%d>%s  ", i, cur->key);

        info_st *tmph;
        HASH_FIND(hh, head, cur->key, strlen(cur->key), tmph);
        //HASH_FIND(hh, head, words[i], strlen(words[i]), tmph);

        if(tmph == NULL)
        {
            HASH_ADD_KEYPTR(hh, head, cur->key, strlen(cur->key), cur);
            psize++;
            continue;
        }

        tmph->val++;
    }
    //printf("\n");

    HASH_SORT(head, compare);

    char **res = (char **)calloc(psize, sizeof(char*));
    int rsize = 0;

    info_st *cur, *tmph;

    int id = 0;
    HASH_ITER(hh, head, cur, tmph)
    {
        //printf("<%d>[%s %d]   ", id, cur->key, cur->val);

        res[rsize++] = cur->key;
        id++;
        if(id == k)
        {
            //break;
        }
    }
    //printf("\n");

    *returnSize = k;
    return res;
}


// @lc code=end


```