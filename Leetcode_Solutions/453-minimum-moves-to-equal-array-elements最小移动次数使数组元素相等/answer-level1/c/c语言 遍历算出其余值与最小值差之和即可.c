### 解题思路
n - 1个数加1即1个数减1，因此只需算sum(nums) - numsSize * min

### 代码

```c
int minMoves(int* nums, int numsSize){
    int ret = 0;
    int min = nums[0];
    for(int i = 0;i < numsSize;i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    for(int i = 0;i < numsSize;i++){
        ret = ret + nums[i] - min;
    }
    return ret;
}
```