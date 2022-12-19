### 解题思路
1. 前后双指针

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *out = NULL;
    int i = 0, j = numbersSize - 1, sum;

    while (i <= j)
    {
        sum = numbers[i] + numbers[j];
        if (sum > target) j--;
        else if (sum < target) i++;
        else
        {
            out = (int *)malloc(sizeof(int) * 2);
            *out = i + 1;
            *(out + 1) = j + 1;
            *returnSize = 2;
            return out;
        }
    }

    *returnSize = 0;
    return out;
}
 /* 双循环，但是用时太长
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *out = NULL;
    int i, j;

    for (i = 0; i < numbersSize; i++)
    {
        for (j = i + 1; j < numbersSize; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                out = (int *)malloc(sizeof(int) * 2);
                *out = i + 1;
                *(out + 1) = j + 1;
                *returnSize = 2;
                return out;
            }
        }
    }

    *returnSize = 0;
    return out;
}
*/
```