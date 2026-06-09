### 解题思路
前缀和题目的关键思路：
left == sum - leftSum - nums[i]

### 代码

```c
int pivotIndex(int* nums, int numsSize){
    if(nums == 0 || numsSize == 0) {
        return -1;
    }

    int leftSum = 0;
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    for(int i = 0; i < numsSize; i++) {
        if (leftSum == sum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}
```