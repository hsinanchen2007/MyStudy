```
#define MAX_SIZE (2010)

int g_nums[MAX_SIZE];

int CmpFunc(const void *a, const void *b)
{
    return (*(int*)b) - (*(int*)a);
}

bool uniqueOccurrences(int* arr, int arrSize)
{
    int i;
    int j;
    for (i = 0; i < MAX_SIZE; i++) {
        g_nums[i] = 0;
    }
    for (i = 0; i < arrSize; i++) {
        g_nums[arr[i] + 1000]++;
    }
    qsort(g_nums, MAX_SIZE, sizeof(int), CmpFunc);

    for (i = 0; i < MAX_SIZE - 1; i++) {
        if (g_nums[i] == 0) {
            return true;
        }
        if (g_nums[i] == g_nums[i + 1]) {
            return false;
        }
    }
    return true;
}
```
