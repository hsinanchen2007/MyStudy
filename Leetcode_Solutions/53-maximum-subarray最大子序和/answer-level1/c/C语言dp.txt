### 解题思路
此处撰写解题思路

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return -1;
    }

    int max = nums[0];
    int i;
    for (i = 1; i < numsSize; i++) {
        if (nums[i - 1] > 0) {
            nums[i] += nums[i - 1];
        }
        max = nums[i] > max ? nums[i] : max;
    }

    return max;
}
```