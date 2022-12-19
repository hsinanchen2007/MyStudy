列出所有组合，然后自定义快排
```
int comp (const void *a, const void *b)
{
    int *ap = *(int **)a;
    int *bp = *(int **)b;
    if ((ap[0] + ap[1]) == (bp[0] + bp[1])) {
        return ap[0] - bp[0];
    }
    return (ap[0] + ap[1]) - (bp[0] + bp[1]);
}
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    int **ret;
    int rowsize = nums1Size * nums2Size;
    int idx = 0;
    ret = (int **)malloc(sizeof(int *) * rowsize);
    for (int i = 0; i < rowsize; i++) {
        ret[i] = (int *)malloc(sizeof(int) * 2);
    }
    if (nums1Size == 0 || nums2Size == 0) {
        * returnSize = 0;
        return ret;
    }
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            ret[idx][0] = nums1[i];
            ret[idx++][1] = nums2[j];
        }
    }
    qsort(ret, rowsize, sizeof(int) * 2, comp);

    if (k > rowsize) {
        * returnSize = rowsize;
    } else {
        * returnSize = k;
    }
    * returnColumnSizes = (int *)malloc(sizeof(int *) * (* returnSize));
    for (int i = 0; i < * returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return ret;
}
```
