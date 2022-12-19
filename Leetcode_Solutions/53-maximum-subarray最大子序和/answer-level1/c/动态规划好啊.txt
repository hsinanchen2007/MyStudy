### 解题思路
使用动态规划，后面一个状态依赖前一个状态

### 代码

```c

/* 使用动态规划，当前节点最大的值：max{preValue+curValue, curValue} */
int maxSubArray(int* nums, int numsSize){
    int i = 0;
    int sum = nums[0];
    
    for (i = 1; i < numsSize; i++) {
        if ((nums[i -1] + nums[i]) > nums[i] ) {
            nums[i] = nums[i -1] + nums[i];
        }
    }

    for (i = 1; i < numsSize; i++) {
        if (nums[i] > sum) {
            sum = nums[i];
        }
    }

    return sum;
}
```