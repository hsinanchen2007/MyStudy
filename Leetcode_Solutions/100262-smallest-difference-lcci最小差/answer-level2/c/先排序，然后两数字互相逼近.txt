```
/*先排序，然后两数字互相逼近*/
#define ABS_NUM(a)              ((a) > 0  ? (a) : -(a))
#define MIN_NUM(a, b)           ((a) > (b) ? (b) : (a))

int cmp(const void *a, const void *b) {
    const int l = *(int *)a;
    const int r = *(int *)b;
    return l > r ? 1 : -1;
}
int smallestDifference(int* a, int aSize, int* b, int bSize){
    if (a == NULL || aSize == 0 || b == NULL || bSize == 0) {
        return 0;
    }
    qsort(a, aSize, sizeof(int), cmp);
    qsort(b, bSize, sizeof(int), cmp);
    long min = ABS_NUM((long)(a[0] - b[0]));
    int i = 0, j = 0;
    while (i < aSize && j < bSize) {
        if (a[i] > b[j]) {
            min = MIN_NUM(min, ABS_NUM((long)(a[i] - b[j])));
            j++;
        }else if (a[i] < b[j]) {
            min = MIN_NUM(min, ABS_NUM((long)(a[i] - b[j])));
            i++;
        }else {
            return 0;
        }
    }
    return min;
}
```
