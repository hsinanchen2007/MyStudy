```
void dfs(int *nums, int step, int jums, int numsSize, int *mim)
{
    if (step >= numsSize) {
        if (jums < *mim) {
            *mim = jums;
        }
        return;
    }

    int cnt = nums[step];
    if (cnt == 0) {
        return;
    }

    for (int i = cnt; i > 0; i--) {
        dfs(nums, step + i, jums + 1, numsSize, mim);
    }

    return;
}

int jump(int* nums, int numsSize){
    if (numsSize <= 1) {
        return 0;
    }
    int min = 0x0FFFFFFF;
    dfs(nums, 0, 0, numsSize - 1, &min);
    return min;
}
```
