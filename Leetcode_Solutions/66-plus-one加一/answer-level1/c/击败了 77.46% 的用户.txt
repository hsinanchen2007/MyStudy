### 解题思路
1. 从最好一个数字开始，逢九进位，遇到其他的则退出循环
2. 然后检查最高位是否为0，如果为0再将返回数组扩展一位并置1

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i, flag = 0;
    int *arr = NULL;

    for (i = digitsSize - 1; i >= 0; i--)
    {
        if (flag == 1 || i == digitsSize - 1)
        {
            if (digits[i] == 9) 
            {
                digits[i] = 0;
                flag = 1;
            }
            else
            {
                digits[i]++;
                flag = 0;
                break;
            }
        }
    }

    if (digits[0] == 0)
    {
        *returnSize = digitsSize + 1;
        arr = (int *)malloc(sizeof(int) * *returnSize);
        arr[0] = 1;
        memcpy(arr + 1, digits, sizeof(int) * digitsSize);
    } else
    {
        *returnSize = digitsSize;
        arr = (int *)malloc(sizeof(int) * *returnSize);
        memcpy(arr, digits, sizeof(int) * digitsSize);
    }
    return arr;
}
```