### 代码

```c

int cmp(const void *a, const void *b)
{
    return *(int *)a > *(int *)b;
}

bool check(int nums[], int groups[], int row, int k, int target)
{
    if (row < 0) return true;
    int sel = nums[row--];
    for (int i = 0; i < k; i++) {
        if (sel + groups[i] <= target) {
            groups[i] += sel;
            if (check(nums, groups, row, k, target)) return true;
            groups[i] -= sel;
        }
        if (groups[i] == 0) break;
    }
    return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k){
    //特判
    int sum = 0, row = numsSize - 1, average = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    if (sum % k) return false;
    average = sum / k;
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[numsSize - 1] > average) return false;
    while (row >= 0 && nums[row] == average) {
        row--;
        k--;
    }
    //建立k个桶
    int *groups = (int *) malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) groups[i] = 0;
    bool res = check(nums, groups, row, k, average);
    free(groups);
    return res;
}
```