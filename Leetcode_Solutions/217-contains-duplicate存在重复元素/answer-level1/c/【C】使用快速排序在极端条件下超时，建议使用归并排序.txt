```

void mergeTwoNums(int* nums1, int len1, int* nums2, int len2) {    
    int *result = (int *)malloc(sizeof(int) * (len1 + len2));
    if (result == NULL) {
        return NULL;
    }
    
    int mergedIndex = 0;
    int i = 0;
    int j = 0;
    for(;i < len1 && j < len2; mergedIndex++) {
        if (nums1[i] < nums2[j]) {
            result[mergedIndex] = nums1[i];
            ++i;
        } else {
            result[mergedIndex] = nums2[j];
            ++j;
        }
    }
    for(;i < len1; mergedIndex++,i++) {
        result[mergedIndex] = nums1[i];       
    }
    for(;j < len2; mergedIndex++,j++) {
        result[mergedIndex] = nums2[j];       
    }
    
    for(mergedIndex = 0; mergedIndex < (len1 + len2); mergedIndex++) {
        nums1[mergedIndex] = result[mergedIndex];       
    }
    
    free(result);
    result = NULL;
}

void mergeSort(int *nums, int len) {
    if (nums == NULL) {
        return;
    }
    if (len <= 1) {
        return;
    }
    
    int middle = len / 2;
    int len1 = middle;
    int len2 = len - middle;
    int *nums1 = nums;
    int *nums2 = nums + middle;
    mergeSort(nums1, len1);
    mergeSort(nums2, len2);
    mergeTwoNums(nums1, len1, nums2, len2);
}

bool containsDuplicate(int* nums, int numsSize){
    if (nums == NULL) {
        return false;
    }
    if (numsSize <= 1) {
        return false;
    }
    
    mergeSort(nums,numsSize);
     
    int duplicate = nums[0];
    for(int i = 1; i < numsSize; ++i) {
        if (nums[i] == duplicate) {
            return true;
        }
        duplicate = nums[i];
    }
    return false;
}


```
