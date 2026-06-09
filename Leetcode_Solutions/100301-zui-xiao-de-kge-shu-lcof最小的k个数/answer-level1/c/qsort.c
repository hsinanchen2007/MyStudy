算作弊吗
```
int IntegerCmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr, arrSize, sizeof(int), IntegerCmp);
    *returnSize = k;
    return arr;
}
```
