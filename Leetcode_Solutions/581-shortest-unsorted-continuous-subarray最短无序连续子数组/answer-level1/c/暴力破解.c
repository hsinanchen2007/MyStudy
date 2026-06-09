1.对数组进行排序。
2.比较排序后的数组和原始数组。
3.祛除两端相同的项。
4.剩余的需要进行排序。
注意：如果已经是排好序的，需要单独处理。

题解如下：
int cmp(const void *a, const void *b) {
    return *(int*)a > *(int *)b;
}

int findUnsortedSubarray(int* nums, int numsSize){
    int i, j;
    int *org_nums;
    int cnt = 0;
    if (numsSize < 2) {
        return 0;
    }
    org_nums = (int *)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        org_nums[i] = nums[i];
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != org_nums[i]) {
            break;
        }
    }
    for (j = numsSize - 1; j >= 0; j--) {
        if (nums[j] != org_nums[j]) {
            break;
        }
    }
    if (i == numsSize) {
        cnt = 0;
    } else {
        cnt = j - i + 1;
    }
    free(org_nums);
    org_nums = NULL;
    return cnt;
}