```
bool increasingTriplet(int* nums, int numsSize){
    if (numsSize < 3) {
        return false;
    }
    int i;
    int numsMax[numsSize];
    int numsMin[numsSize];
    int max = INT_MIN;
    int min = INT_MAX;
    for (i = numsSize - 1; i >= 0; i--) {
        if (nums[i] > max) {
            numsMax[i] = nums[i];
            max = nums[i];
        } else {
            numsMax[i] = max;
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < min) {
            numsMin[i] = nums[i];
            min = nums[i];
        } else {
            numsMin[i] = min;
        }
    }
    for (i = 1; i < numsSize - 1; i++) {
        if (nums[i] > numsMin[i - 1] && nums[i] < numsMax[i + 1]) {
            return true;
        }
    }
    return false;
}
```
