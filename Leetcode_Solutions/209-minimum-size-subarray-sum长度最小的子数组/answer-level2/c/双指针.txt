# 双指针
```
int minSubArrayLen(int s, int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) {
        return 0;
    }
    int min = numsSize + 1;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        while (sum >= s && left <= i) {
            min = min < (i - left + 1 ) ? min : (i - left + 1 );
            sum -= nums[left++];
        }
    }
    return min == numsSize + 1 ? 0 : min;
}
```
