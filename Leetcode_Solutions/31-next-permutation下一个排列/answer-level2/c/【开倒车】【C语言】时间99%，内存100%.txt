科目one-字符串专项, 提供C语言解法
```
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void nextPermutation(int* nums, int numsSize){
    int *left = nums + numsSize - 1;
    int *right = nums + numsSize - 1;
    int tmp;
    if (nums == NULL || numsSize == 1) {
        return nums;
    }

    while ((left - 1) >= nums) {
        if (*(left - 1) < *left) {
            break;
        }
        left--;
    }
    left = left - 1;
    if (left < nums) {
        // 逆序 qsort
        qsort(nums, numsSize, sizeof(int), cmp);
        return;
    }
    while (right > left) {
        if (*right > *left) {
            break;
        }
        right--;
    }
    tmp = *left;
    *left = *right;
    *right = tmp;

    if ((nums + numsSize - (left + 1)) > 1) {
        qsort(left + 1, nums + numsSize - (left + 1), sizeof(int), cmp);
    }
}
```
