```
bool find132pattern(int* nums, int numsSize){
    int min, i, j;

    if (nums == NULL || numsSize < 3) {
        return false;
    }

    min = nums[0];
    for (i = 1; i < numsSize - 1; i++) {
        if (nums[i] < min) {
            min = nums[i];
            continue;
        } else {
            for (j = i + 1; j < numsSize; j++) {
                if (nums[j] < nums[i] && nums[j] > min) {
                    return true;
                }
            }
        }
    }
    return false;
}
```
