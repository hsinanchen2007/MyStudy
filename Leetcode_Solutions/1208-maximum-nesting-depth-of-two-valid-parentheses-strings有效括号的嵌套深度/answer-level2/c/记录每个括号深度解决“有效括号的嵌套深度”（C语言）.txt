### 解题思路
记录最大深度，和每个括号的深度。以mid深度为限，大于mid置1，小于mid置0

（1）设置两个变量，一个记录当前深度，一个记录最大深度。
（2）遍历括号，如果为‘（’则深度增加，否则减少；
（3）深度增加是刷新最大深度
（4）根据最大深度或的mid
（5）再两次刷新获得结果

三次遍历，解决本问题。

![image.png](https://pic.leetcode-cn.com/5cb74a7d334b1f07237c016c8de3499acb17f9ea846237b8ddfc47c63ce70e61-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MMAX(a, b)      ((a) > (b)? (a) : (b))

//【算法思路】字符串。根据括号的出入栈情况，将不同深度的左右括号分别记录深度，并记录最大深度，然后取中间深度，将所有括号分为0,1两类
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int slen = strlen(seq);
    int ssize = 0;
    int *depth = (int *)calloc(slen, sizeof(int));

    int d = 0;
    int dmax = 0;

    for(int i = 0; i < slen; i++)
    {
        if(seq[i] == '(')
        {
            //当前深度增加
            d++;

            //当前深度赋值
            depth[i] = d;

            //刷新最大深度
            dmax = MMAX(dmax, d);
        }
        else
        {
            //当前深度赋值
            depth[i] = d;

            //当前深度减少
            d--;
        }
    }
/*
    for(int i = 0; i < slen; i++)
    {
        printf("<%d>%d ", i, depth[i]);
    }
    printf("\n");
*/
    int mid = dmax / 2;

    //printf("mid = %d\n", mid);

    for(int i = 0; i < slen; i++)
    {
        if(depth[i] <= mid)
        {
            depth[i] = 0;
        }
    }

    for(int i = 0; i < slen; i++)
    {
        if(depth[i] > mid)
        {
            depth[i] = 1;
        }
    }

    *returnSize = slen;
    return depth;
}

```