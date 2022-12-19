```
int cmpfunc(const void *a, const void *b) {
    if (*(int *)a < *(int *)b) {
        return -1;
    }else if (*(int *)a == *(int *)b) {
        return 0;
    }
    return 1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int size = nums1Size < nums2Size ? nums1Size : nums2Size;
    int i;
    int *res = (int *)malloc(sizeof(int) * size);

    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);

    int j = 0;
    int count = 0;
    int index1 = 0, index2 = 0;
    int num1 = 0, num2 = 0;
    while (index1 < nums1Size && index2 < nums2Size) {
        num1 = nums1[index1];
        num2 = nums2[index2];
        if (num1 == num2) {
            res[j++] = num1;
            index1++;
            index2++;
        } else if (num1 < num2) {
            index1++;
        } else {
            index2++;
        }
    }

    *returnSize = j;
    
    return res;
}
```
