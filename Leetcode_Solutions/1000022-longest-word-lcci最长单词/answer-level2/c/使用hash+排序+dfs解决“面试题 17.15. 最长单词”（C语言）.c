### 解题思路
本题关键点：（1）单词遍历；（2）线性查找；（3）结果筛选；

1.首先将单词按照长度递减，等长度字典序最小进行排序，以满足结果输出（查到即可输出）

2.将单词存入hash表，用于线性查找

3.对于单个单词，使用DFS遍历是否可以组合成功

注意，记录最长长度和最短长度，用于剪枝。

![image.png](https://pic.leetcode-cn.com/d06502f771e92b8900202c3e148a9ae9a59cb9f7dc37db0f85aaf03a55558e2a-image.png)



### 代码

```c
#define STR_LEN 150

#define MMAX(a, b)          ((a) > (b)? (a) : (b))
#define MMIN(a, b)          ((a) < (b)? (a) : (b))

int compare(const void *a, const void *b)
{
    char *aa  = (*(char**)a);
    char *bb  = (*(char**)b);
    if(strlen(aa) != strlen(bb))
    {
        return strlen(bb) - strlen(aa);
    }
    else
    {
        return strcmp(aa, bb);
    }
}

typedef struct _hash_st
{
    char *key;
    int val;
    UT_hash_handle hh;
}hash_st;

hash_st *head;

int max_len; 
int min_len;

bool helper(char *s)
{
    //printf("s: %s\n", s);
    int slen = strlen(s);

    if(slen == 0)
    {
        return true;
    }
    else if(slen < min_len)
    {
        return false;
    }

    char tmps[STR_LEN];

    for(int len = min_len; len < max_len; len++)
    {
        if(len > slen)
        {
            break;
        }

        strncpy(tmps, s, len);
        tmps[len] = '\0';

        hash_st *tmph;

        //printf("---->tmps: %s\n", tmps);
        //判断是否可以查找到tmps
        HASH_FIND(hh, head, tmps, len, tmph);

        if(tmph == NULL || tmph->val == 0)
        {
            continue;
        }

        bool ret = helper(&s[len]);

        if(ret == true)
        {
            return true;
        }
    }

    return false;
}

//【算法思路】qsort+hash+dfs。将单词使用hash记录，然后对每个单词进行判断dfs。
// 注意：记录最长单词和最短单词，用于剪枝
// 注意：结果要求输出最长字串，以及同等长度字典序最小，在排序中解决。
char* longestWord(char** words, int wordsSize){
    if(wordsSize <= 1)
    {
        return "";
    }

    hash_st *pool = (hash_st *)calloc(wordsSize, sizeof(hash_st));
    int psize = 0;

    head = NULL;

    max_len = INT_MIN; 
    min_len = INT_MAX;

    qsort(words, wordsSize, sizeof(char*), compare);

    //将字符串记录在hash，注意，去重添加
    for(int i = 0; i < wordsSize; i++)
    {
        int tlen = strlen(words[i]);
        max_len = MMAX(max_len, tlen);
        min_len = MMIN(min_len, tlen);

        //printf("%d: %s\n", i, words[i]);

        hash_st *new = &pool[psize];
        new->key = words[i];
        new->val = 1;

        hash_st *tmph;

        HASH_FIND(hh, head, new->key, strlen(new->key), tmph);

        if(tmph == NULL)
        {
            HASH_ADD_KEYPTR(hh, head, new->key, strlen(new->key), new);
            psize++;
        }
    }

    //printf("max_len = %d, min_len = %d\n", max_len, min_len);

    //遍历单词，进行查找
    for(int i = 0; i < wordsSize; i++)
    {
        int tlen = strlen(words[i]);

        if(tlen == min_len)
        {
            continue;
        }

        hash_st *tmph;
        HASH_FIND(hh, head, words[i], tlen, tmph);

        tmph->val = 0;

        bool ret = helper(words[i]);

        tmph->val = 1;

        if(ret == true)
        {
            return words[i];
        }
    }

    return "";
}
```