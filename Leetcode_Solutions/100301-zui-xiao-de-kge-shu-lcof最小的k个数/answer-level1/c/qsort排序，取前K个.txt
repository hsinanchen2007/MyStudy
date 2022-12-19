int Cmp(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if (arr == NULL) {
    *returnSize = 0;
    return NULL;
    }
    qsort(arr, arrSize, sizeof(int), Cmp);
    *returnSize = k;
    return arr;
}