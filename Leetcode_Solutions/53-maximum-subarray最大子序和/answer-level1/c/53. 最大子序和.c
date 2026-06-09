### 解题思路
此处撰写解题思路

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int maxSum, sum = 0;
    int i;


    maxSum = nums[0];
    for (i = 0; i < numsSize; ++i) {
        sum += nums[i];
        if (sum > maxSum)
            maxSum = sum;

        if (sum <= 0)
            sum = 0;
    }

    return maxSum;
}
```