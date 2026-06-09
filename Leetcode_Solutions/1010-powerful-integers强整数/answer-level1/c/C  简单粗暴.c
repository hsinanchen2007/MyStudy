```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize){
    int i, count = 0, j, k, flag = 1;
    int * res = (int *)malloc(sizeof(int) * bound);
    int t;
    if(x == 1 && y == 1)//先判断一下
    {
        if(bound >= 2)
        {
            *returnSize = 1;
            res[0] = 2;
            return res;
        }
        else
        {
            *returnSize = 0;
            return res;
        }
    }
    if(x < y)
    {
        t = x;
        x = y;
        y = t;
    }
    for(i = 0;i <= bound;i++)
    {
        for(j = 1;j < bound;j *= x)
        {
            flag = 0;
            for(k = 1;k < bound;k *= y)
            {
                if(j + k == i)
                {
                    res[count++] = i;
                    flag = 1;
                    break;
                }
                else if(j + k > i)
                    break;
                else if(y == 1)
                    break;
            }
            if(flag == 1)
                break;
        }
    }
    *returnSize = count;
    return res;
}
```
