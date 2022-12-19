### 解题思路
本题的基本算法思路是DFS，并采用记忆化剪枝。

1.首先将字符串分成若干个（布尔运算符个数）个左右子串

2.分别求解左右子问题的0和1的解的个数

3.利用左右子问题的解，合成主问题的解

![image.png](https://pic.leetcode-cn.com/a05063bff5027a8bd431beabb8a9efde261f97e6229acc955f5ebd36d236e453-image.png)


### 代码

```c
#define MEMO_SIZE   50

typedef struct _info_st
{
    bool valid;
    int ocnt;
    int zcnt;
}info_st;

info_st memo[MEMO_SIZE][MEMO_SIZE];

char *ss;
int slen;

info_st *helper(int sid, int len)
{
    if(memo[sid][len].valid == true)
    {
        return &memo[sid][len];
    }

    if(len == 1)
    {
        memo[sid][len].valid = true;
        memo[sid][len].ocnt = ss[sid] == '1'? 1 : 0;
        memo[sid][len].zcnt = ss[sid] == '0'? 1 : 0;

        return &memo[sid][len];
    }

    //计算符号个数
    int symb_num = len / 2;

    info_st ret = {0};

    //遍历所有划分
    for(int i = 0; i < symb_num; i++)
    {
        //计算符号位置
        int id = sid + i * 2 + 1;
        char symb = ss[id];

        int llen = i * 2 + 1;
        int rlen = len - llen - 1;

        info_st *ret_l = helper(sid, llen);
        info_st *ret_r = helper(id + 1, rlen);

        if(symb == '&')
        {
            ret.ocnt += ret_l->ocnt * ret_r->ocnt;
            ret.zcnt += ret_l->ocnt * ret_r->zcnt + ret_l->zcnt * ret_r->ocnt + ret_l->zcnt * ret_r->zcnt;
        }
        else if(symb == '|')
        {
            ret.ocnt += ret_l->ocnt * ret_r->ocnt + ret_l->ocnt * ret_r->zcnt + ret_l->zcnt * ret_r->ocnt;
            ret.zcnt += ret_l->zcnt * ret_r->zcnt;
        }
        else if(symb == '^')
        {
            ret.ocnt += ret_l->ocnt * ret_r->zcnt + ret_l->zcnt * ret_r->ocnt;
            ret.zcnt += ret_l->ocnt * ret_r->ocnt + ret_l->zcnt * ret_r->zcnt;
        }
    }

    memo[sid][len].valid = true;
    memo[sid][len].ocnt = ret.ocnt;
    memo[sid][len].zcnt = ret.zcnt;

    return &memo[sid][len];
}

//【算法思路】DFS+memo。遍历算式的所有可能，最终将得到为1的方法和为0的方法个数，进行dfs遍历
// memo[i][j]表示，字串[i, j]表示的字串，有多少种可能结果
int countEval(char* s, int result){
    ss = s;
    slen = strlen(s);

    if(slen == 0)
    {
        return 0;
    }
    else if(slen == 1)
    {
        return s[0] == result + '0'? 1 : 0;
    }

    for(int i = 0; i <= slen; i++)
    {
        for(int j = 0; j <= slen; j++)
        {
            memo[i][j].valid = false;
        }
    }

    info_st *ret = helper(0, slen);

    return (result == 1)? ret->ocnt : ret->zcnt;
}
```