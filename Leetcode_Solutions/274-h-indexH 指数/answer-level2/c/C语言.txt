### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int hIndex(int* citations, int citationsSize)
{
    qsort(citations, citationsSize, sizeof(int), cmp);
    int i;
    for (i = 0; i < citationsSize; i++)
        if (citations[i] <= i)
            break;
    return i;
}
```