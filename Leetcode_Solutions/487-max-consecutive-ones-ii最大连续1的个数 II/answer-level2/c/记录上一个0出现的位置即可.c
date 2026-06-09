```
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int num = 0;
    int max = 0;
    int lastZero = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            num++;
        } else {
            if (max < num) {
                max = num;
            }
            num = i - lastZero;
            lastZero = i;
        }
    }
    if (max < num) {
        max = num;
    }
    return max;
}
```
