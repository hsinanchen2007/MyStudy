```
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(target * sizeof(int*));
    *returnColumnSizes = (int*)malloc(target * sizeof(int));
    *returnSize = 0;

     if (target == 1 || target == 2) {
        return res;
    }

    int l = 1;
    int r = 2;
    while (l < r) {
        int sum = (r - l + 1) * (l + r) / 2;
        if (sum < target) r++;
        else if (sum > target) l++;
        else {
            int* nums = (int*)malloc((r - l + 1) * sizeof(int));
            for (int i = 0; i <= r - l; i++) {
                nums[i] = i + l;
            }
            res[*returnSize] = nums;
            (*returnColumnSizes)[*returnSize] = r - l + 1;
            (*returnSize)++;
            l++;
        }
    }
    return res;
}
```
