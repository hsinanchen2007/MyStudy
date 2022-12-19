C语言实现
```C []
int thirdMax(int* nums, int numsSize){   
    int queue[3] = {(int)0x80000000, (int)0x80000000, (int)0x80000000};
    int min_val = 0x7fffffff;
    for (int i = 0; i < numsSize; ++i)
    {
        min_val = fmin(min_val, nums[i]);
        if (nums[i] > queue[0]) {
            queue[2] = queue[1], queue[1] = queue[0], queue[0] = nums[i]; continue;
        }
        if (nums[i] > queue[1] && nums[i] < queue[0]) {
            queue[2] = queue[1], queue[1] = nums[i]; continue;
        }
        if (nums[i] > queue[2] && nums[i] < queue[1]) queue[2] = nums[i];               
    }
    return queue[2] >= min_val ? (queue[1] > queue[2] ? queue[2] : queue[0]) : queue[0];
}

```
