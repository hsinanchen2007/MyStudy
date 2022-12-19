思路：（只做能用于通过机试且直观简短的解法，不考虑题目要求的复杂度）
将两个有序数组直接拼接在新数组里，qsort后按奇偶数找到中位数，下标处理要注意
这里拼接可以加判断选择后合并的话可以不用qsort，但判断选择的合并要注意两个数组长度不确定谁大谁小
```
int compare(void const *a, void const *b){
    return *(int*)a - *(int*)b;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int len = nums1Size + nums2Size;
    int combine[len];
    memset(combine, 0, sizeof(combine));
    int i, j;
    for (i = 0; i < nums1Size; i++) {
        combine[i] = nums1[i];
    }
    for (j = 0; j < nums2Size; j++) {
        combine[nums1Size + j] = nums2[j];  
    }
    qsort(combine, len, sizeof(int), compare);
    if (len % 2 == 1) {
        return (double)combine[(len - 1) / 2];
    } else {
        return (double)((combine[(len - 1)/ 2] + combine[(len - 1)/ 2 + 1]) / 2.0);
    }
}
```
