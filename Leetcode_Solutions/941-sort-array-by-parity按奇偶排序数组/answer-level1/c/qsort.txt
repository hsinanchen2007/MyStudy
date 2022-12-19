### 解题思路
此处撰写解题思路

qsort

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int MyCompare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if ((x & 1) == 0) {
        return -1;
    }
    if ((y & 1) == 0) {
        return 1;
    }
    return x - y;
}

int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    if (!A || ASize < 1) {
        *returnSize = 0;
        return A;
    }

    qsort(A, ASize, sizeof(int), MyCompare);
    *returnSize = ASize;
    return A;
}
```