### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int isDividingNumber(int n)
{
    int temp = n, a;
    while (temp)
    {
        a = temp % 10;
        if (a == 0 || n % a != 0)
            return false;
        temp /= 10;
    }
    return 1;
}

int* selfDividingNumbers(int left, int right, int* returnSize)
{
    int *res = (int*)malloc(sizeof(int) * (right - left));
    *returnSize = 0;
    int i;
    for (i = left; i <= right; i++)
        if (isDividingNumber(i))
            res[(*returnSize)++] = i;
    return res;
}
```