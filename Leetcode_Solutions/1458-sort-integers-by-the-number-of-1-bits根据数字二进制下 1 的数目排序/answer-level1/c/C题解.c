```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int bits_count(int a) {
    int count = 0;
    while (a) {
        count++;
        a &= (a - 1);
    }

    return count;
}

int cmpfunc(const void* a, const void *b) {
    int c = *(int *)a, d = *(int *)b;

    int countc = bits_count(c);
    int countd = bits_count(d);

    return countc != countd ? countc - countd : c - d;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), cmpfunc);
    return arr;
}
```
