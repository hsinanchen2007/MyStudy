### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmp(const void *p, const void *q)
{
	return *(int *)p - *(int *)q;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int i, j;
    int count = 0;
    int tmp;
    for (i = 0; i < arr2Size; i++) {
        for (j = count; j < arr1Size; j++) {
            if (arr1[j] == arr2[i]) {
                tmp = arr1[j];
                arr1[j] = arr1[count];
                arr1[count] = tmp;
                count++;
            }
        }
    }
    if (count < arr1Size)
    {
        qsort(&arr1[count], arr1Size - count, sizeof(int), cmp);
    }
    *returnSize = arr1Size;
    return arr1;
}
```