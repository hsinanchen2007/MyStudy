### 解题思路
典型的字符串操作，关键在于将操作步骤进行分解。

为了处理方便，先将待查找下标进行排序。

1.将待带查找的index、source、target整合，使用qsort排序

2.查找tid（target index），在sid不等于tid时，进行数据拷贝

3.当sid等于tid时，判断source是否满足条件，注意超出尾部也判断为不满足条件

4.当不满足条件时更新tid，进行后面的处理。（关键点，如果没有下一个index，则使用slen，目的在于完成拷贝）

5.如果满足条件，则进行替换。为了方便处理，结果的rid和S的sid分别记录，互不影响。sid用于和index比较；rid主要用于结果拷贝。

6.完成处理输出结果

![image.png](https://pic.leetcode-cn.com/fe31d41d24c232636b99668a6abfa09e39ee1a13395f811a8000ce61c56d0dd6-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=833 lang=c
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start
#define RES_SIZE    10000
char res[RES_SIZE];

typedef struct _info_st
{
    int id;
    char *source;
    char *target;
}info_st;

int compare(const void *a, const void *b)
{
    return (*(info_st *)a).id - (*(info_st *)b).id;
}

//【算法思路】排序 + 字符串。一边复制一边寻找下标。找到后，检查是否匹配：匹配则进行拷贝；不匹配则开始下一个下标的寻找。如果下标用完，则寻找结尾，完成拷贝
// 注意s的游标和结果的游标，独立处理
char * findReplaceString(char * S, int* indexes, int indexesSize, char ** sources, int sourcesSize, char ** targets, int targetsSize){
    if(indexesSize == 0)
    {
        return S;
    }

    info_st *info = (info_st *)calloc(indexesSize, sizeof(info_st));
    for(int i = 0; i < indexesSize; i++)
    {
        info[i].id = indexes[i];
        info[i].source = sources[i];
        info[i].target = targets[i];
    }

    qsort(info, indexesSize, sizeof(info_st), compare);

    int slen = strlen(S);

    int sid = 0, iid = 0;
    int tid = info[iid].id;     //后面还会多次使用，完成比较后再更新iid
    int rid = 0;

    while(sid < slen)
    {
        if(sid != tid)
        {
            // 完成非替换数据的拷贝
            res[rid++] = S[sid++];
            continue;
        }

        //开始比较字符串是否相同
        bool same = true;

        int clen = strlen(info[iid].source);
        for(int i = tid; i < tid + clen; i++)
        {
            if(i >= slen || S[i] != info[iid].source[i - tid])
            {
                same = false;
                break;
            }
        }

        // 如果出现没有比过，则更新tid，继续下一次比较
        if(same == false)
        {
            iid++;
            //如果没有下一个待比较的index，则将其更新为slen，用于后面数据的拷贝
            tid = (iid < indexesSize)? info[iid].id : slen;

            continue;
        }

        // 如果比过，则进行替换拷贝
        int plen = strlen(info[iid].target);
        int pid = 0;
        int end = rid + plen;
        while(rid < end)
        {
            res[rid++] = info[iid].target[pid++];
        }

        //更新iid，tid，sid
        sid = tid + clen;
        iid++;
        tid = (iid < indexesSize)? info[iid].id : slen;
    }

    res[rid] = '\0';
    return res;
}


// @lc code=end


```