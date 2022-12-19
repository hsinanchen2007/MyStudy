### 解题思路
根据题目特点，构造栈结构，然后将K在栈结构中进行换算得到结果

栈元素中保存：上一级字符长度,本级倍数,本级补充的字符数

然后将K逐级换算，对应到某一级字符串获得结果。

### 代码

```c
#define STK_SIZE    1000
typedef long long ll_t;
typedef struct _info_st
{
    ll_t sum;
    ll_t mul;
    ll_t rem;
}info_st;

info_st stk[STK_SIZE];

char ss[100][100];

void my_str_cpy(char *d, char *s, int len)
{
    for(int i = 0; i < len; i++)
    {
        d[i] = s[i];
    }

    d[len] = '\0';
}

char res[2] ={0};

// 【算法思路】栈。根据计算特点为分层结构，使用栈表示，栈元素表示：此层总数，上层的倍数，余数
// 判断k属于余数，则在余数字串中查找；
// 判断k属于倍数，则将K对倍数求余，转化到上一层求解。
// 逐层递推得到结果
char * decodeAtIndex(char * S, int K){
    int slen = strlen(S);
    //双指针将S拆解为字符串数组，作为各层的余数字串，同时获得栈结构
    int ll = 0, rr = 0;

    int level = 0;
    ll_t mul = 0;
    ll_t last_sum = 0;
    while(rr < slen)
    {
        if(S[rr] >= 'a' && S[rr] <= 'z')
        {
            rr++;
            continue;
        }

        my_str_cpy(ss[level], &S[ll], rr - ll);

        stk[level].rem = rr - ll;
        stk[level].mul = mul;
        stk[level].sum = last_sum;

        //记录本层长度，供下层使用
        last_sum = last_sum * mul + rr - ll;
        mul = S[rr] - '0';

        level++;
        rr++;
        ll = rr;
    }

    //处理最后一层
    my_str_cpy(ss[level], &S[ll], rr - ll);

    stk[level].rem = rr - ll;
    stk[level].mul = mul;
    stk[level].sum = last_sum;

    level++;
/*
    for(int i = 0; i < level; i++)
    {
        printf("[%ld, %ld, %ld]   ", stk[i].sum, stk[i].mul, stk[i].rem);
    }
    printf("\n");

    for(int i = 0; i < level; i++)
    {
        printf("<%d>%s ", i, ss[i]);
    }
    printf("\n");
*/
    //根据栈结构进行推算
    while(level > 0)
    {
        //printf("level = %d, K = %d\n", level, K);

        if(stk[level - 1].rem > 0 && stk[level - 1].sum * stk[level - 1].mul < K)
        {
            K -= stk[level - 1].sum * stk[level - 1].mul;

            //printf("K = %d\n", K);

            res[0] = ss[level - 1][K - 1];

            return res;
        }

        K = (K > stk[level - 1].sum * stk[level - 1].mul)? (K - stk[level - 1].rem - 1) % stk[level - 1].sum + 1 : (K - 1) % stk[level - 1].sum + 1;
        level--;
    }

    return "\0";
}
```