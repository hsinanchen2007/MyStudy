### 解题思路
此处撰写解题思路
直接通分求和，每次循环，转换分子分母的位置，遍历一次。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fraction(int* cont, int contSize, int* returnSize)
{
    int *ret=(int*)malloc(sizeof(int)*2);
    int i = contSize-2,temp;
    ret[1] = 1;
    ret[0] = cont[contSize-1];
    for(;i>-1;i--)
    {
        temp = ret[1];
        ret[1] = ret[0];
        ret[0] =temp;
        ret[0] = ret[0] + cont[i] * ret[1];

    }
    *returnSize = 2;
    return ret;
}
```