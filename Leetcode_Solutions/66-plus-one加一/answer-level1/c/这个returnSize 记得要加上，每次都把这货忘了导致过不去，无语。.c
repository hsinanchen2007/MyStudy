### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for(int i = digitsSize - 1; i >= 0; --i)
    {
        if(digits[i] == 9)
            digits[i] = 0;        //是 9 就置零
        else
        {
            digits[i] += 1;      //不是零就加 1 并退出循环
            *returnSize = digitsSize;
            return digits;
        }

    }
    
    int* arr = (int*) malloc ((digitsSize + 1) * sizeof (int));   //到这说明全是9，重开空间就行，realloc 和 malloc 都行
    arr[0] = 1;
    for(int i = 1;i < (digitsSize + 1);i++)
        arr[i] = 0;   
    *returnSize = digitsSize + 1;
    return arr;

}
```