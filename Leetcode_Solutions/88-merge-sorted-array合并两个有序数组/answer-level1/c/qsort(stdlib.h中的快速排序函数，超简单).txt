int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; //由小到大排序
    //return *(int *)b - *(int *)a; 由大到小排序
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i;
    for(i = 0; i < n; i++){
        nums1[i + m] = nums2[i];
    }
    qsort(nums1, n + m, sizeof(nums1[0]), cmp);
}