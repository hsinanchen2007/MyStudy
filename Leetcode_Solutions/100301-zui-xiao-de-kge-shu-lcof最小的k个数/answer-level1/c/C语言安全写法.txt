

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comparator(const void* a, const void* b);

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){

    qsort(arr, arrSize, sizeof(int), comparator);
    int i = 0;
    int index = k < arrSize ? k : arrSize;
    int * ret = (int*)malloc(sizeof(int) * index);
    memset(ret, 0, sizeof(int) * index);
    for (i = 0; i < index; i++) {
        ret[i] = arr[i];
    }
    *returnSize = index;
    return ret;
}

int comparator(const void* a, const void* b) 
{
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}
```
