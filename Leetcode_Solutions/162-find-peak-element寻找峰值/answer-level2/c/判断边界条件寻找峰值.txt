# 判断边界条件寻找峰值
```

int findPeakElement(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) {
        return NULL;
    }
    if (numsSize == 1) {
        return 0;
    }
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }else if (i == numsSize - 1) {
            if (nums[i] > nums[i - 1]) {
                return i;
            }
        }else if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return NULL;
}
```
