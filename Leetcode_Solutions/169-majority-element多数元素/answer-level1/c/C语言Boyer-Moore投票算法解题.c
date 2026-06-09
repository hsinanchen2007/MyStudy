具体详解请看官方思路。
```c
int majorityElement(int* nums, int numsSize){
    int candidate;
    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += nums[i] == candidate ? 1 : -1;
    }
    return candidate;
}
```
