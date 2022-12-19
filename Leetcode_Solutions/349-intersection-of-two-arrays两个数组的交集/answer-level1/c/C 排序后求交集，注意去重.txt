![image.png](https://pic.leetcode-cn.com/20aca531467e8644227568f79ae8cf3f3213a19e346bb3e1bd76e96ba56677bd-image.png)

```c
int cmp(void *lhsPtr, void *rhsPtr) {
    return (*(int*)lhsPtr > *(int*)rhsPtr) - 
           (*(int*)lhsPtr < *(int*)rhsPtr);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (!nums1 || !nums2) {
        *returnSize = 0;
        return NULL;
    }
    int *ans = (int *) malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int count = 0;
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    for (int i = 0, j = 0; i < nums1Size && j < nums2Size; ) {
        if (nums1[i] < nums2[j])
            ++i;
        else if (nums1[i] > nums2[j])
            ++j;
        else {
            ans[count++] = nums1[i];
            ++i;
            ++j;
            if (count > 1 && ans[count-1] == ans[count-2])
                --count;
        }
    }
    ans = (int *)realloc(ans, count * sizeof(int));
    *returnSize = count;
    return ans;
}
```
