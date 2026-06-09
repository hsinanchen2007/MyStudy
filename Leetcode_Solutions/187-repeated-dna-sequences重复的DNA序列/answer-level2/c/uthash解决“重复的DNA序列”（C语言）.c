### 解题思路
1.将所有长度为10的字符串作为键值，查找hash表

2.如果没有找到，则将该元素放入hash表，初始val为1

3.如果找到，并且val == 1，则放入结果。该步有去重功能。

此题对于有hash表类型的语言非常简单，但对于C而言，最有方法是使用uthash库。

### 代码

```c
/*
 * @lc app=leetcode.cn id=187 lang=c
 *
 * [187] 重复的DNA序列
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define RES_SIZE    100000

char *res[RES_SIZE];

typedef struct _hash_st
{
    //key
    char key[11];
    //val
    int val;
    //hash handle
    UT_hash_handle hh;
}hash_st;

void my_strcpy(char *d, char *s, int len)
{
    for(int i = 0; i < len; i++)
    {
        d[i] = s[i];
    }
    d[len] = '\0';
}

// 【算法思路】hash+双指针。每10个字符为一个字符串，将所有字符串进行hash映射
// 使用uthash
char ** findRepeatedDnaSequences(char * s, int* returnSize){
    int slen = strlen(s);
    if(slen <= 10)
    {
        *returnSize = 0;
        return NULL;
    }

    hash_st *head = NULL;

    hash_st *pool = (hash_st *)calloc(RES_SIZE, sizeof(hash_st));
    int psize = 0;

    int rsize = 0;

    for(int i = 0; i <= slen - 10; i++)
    {
        //重复使用pool中元素，需要时增加
        hash_st * cur= &pool[psize];
        my_strcpy(cur->key, &s[i], 10);
        cur->val = 1;

        //printf("<%d>[%s %d]\n", i, cur->key, cur->val);

        hash_st *find;

        HASH_FIND_STR(head, cur->key, find);
        if(find == NULL)
        {
            HASH_ADD_STR(head, key, cur);

            //使用当前结构
            psize++;
            continue;
        }

        if(find->val == 1)
        {
            res[rsize++] = find->key;
        }

        find->val++;
    }

    *returnSize = rsize;
    return res;
}


// @lc code=end


```