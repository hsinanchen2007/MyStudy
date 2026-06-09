### 解题思路
对于C语言，本题非常考验字符串相关的编程能力。

整个盖章过程，可以看做若干个最后一次的盖章，覆盖了左侧和右侧的多个章，最后剩余一些两次完整章延伸区域的交接位置，单独进行处理.

图示如下：

[1[1[ 1 ]1] 3 [2[2[ 2 ]2]...

其中1表示第一次完全匹配后进行的左右延伸操作，2表示第二次完全匹配进行的左右延伸操作，3为剩余部分

解题思路非常清晰：
1.找到完全匹配的字串，将其置为'?'

2.向左边找到部分匹配的字串，置为'?',不断延伸

3.向右边找到部分匹配的字串，置为'?',不断延伸

4.重复步骤1，直到无完全匹配项

5.处理剩余字符

编程时注意下标的关系和异常情况的判断，非常容易出错。

![image.png](https://pic.leetcode-cn.com/ef105901af78ce836ef8fd0967dfa282a4a3555870bdb6294b77b988b3035895-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define RES_SIZE    1000
#define TMP_SIZE    500

//s0为target:abc????
bool my_cmp(char *s0, char *s1, int len)
{
    bool same = true;

    for(int i = 0; i < len; i++)
    {
        if(s0[i] != s1[i] && s0[i] != '?')
        {
            same = false;
            break;
        }
    }

    return same;
}

int res[RES_SIZE];
int rres[RES_SIZE];

char tmp_str[TMP_SIZE];

//【算法思路】贪心+字符串匹配。字符串的模糊匹配。
//1.首先使用strstr找到完全匹配项
//2.然后使用左侧匹配函数找到所有左侧匹配项
//3.再使用右侧匹配函数找到所有右侧匹配点
//4.返回步骤1，如果找不到进入下一步
//5.剩余项和stamp进行中间匹配
int* movesToStamp(char * stamp, char * target, int* returnSize){
    int slen = strlen(stamp);
    int tlen = strlen(target);

    int rsize = 0;

    //记录已经处理过的字符
    int total = 0;

    char *p = strstr(target, stamp);

    while(p != NULL)
    {
        int pid = (p - target) / sizeof(char);

        //printf("pid = %d\n", pid);

        res[rsize++] = pid;

        //刷新‘？’
        for(int i = pid; i < pid + slen; i++)
        {
            target[i] = '?';
            total++;
        }

        //printf("target: %s\n", target);

        //处理左边字串
        int rr = pid;
        int ll = rr - tlen + 1;
        ll = ll > 0? ll : 0;

        bool find_left = true;
        //printf("---->find left\n");
        while(find_left)
        {
            //printf("ll = %d, rr = %d\n", ll, rr);
            find_left = false;

            //遍历ll到rr，找到可能的最长匹配
            for(int i = ll; i <= rr; i++)
            {
                if(target[i] == '?')
                {
                    continue;
                }

                if(target[i] == stamp[0])
                {
                    int start  = i;
                    //开始比较
                    if(my_cmp(&target[start], stamp, slen) == true)
                    {
                        find_left = true;

                        res[rsize++] = i;

                        //刷新为‘？’,上次已经刷新都按rr
                        for(int j = start; j < rr; j++)
                        {
                            if(target[j] == '?')
                            {
                                continue;
                            }
                            target[j] = '?';
                            total++;
                        }
                        //printf("target: %s\n", target);

                        //刷新左边界
                        rr = start;
                        ll = rr - slen + 1;
                        ll = ll > 0? ll : 0;

                        break;
                    }
                }
            }
        }

        //处理右边字串
        ll = pid + slen - 1;
        rr = ll + slen - 1;
        rr = rr < tlen? rr : tlen - 1;

        bool find_right = true;
        //printf("---->find right\n");
        while(find_right)
        {
            //printf("ll = %d, rr = %d\n", ll, rr);
            find_right = false;

            //从后向前查找
            for(int i = rr; i >= ll; i--)
            {
                if(target[i] == '?')
                {
                    continue;
                }

                if(target[i] == stamp[slen - 1])
                {
                    int start = i - slen + 1;
                    //开始比较
                    if(my_cmp(&target[start], stamp, slen) == true)
                    {
                        find_right = true;

                        res[rsize++] = start;

                        //刷新为‘？’
                        for(int j = i; j >= start; j--)
                        {
                            if(target[j] == '?')
                            {
                                continue;
                            }
                            target[j] = '?';
                            total++;
                        }
                        //printf("target: %s\n", target);

                        //刷新右边界
                        ll = i;     //上次比较，i为右端点
                        rr = ll + slen - 1;
                        rr = rr < tlen? rr : tlen - 1;

                        break;
                    }
                }
            }
        }

        //找到下一个完全匹配的字符串
        p = strstr(target, stamp);
    }

    //双指针处理剩余字串
    int ll = 0, rr = 0;
    //printf("---->find remain\n");
    while(rr < tlen)
    {
        if(target[rr] == '?')
        {
            rr++;
            continue;
        }

        ll = rr;

        bool find = false;
        for(int i = ll; i < tlen; i++)
        {
            if(target[i] == '?')
            {
                find = true;
                rr = i;
                break;
            }
        }
        if(find == false)
        {
            goto FAIL;
        }

        //printf("ll = %d, rr = %d\n", ll, rr);

        //[ll, rr)为剩余字串，反向查找起点
        int tmp_len = rr - ll;
        strncpy(tmp_str, &target[ll], tmp_len);
        tmp_str[tmp_len] = '\0';

        p = strstr(stamp, tmp_str);

        //printf("stamp:%s, tmp_str:%s\n", stamp, tmp_str);

        if(p == NULL)
        {
            goto FAIL;
        }

        int pid = (p - stamp) / sizeof(char);

        int start = ll - pid;

        res[rsize++] = start;

        for(int i = start; i < start + slen; i++)
        {
            if(target[i] == '?')
            {
                continue;
            }

            target[i] = '?';
            total++;
        }

        //printf("target: %s\n", target);
    }

    int rrsize = 0;
    if(total == tlen)
    {
        //将结果反向
        for(int i = 0; i < rsize; i++)
        {
            rres[rrsize++] = res[rsize - i - 1];
        }

        *returnSize = rrsize;
        return rres;
    }

FAIL:
    *returnSize = 0;
    return NULL;
}
```