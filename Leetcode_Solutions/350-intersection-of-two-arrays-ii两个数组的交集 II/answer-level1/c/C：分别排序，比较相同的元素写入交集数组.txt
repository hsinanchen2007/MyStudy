思路：
qsort分别排序，比较不相等时循环标记后移，
比较相等的元素加入交集

```
int compare(const void* a, const void* b){
    return *(int*)a > *(int*)b;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);   
    
    int i = 0;
    int j = 0;
    *returnSize = 0;
    int *result = malloc(sizeof(int)*nums2Size);
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j])
            i++;
        else if(nums1[i] > nums2[j])
            j++;
        else{
            result[(*returnSize)++] = nums1[i];
            i++;
            j++;
        }
    }
    return result;
}
```
