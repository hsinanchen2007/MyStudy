```
int jump(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 1) {
        return 0;
    }
    int max = 0;
    int end = 0;
    int step = 0;
    for (int i = 0; i < numsSize - 1 && i <= max; i++) {
        if (max < nums[i] + i) {
            max = nums[i] + i;
        }
        if (max >= (numsSize - 1)) {
            break;
        }
        if (i == end) {
            step++;
            end = max;
        }
    }
    if (max >= (numsSize - 1)) {
        return step + 1;
    }
    return -1;
}
```
