```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void MergeArray(int* nums, int left, int middle, int right, int *tmp)
{
    int left1Index = left;
    int left2Index = middle + 1;
    int tmpIndex = left;

    if ((left1Index > middle) || (left2Index > right)) {
        return;
    }

    while ((left1Index <= middle) && (left2Index <= right)) {
        if (nums[left1Index] < nums[left2Index]) {
            tmp[tmpIndex] = nums[left1Index];
            left1Index++;
        } else {
            tmp[tmpIndex] = nums[left2Index];
            left2Index++;
        }
        tmpIndex++;
    }
    while (left1Index <= middle) {
        tmp[tmpIndex] = nums[left1Index];
        left1Index++;
        tmpIndex++;
    }
    while (left2Index <= right) {
        tmp[tmpIndex] = nums[left2Index];
        left2Index++;
        tmpIndex++;
    }

    int i;
    for (i = left; i <= right; i++) {
        nums[i] = tmp[i];
    }
}

//归并排序
void MergeSort(int* nums, int left, int right, int *tmp)
{
    int middle;
    if (left >= right) {
        return;
    }
    middle = left + (right - left) / 2;
    //printf("left: %d, middle: %d\n", left, middle);
    MergeSort(nums, left, middle, tmp);
    //printf("middle + 1: %d, right: %d\n", middle + 1, right);
    MergeSort(nums, middle + 1, right, tmp);
    MergeArray(nums, left, middle, right, tmp);
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }
    int *tmp = (int *)malloc(numsSize * sizeof(int));
    memset(tmp, 0, numsSize * sizeof(int));

    MergeSort(nums, 0, numsSize - 1, tmp);

    *returnSize = numsSize;
    free(tmp);
    return nums;
}
```
