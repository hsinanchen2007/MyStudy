```
int cmp(const void *a, const void *b){
    return *(int*)a < *(int*)b;
}
int hIndex(int* citations, int citationsSize){
    int i;

    qsort(citations, citationsSize, sizeof(citations[0]), cmp);
    for (i = 0; i < citationsSize; i++){
        if (citations[i] <= i)
            break;
    }
    return i;
}
```
