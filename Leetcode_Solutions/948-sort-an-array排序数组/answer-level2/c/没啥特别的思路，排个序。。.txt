
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int *nums, int numsSize, int begin, int end) {
    if (begin >= end) return;

    int pivot = end;
    int i = begin;
    int j = end - 1;
    while (i < j) {
        while (nums[i] <= nums[pivot] && i < j) i++;
        while (nums[j] > nums[pivot] && j > i) j--;
        if (i != j) {
            swap(nums + i, nums + j);
        }
    }

    if (nums[i] > nums[pivot]) {
        swap(nums + i, nums + pivot);
        pivot = i;
    }
    
    quicksort(nums, numsSize, begin, pivot-1);
    quicksort(nums, numsSize, pivot+1, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    if (!nums || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    (void)memcpy(ans, nums, sizeof(int) * numsSize);
    quicksort(ans, numsSize, 0, numsSize-1);
    *returnSize = numsSize;
    return ans;    
}
```