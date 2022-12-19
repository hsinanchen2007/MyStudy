### 解题思路

1.构建字典树

2.使用双指针遍历处理语句。右指针找到单词尾部，左指针逐字符查字典树

### 代码

```c
#define INFO_SIZE   100000

typedef struct _info_st
{
    int val;
    struct _info_st *nxt[26];
}info_st;

// 【算法思路】字典树 + 双指针。构建字典树，然后使用双指针遍历sentence
char * replaceWords(char ** dict, int dictSize, char * sentence){
    info_st * pool = (info_st *)calloc(INFO_SIZE, sizeof(info_st));
    int psize = 0;

    info_st *root = &pool[psize++];

    for(int i = 0; i < dictSize; i++)
    {
        int tlen = strlen(dict[i]);

        info_st *cur = root;
        for(int j = 0; j < tlen; j++)
        {
            int nid = dict[i][j] - 'a';
            if(cur->nxt[nid] == NULL)
            {
                cur->nxt[nid] = &pool[psize++];
            }

            cur = cur->nxt[nid];
        }

        cur->val++;
    }

    int slen = strlen(sentence);

    char * res = (char *)calloc(slen + 1, sizeof(char));
    int rsize = 0;

    // 双指针遍历生成结果rr找到右边的空格，ll处理数据
    int ll = 0, rr = 0;

    while(rr < slen)
    {
        if(sentence[rr] != ' ')
        {
            rr++;
            continue;
        }

        info_st *cur = root;
        for(int i = ll; i < rr; i++)
        {
            if(cur != NULL)
            {
                if(cur->val > 0)
                {
                    break;
                }

                int nid = sentence[i] - 'a';
                cur = cur->nxt[nid];
            }

            res[rsize++] = sentence[i];
        }

        // 空格赋值
        res[rsize++] = sentence[rr++];
        ll = rr;
    }

    //处理最后一个单词
    info_st *cur = root;
    for(int i = ll; i < rr; i++)
    {
        if(cur != NULL)
        {
            if(cur->val > 0)
            {
                break;
            }

            int nid = sentence[i] - 'a';
            cur = cur->nxt[nid];
        }

        res[rsize++] = sentence[i];
    }

    res[rsize++] = '\0';

    return res;
}
```