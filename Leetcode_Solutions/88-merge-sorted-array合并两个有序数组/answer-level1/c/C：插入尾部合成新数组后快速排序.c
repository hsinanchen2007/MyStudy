理由：
直接将数组2插入到数组1尾部，然后用库函数qsort快速排序就好
```
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = m; i < m + n; i++){
        nums1[i] = nums2[i-m];
    }
    qsort(nums1, m + n, sizeof(int), compare);
    return;
}
```