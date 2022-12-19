### 解题思路
1.找出第i个最大值位置pos
   如果第i个最大值已经在目标位置，重复1，找下一个次大值
2.按pos煎饼翻一次
3.按第i个值得目标位置Asize - i - 1再翻一次
4.重复1，找下一个次大值

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int get_max(int *A, int size)
{
    int max = A[0];
    int pos = 0;

    for (int i = 1; i < size; i++)
        if (A[i] > max) {
            max = A[i];
            pos = i;
        }

    return pos;
}

void reset(int *A, int pos)
{
    if (pos == 0)
        return;

    int tmp[pos + 1];

    for (int i = 0; i <= pos; i++)
        tmp[i] = A[pos - i];
    for (int i = 0; i <= pos; i++)
        A[i] = tmp[i];
}

int* pancakeSort(int* A, int ASize, int* returnSize)
{
    if (!returnSize)
        return NULL;
    if (!A || ASize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    int pos = 0;
    int index = 0;
    int *ret = (int *)calloc(2 * ASize, sizeof(int));

    for (int i = 0; i < ASize - 1; i++) {
        pos = get_max(A, ASize - i);
        if (pos == ASize - 1 - i)
            continue;
        reset(A, pos);
        reset(A, ASize - 1 - i);
        if (pos != 0)
            ret[index++] = pos + 1;
        ret[index++] = ASize - i;
    }

    *returnSize = index;
    return ret;
}
```