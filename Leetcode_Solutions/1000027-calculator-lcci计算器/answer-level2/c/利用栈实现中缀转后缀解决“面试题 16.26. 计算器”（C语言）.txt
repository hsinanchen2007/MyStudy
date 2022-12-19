### 解题思路

经典的计算器类问题，典型解法是**中缀转后缀**，然后**计算后缀表达式**，该方法**通杀所有计算器类问题**。

对于C语言开发者，本题的最大难度，是字符串的处理，在解的时候使用了状态机的思路。


![image.png](https://pic.leetcode-cn.com/5f51957d50f43bc7e84b98d80ca228fe76404f9b372393748d53901ce917056d-image.png)


### 代码

```c

typedef struct _info_st
{
    bool is_num;
    int num;
    char symb;
}info_st;

//【算法思路】栈 +　状态机。典型的中缀表达式转后缀表达式，关键要素是：数组+符号栈->后缀；计算栈得结果。
int calculate(char* s){
    int slen = strlen(s);

    if(slen == 0)
    {
        return 0;
    }

    info_st *info = calloc(slen, sizeof(info_st));
    int isize = 0;

    //信息解析
    int sid = 0;
    
    int stat = 0;   //状态为１，解析数字

    char tmpn[16];
    int tid = 0;

    s[slen] = ' ';//处理尾部数字的技巧
    while(sid <= slen)
    {
        if(s[sid] == ' ')
        {
            if(stat == 1)
            {
                stat = 0;
                //完成取数
                tmpn[tid] = '\0';

                info[isize].is_num = true;
                info[isize].num = atoi(tmpn);
                isize++;

                tid = 0;
            }

            sid++;
        }
        else if(s[sid] >= '0' && s[sid] <= '9')
        {
            stat = 1;
            tmpn[tid++] = s[sid];

            sid++;
        }
        else
        {
            if(stat == 1)
            {
                stat = 0;
                //完成取数
                tmpn[tid] = '\0';

                info[isize].is_num = true;
                info[isize].num = atoi(tmpn);
                isize++;

                tid = 0;
            }

            info[isize].is_num = false;
            info[isize].symb = s[sid];
            isize++;

            sid++;
        }
    }
    s[slen] = '\0';
/*
    for(int i = 0; i < isize; i++)
    {
        if(info[i].is_num == true)
        {
            printf("%d   ", info[i].num);
        }
        else
        {
            printf("%c   ", info[i].symb);
        }
    }
    printf("\n");
*/
    //中缀转后缀
    info_st *bak = calloc(isize, sizeof(info_st));
    int bsize = 0;
    info_st *stk = calloc(isize, sizeof(info_st));
    int ssize = 0;

    for(int i = 0; i < isize; i++)
    {
        if(info[i].is_num == true)
        {
            bak[bsize++] = info[i];
        }
        else
        {
            if(info[i].symb == '+' || info[i].symb == '-')
            {
                //将栈弹空
                while(ssize > 0)
                {
                    bak[bsize++] = stk[--ssize];
                }

                stk[ssize++] = info[i];

                continue;
            }
            
            //此时info只可能是*，/
            bool proc = false;

            while(ssize > 0)
            {
                if(stk[ssize - 1].symb == '*' || stk[ssize - 1].symb == '/')
                {
                    bak[bsize++] = stk[--ssize];
                }
                else
                {
                    stk[ssize++] = info[i];
                    proc = true;
                    break;
                }
            }

            if(proc == false)
            {
                stk[ssize++] = info[i];
            }
        }
    }

    //将栈弹空
    while(ssize > 0)
    {
        bak[bsize++] = stk[--ssize];
    }

    //计算后缀表达式
    for(int i = 0; i < bsize; i++)
    {
        if(bak[i].is_num == true)
        {
            stk[ssize++] = bak[i];
            continue;
        }

        int b = stk[--ssize].num;
        int a = stk[--ssize].num;

        //printf("a = %d, b = %d\n", a, b);

        if(bak[i].symb == '+')
        {
            stk[ssize++].num = a + b;
        }
        else if(bak[i].symb == '-')
        {
            stk[ssize++].num = a - b;
        }
        else if(bak[i].symb == '*')
        {
            stk[ssize++].num = a * b;
        }
        else
        {
            stk[ssize++].num = a / b;
        }
    }

    return stk[0].num;
}
```