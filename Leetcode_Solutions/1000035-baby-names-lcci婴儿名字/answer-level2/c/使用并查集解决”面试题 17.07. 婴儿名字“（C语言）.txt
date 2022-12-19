### 解题思路
本题的核心算法思路是并查集。

对于C语言开发者而言，字符串的分割，转换，也是一个难点，主要使用双指针的方式解决。

1.字符串解析，将名字+序号+人数组成数组，用于序号查找名字，以及结果的处理

2.建立名字和序号的hash，用于名字查找序号

3.根据重名表，将名字对应到序号，进行并查操作

4.将并查结果，利用1的表格进行汇总，并输出结果

注意，分拆字符串时，使用双指针进行处理。

![image.png](https://pic.leetcode-cn.com/b5678ae89e12c49e4dbbd0dc1273cb57d87709fb353204d2a19a406491f66314-image.png)


### 代码

```c
#define STR_LEN     50

typedef struct _info_st
{
    char name[STR_LEN];
    char *root;
    int id;
    int cnt;
}info_st;

typedef struct _hash_st
{
    char *key;
    int id;
    UT_hash_handle hh;
}hash_st;

int find(int *fa, int x)
{
    if(fa[x] == x)
    {
        return fa[x];
    }

    fa[x] = find(fa, fa[x]);

    return fa[x];
}

//将正整数n转成字符串s
void itoa(char *s, int n)
{
    if(n == 0)
    {
        s[0] = '0';
        s[1] = '\0';

        return ;
    }

    int nn = n;
    char tmps[16];
    int tid = 0;
    while(nn > 0)
    {
        tmps[tid++] = (nn % 10) + '0';
        nn /= 10;
    }

    for(int i = 0; i < tid; i++)
    {
        s[i] = tmps[tid - 1 - i];
    }

    s[tid] = '\0';
}

void join(int *fa, int x, int y)
{
    int xx = find(fa, x);
    int yy = find(fa, y);

    if(xx == yy)
    {
        return;
    }

    if(xx < yy)
    {
        fa[yy] = xx;
    }
    else
    {
        fa[xx] = yy;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//【算法思路】双指针+字符串+并查集。算法核心是并查集，辅助字符串处理。
// 1.字符串解析，将名字+序号+人数组成数组，用于序号查找名字，以及结果的处理
// 2.建立名字和序号的hash，用于名字查找序号
// 3.根据重名表，将名字对应到序号，进行并查操作
// 4.将并查结果，利用1的表格进行汇总，并输出结果
char** trulyMostPopular(char** names, int namesSize, char** synonyms, int synonymsSize, int* returnSize){
    if(namesSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    info_st *info = (info_st *)calloc(namesSize, sizeof(info_st));
    hash_st *pool = (hash_st *)calloc(namesSize, sizeof(hash_st));
    int psize = 0;

    hash_st *head = NULL;

    //将原有字符串解析成对应结构体信息,双指针
    for(int i = 0; i < namesSize; i++)
    {
        int tlen = strlen(names[i]);

        int ll = 0, rr = 0;

        char tmps[STR_LEN];

        int ncnt = 0;
        while(rr < tlen)
        {
            if(names[i][rr] != '(' && names[i][rr] != ')')
            {
                rr++;
                continue;
            }

            //处理名字和数量，将info序列赋值，并构建hash映射
            if(ncnt == 0)
            {
                int nlen = rr - ll;
                strncpy(info[i].name, &names[i][ll], nlen);
                //无需收尾
                //注意将root先指向自身
                info[i].root = info[i].name;
                info[i].id = i;

                //建立hash表
                hash_st *new = &pool[psize];
                new->key = info[i].name;
                new->id = i;

                hash_st *tmph;
                HASH_FIND(hh, head, new->key, nlen, tmph);

                if(tmph == NULL)
                {
                    HASH_ADD_KEYPTR(hh, head, new->key, nlen, new);
                    psize++;
                }

                ncnt++;

                rr++;
                ll = rr;
            }
            else
            {
                int nlen = rr - ll;
                strncpy(tmps, &names[i][ll], nlen);
                tmps[nlen] = '\0';

                info[i].cnt = atoi(tmps);
                break;
            }
        }

        //printf("%d: %s, %d   ", info[i].id, info[i].name, info[i].cnt);
    }
    //printf("\n");

    int *fa = (int *)calloc(namesSize, sizeof(int));
    for(int i = 0; i < namesSize; i++)
    {
        fa[i] = i;
    }

    //遍历重名表，建立并查关系
    for(int i = 0; i < synonymsSize; i++)
    {
        int slen = strlen(synonyms[i]);

        char tmps[2][STR_LEN];

        //第0位置是(
        int ll = 1, rr = 1;

        int ncnt = 0;
        while(rr < slen)
        {
            if(synonyms[i][rr] != ',' && synonyms[i][rr] != ')')
            {
                rr++;
                continue;
            }

            int nlen = rr - ll;

            strncpy(tmps[ncnt], &synonyms[i][ll], nlen);
            tmps[ncnt][nlen] = '\0';

            ncnt++;

            if(ncnt == 2)
            {
                break;
            }

            rr++;
            ll = rr;
        }

        //printf("%s; %s ", tmps[0], tmps[1]);

        int id[2];

        bool find = true;

        for(int j = 0; j < 2; j++)
        {
            hash_st *tmph;

            HASH_FIND(hh, head, tmps[j], strlen(tmps[j]), tmph);

            if(tmph == NULL)
            {
                find = false;
                break;
            }

            id[j] = tmph->id;
        }

        if(find == false)
        {
            continue;
        }

        //printf("%d; %d\n", id[0], id[1]);

        join(fa, id[0], id[1]);
    }
/*
    for(int i = 0; i < namesSize; i++)
    {
        printf("fa[%d] = %d,   ", i, fa[i]);
    }
    printf("\n");
*/
    int rsize = 0;
    //将归并结果进行整理
    for(int i = 0; i < namesSize; i++)
    {
        int ff = find(fa, i);

        //刷新根名字
        if(strcmp(info[i].name, info[ff].root) < 0)
        {
            info[ff].root = info[i].name;
        }

        if(i == ff)
        {
            rsize++;
            continue;
        }
        //刷新根数据
        info[ff].cnt += info[i].cnt;
    }

    //输出最终结果
    char **ret = (char **)calloc(rsize, sizeof(char *));
    int rid = 0;
    for(int i = 0; i < namesSize; i++)
    {
        if(i == find(fa, i))
        {
            ret[rid] = info[i].root;

            int tlen = strlen(ret[rid]);

            ret[rid][tlen++] = '(';

            itoa(&ret[rid][tlen], info[i].cnt);

            tlen = strlen(ret[rid]);

            ret[rid][tlen++] = ')';
            ret[rid][tlen++] = '\0';

            //printf("%s    ", ret[rid]);

            rid++;
        }
    }

    *returnSize = rsize;
    return ret;
}

```