### 解题思路
方法一：倒序加1
1,注意加1之后超过10特殊处理即可
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//方法一：倒序加1
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int     i           = 0;
    int     iTmp        = 1;
    int*    pRet        = NULL;

    if ((NULL == digits) || (0 == digitsSize))
    {
        *returnSize = 0;
        return pRet;
    }

    pRet = (int*)malloc(sizeof(int) * (digitsSize + 1));
    memset(pRet, 0x00, sizeof(int) * (digitsSize + 1));

    for (i = digitsSize; i > 0; i--)
    { 
        pRet[i] = (digits[i - 1] + iTmp) % 10;
        iTmp = (digits[i - 1] + iTmp) / 10;
    }
    pRet[0] = iTmp;

    if (pRet[0] == 0)
    {
        *returnSize = digitsSize;
        return &pRet[1];
    }
    else
    {
        *returnSize = digitsSize + 1;
        return &pRet[0];
    }
}
```