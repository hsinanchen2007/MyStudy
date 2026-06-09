### 解题思路
本题对于**C语言**的**难点在于动态结果数量**的问题。

这里没有采用申请pool的方式，而是规矩的采用，每次根据返回结果的数量，建立链表组织结果。

**算法**很经典，就是**统计**各个字符出现的数量，**保证在每个位置**，只**使用**这个字符**一次**即可。

注意字符包括大小写。

![image.png](https://pic.leetcode-cn.com/e9df5ebcb494f122c710fd9a0f8d64b8a7e9e8d7005a97df73acf2f11a8655a0-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define STR_LEN     16

//用于串接结果数组
typedef struct _info_st
{
    char *str;
    struct _info_st *nxt;
}info_st;

int *hash;
int slen;

char **helper(int id, int *returnSize)
{
    //处理最后一个字符,申请返回结果空间
    if(id == slen - 1)
    {
        char **ret = (char **)calloc(1, sizeof(char *));
        char *ret_ = (char *)calloc(STR_LEN, sizeof(char));
        ret[0] = ret_;
        for(int i = 0; i < 128; i++)
        {
            if(hash[i] != 0)
            {
                ret[0][0] = i;
                break;
            }
        }

        *returnSize = 1;
        return ret;
    }

    info_st *head = NULL;
    int rsize = 0;

    for(int i = 0; i < 128; i++)
    {
        if(hash[i] == 0)
        {
            continue;
        }
        
        //每个字符使用一次
        int tsize;

        hash[i] -= 1;
        char **ret = helper(id + 1, &tsize);
        hash[i] += 1;

        //将tsize个结果补充当前字串，并串入链表中
        for(int j = 0; j < tsize; j++)
        {
            info_st *cur = (info_st *)calloc(1, sizeof(info_st));
            cur->str = ret[j];
            //将当前结果补充进去
            cur->str[slen - 1 - id] = i;

            //串入链表
            cur->nxt = head;
            head = cur;
        }

        rsize += tsize;
    }

    //将链表中的所有结果，组织成二维数组
    char **ret = (char **)calloc(rsize, sizeof(char *));
    int rid = 0;

    info_st *cur = head;
    while(cur != NULL)
    {
        ret[rid++] = cur->str;
        cur = cur->nxt;
    }

    *returnSize  = rsize;
    return ret;
}

//【算法思路】DFS。不重复的遍历，是统计字符出现的个数，在每个位置只可使用一次。
// 在最后的字符申请空间，用于返回结果。
// 注意结果包括大小写。
// 单链表组织结果数据
char** permutation(char* s, int* returnSize){
    if(s == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    slen = strlen(s);

    if(slen == 0)
    {
        char **ret = (char **)calloc(1, sizeof(char *));
        ret[0] = "";

        *returnSize = 1;
        return ret;
    }

    int hash_[128] = {0};
    hash = hash_;

    for(int i = 0; i < slen; i ++)
    {
        hash[s[i]]++;
    }

    char **ret = helper(0, returnSize);

    return ret;
}
```