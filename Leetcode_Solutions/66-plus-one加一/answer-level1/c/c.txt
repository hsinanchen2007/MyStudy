### 解题思路
此处撰写解题思路
1、主要需要头部预留一位位置，给进位留下空间；

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int add_flag = 1;
    int i = 0;
    int *results = (int *)malloc(sizeof(int) * (digitsSize + 1));

    //移动一位，给进位留下空间
    results++;

    for(i = (digitsSize - 1); i >= 0; i--)
    {
        results[i] = digits[i] + add_flag;

        if(results[i] == 10)
        {
            results[i] = 0;
            add_flag = 1;
        }
        else
        {
            add_flag = 0;
        }
    }

    if(results[0] == 0)
    {
        results[-1] = 1;
        results--;
        *returnSize = digitsSize + 1;
    }
    else
    {
        *returnSize = digitsSize;
    }

    return results;
}
```