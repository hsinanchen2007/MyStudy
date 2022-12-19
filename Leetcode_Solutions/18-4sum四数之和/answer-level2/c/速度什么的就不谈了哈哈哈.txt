```
int comp(const void *a,const void *b) {
    return * (int*)a - * (int*)b;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * 1000);
    *returnSize = 0;
    if (numsSize < 4) {
        *res = NULL;
        return res;
    }
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0;i < numsSize - 3;i++) {
        for (int j = i + 1;j < numsSize - 2;j++) {
            int k = j + 1;
            int l = numsSize - 1;
            int tmp = target - nums[i] - nums[j];
            while (k < l) {
                if (tmp > nums[k] + nums[l]) {
                    k++;
                } else if (tmp < nums[k] + nums[l]) {
                    l--;
                } else {
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[k];
                    res[*returnSize][3] = nums[l];
                    (*returnSize)++;
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
            }
            
            while (j < numsSize - 3 && nums[j] == nums[j + 1]) j++;
        }
        while (i < numsSize - 4 && nums[i] == nums[i + 1]) i++;
    }
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0;i < (*returnSize);i++) {
        returnColumnSizes[0][i] = 4;
    }
    return res;                          
}


```
