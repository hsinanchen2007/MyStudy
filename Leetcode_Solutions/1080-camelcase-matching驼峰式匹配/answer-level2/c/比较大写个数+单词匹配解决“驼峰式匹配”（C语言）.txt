### 解题思路
1.首先统计大写次数，不同的就返回false

2.quries和pattern逐字符比较即可。

![image.png](https://pic.leetcode-cn.com/1435f80fda5b998395454a2f888db02147711c6b1eed05e287d250055168f02b-image.png)


### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int get_cap_num(char *s)
{
    int cnt = 0;
    int slen = strlen(s);

    for(int i = 0; i < slen; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            cnt++;
        }
    }

    return cnt;
}

bool my_strcmp(char *s0, char *s1)
{
    int slen0 = strlen(s0);
    int slen1 = strlen(s1);
    int sid1 = 0;

    for(int i = 0; i < slen0; i++)
    {
        if(s0[i] != s1[sid1])
        {
            continue;
        }

        sid1++;

        if(sid1 == slen1)
        {
            break;
        }
    }
    //printf("%s : %s = %d\n", s0, s1, sid1 == slen1);

    return sid1 == slen1;
}

//【算法思路】贪心。贪心比较字符串，并且先用大写字母个数相同进行刷新。
bool* camelMatch(char ** queries, int queriesSize, char * pattern, int* returnSize){
    int pnum = get_cap_num(pattern);

    bool *res = (bool *)calloc(queriesSize, sizeof(bool));
    int rsize = 0;

    for(int i = 0; i < queriesSize; i++)
    {
        int qnum = get_cap_num(queries[i]);
        
        if(qnum != pnum)
        {
            res[rsize++] = false;
            continue;
        }

        res[rsize++] = my_strcmp(queries[i], pattern);
    }

    *returnSize = rsize;
    return res;
}


```