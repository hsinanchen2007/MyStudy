### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int flag = 1;
    int sum,i;
    int* p = (int*)malloc(sizeof(int) * (digitsSize + 1));
    if (p == NULL)
        return NULL;

    for (i = digitsSize - 1; i >= 0; i--)
    {
        sum = digits[i] + flag;
        if (sum >= 10)
        {
            sum = sum - 10;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        p[i + 1] = sum;
    }
    if (flag == 1)
    {
        *returnSize = digitsSize + 1;
        p[0] = 1;
        return p;
    }
    for (i = 0; i < digitsSize; i++)
        p[i] = p[i + 1];
    *returnSize = digitsSize;
    return p;
}
```