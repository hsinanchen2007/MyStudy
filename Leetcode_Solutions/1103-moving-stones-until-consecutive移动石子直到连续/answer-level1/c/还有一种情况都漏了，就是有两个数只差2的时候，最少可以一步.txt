### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int* returnSize){
    *returnSize =2;
    int *returnsize;
    returnsize = (int *)malloc(sizeof(int)*2);
    int m;
    if(a>b)
    {
        m=a;
        a=b;
        b=m;
    }
    if(b>c)
    {
        m=b;
        b=c;
        c=m;
    }
    if(a>b)
    {
        m=a;
        a=b;
        b=m;
    }
    if((c-b == 1 )&& (b-a == 1))
    {
        returnsize[0]=0;
        returnsize[1]=0;
    }else if((b-a == 1) || (c-b == 1))
    {
        returnsize[0]=1;
        returnsize[1]=c-a-2;
    }else if((c-b==2)||(b-a==2))
    {
        returnsize[0]=1;
        returnsize[1]=c-a-2;
    }else{
        returnsize[0]=2;
        returnsize[1]=c-a-2;
    }
    return returnsize;
}
```