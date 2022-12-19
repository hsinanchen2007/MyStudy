```
int maxSubArray(int* nums, int numsSize){
    if (numsSize == 1) {
        return nums[0];
    }
    int sum = 0;
    int max = nums[0];
    //int j = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum < 0) {
            sum = 0;
            if (max < nums[i]) {
                max = nums[i];
            }
        } else {
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}
```
