```c
int maxProduct (int* nums, int numsSize) {
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        int thisMax = 1;
        for (int j = i; j < numsSize; j++) {
            thisMax *= nums[j];
            if (thisMax > max) {
                max = thisMax;
            }
        }
    }
    return max;
}
```
