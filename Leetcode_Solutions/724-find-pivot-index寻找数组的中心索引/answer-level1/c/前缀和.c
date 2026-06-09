### 解题思路
此处撰写解题思路

### 代码

```c
int pivotIndex(int* nums, int numsSize){
    
    if(numsSize == 0) {
        return -1;
    }
    int sum[numsSize];
    memset(sum, 0, sizeof(sum));
    sum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum[i] += sum[i - 1] + nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (sum[i] - nums[i] == sum[numsSize - 1] - sum[i]) {
            return i;
        }
    }
    return -1;
}
```