```
int jump(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1) {
        return 0;
    }

    int *a = (int *)malloc(numsSize * sizeof(int));
    memset(a, 0, numsSize * sizeof(int));
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j <= i + nums[i]; j++) {
            if (j >= numsSize - 1) {
                return (a[i] + 1);
            }
            if (a[j] != 0) { //已被标记
                continue;
            }
            a[j] = a[i] + 1;
        }

    }

    return a[numsSize-1];
}
```
