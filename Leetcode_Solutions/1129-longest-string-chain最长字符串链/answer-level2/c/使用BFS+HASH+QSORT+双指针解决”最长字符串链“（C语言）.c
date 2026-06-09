### 解题思路
根据题意，单词与其长度+1的词构成前身关系，因此可以根据单词长度从短到长进行遍历。

在遍历比较时，使用hash表进行加速，只需要比较两个词的hash表，如果出现短词某字符数目大于对应长词字符数目，则不是前身关系。

编程难点在于，如何根据分割出单词长度增加1的两组词，这里利用了双指针的思路。

1.映射单词hash信息数组

2.对信息数组按照长度排序

3.根据双指针思路，处理字符长度+1的两组字串

![image.png](https://pic.leetcode-cn.com/504bbbdd7124a96e0a43da8322339ea00aa6ba782229936f68a0d8e5ed2087ca-image.png)




### 代码

```c
#define MMAX(a, b)        ((a) > (b)? (a) : (b))

typedef struct _info_st
{
    int id;
    int wlen;
    int hash[26];
    int max;
}info_st;

int gmax;

int compare(const void *a, const void *b)
{
    return (*(info_st *)a).wlen - (*(info_st *)b).wlen;
}

// 将wll字串转换为hash表
void info_init(info_st *ll, char *wll, int id)
{
    ll->id = id;
    ll->wlen = strlen(wll);

    for(int i = 0; i < ll->wlen; i++)
    {
        int hid =wll[i] - 'a';
        ll->hash[hid]++;
    }
}

// 更新链接最大长度
void info_proc(info_st *ss, info_st *ll)
{
    int llen = ll->wlen;
    int slen = ss->wlen;

    int flag = true;
    for(int i = 0; i < 26; i++)
    {
        if(ss->hash[i] > ll->hash[i])
        {
            flag = false;
            break;
        }
    }

    if(flag == true)
    {
        ll->max = MMAX(ll->max, ss->max + 1);
        gmax = MMAX(gmax, ll->max);
    }
}

// 【算法思路】动态规划。按照题意，逐字符增加单词长度，因此单词按长度排序，记录单词长度和链长，从短到长处理
int longestStrChain(char ** words, int wordsSize){
    gmax = 0;

    info_st *info = (info_st *)calloc(wordsSize, sizeof(info_st));

    for(int i = 0; i < wordsSize; i++)
    {
        info_init(&info[i], words[i], i);
    }

    qsort(info, wordsSize, sizeof(info_st), compare);
/*
    for(int i = 0; i < wordsSize; i++)
    {
        printf("[id = %d, wlen = %d]   ", info[i].id, info[i].wlen);
    }
    printf("\n");
*/
    int base_len = info[0].wlen;
    int nxt_base_len;
    int lll = 0, llr = 0, rrl = 0, rrr = 0;

    // 初始化第一等级长度
    for(int i = 0; i < wordsSize; i++)
    {
        if(info[i].wlen != base_len)
        {
            break;
        }

        llr = i;
    }

    rrl = llr + 1;
    rrr = rrl;
    
    while(rrr < wordsSize)
    {
        nxt_base_len = info[rrr].wlen;
        //printf("base_len = %d, nxt_base_len = %d\n", base_len, nxt_base_len);

        // 跨越两个字符，则需要重新设置起始阶段
        if(nxt_base_len != base_len + 1)
        {
            base_len = nxt_base_len;

            lll = rrl;
            llr = lll;
            for(int i = lll; i < wordsSize; i++)
            {
                if(info[i].wlen != base_len)
                {
                    break;
                }

                llr = i;
            }

            rrl = llr + 1;
            rrr = rrl;
            continue;
        }

        // 设置下一阶段起止
        for(int i = rrl; i < wordsSize; i++)
        {
            if(info[i].wlen != nxt_base_len)
            {
                break;
            }

            rrr = i;
        }

        //printf("lll = %d, llr = %d, rrl = %d, rrr = %d\n", lll, llr, rrl, rrr);

        //开始判断
        for(int i = lll; i <= llr; i++)
        {
            for(int j = rrl; j <= rrr; j++)
            {
                info_proc(&info[i], &info[j]);
            }
        }

        // 进行下一长度的处理
        base_len = nxt_base_len;

        lll = rrl;
        llr = rrr;
        rrl = llr + 1;
        rrr = rrl;
        //printf("lll = %d, llr = %d, rrl = %d, rrr = %d\n", lll, llr, rrl, rrr);
        //printf("------------\n");
    }

    return gmax + 1;
}
```